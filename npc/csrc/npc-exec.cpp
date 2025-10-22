#include "common.h"
#include "utils.h"
#include "npc.h"
#include "memory/paddr.h"
#include "difftest-def.h"
#include "disasm.h"
#include "ftrace.h"
#include "Vtop__Dpi.h"
#include "cpu.h"

#define BITMASK(bits) ((1ull << (bits)) - 1)
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1)) // similar to x[hi:lo] in verilog
#define SEXT(x, len) ({ struct { int64_t n : len; } __x = { .n = (int64_t)(x) }; (uint64_t)__x.n; })

#define MAX_INST_TO_PRINT 10
#define inst_jar 0x6f
#define inst_jarl 0x67

uint64_t g_nr_guest_inst = 0;
bool g_print_step = false;
CPU_state cpu = {};

static void trace(char *logbuf)
{
#ifdef CONFIG_ITRACE_COND
    if (ITRACE_COND)
    {
        log_write("%s\n", logbuf);
    }
#endif
    if (g_print_step)
    {
#ifdef CONFIG_ITRACE
        puts(logbuf);
#endif
    }
}

static void single_cycle(Vtop *top, VerilatedContext *contextp, VerilatedVcdC *tfp)
{
    char logbuf[128];

    if(!npc_state.inited)
    {
        contextp->timeInc(1);
        top->clk = 1;
        top->eval();
        tfp->dump(contextp->time());
        npc_state.inited = true;
    }

    // contextp->timeInc(1);
    // top->rst = 0;
    // top->clk = 0;
    // top->eval();
    cpu_single_cycle(top);
    tfp->dump(contextp->time());
    npc_state.halt_pc = top->pc;
    npc_state.halt_ret = top->ReadData_a0;
    cpu.pc = top->npc;
    contextp->timeInc(1);
    // top->clk = 1;
    // top->eval();
    // tfp->dump(contextp->time());

    svSetScope(svGetScopeFromName("TOP.top.u_GPR.u_RegisterFile"));
    get_gpr(cpu.gpr);
    svSetScope(svGetScopeFromName("TOP.top.u_CSR"));
    get_csr((int *)(&cpu.csr));

    if (npc_state.halt_pc >= 0x80000000)
    {
        // 反汇编 itrace
        char *p = logbuf;
        p += snprintf(p, sizeof(logbuf), "0x%08x:", npc_state.halt_pc);
        int ilen = 4;
        int i;
        uint32_t inst_val = paddr_read(npc_state.halt_pc);
        uint8_t *inst = (uint8_t *)&inst_val;
#ifdef CONFIG_ITRACE
        for (i = ilen - 1; i >= 0; i--)
        {
            p += snprintf(p, 4, " %02x", inst[i]);
        }
        int ilen_max = 4;
        int space_len = ilen_max - ilen;
        if (space_len < 0)
            space_len = 0;
        space_len = space_len * 3 + 1;
        memset(p, ' ', space_len);
        p += space_len;

        disassemble(p, logbuf + sizeof(logbuf) - p, npc_state.halt_pc, inst, ilen);
        trace(logbuf);
#endif

        // 函数调用 ftrace
        uint8_t opcode = BITS(inst_val, 6, 0);
        int rd = BITS(inst_val, 11, 7);
        int rs1 = BITS(inst_val, 19, 15);
        uint32_t dnpc = 0x0;
        if (opcode == inst_jar)
        {
            uint32_t imm = (SEXT((BITS(inst_val, 31, 31) << 20) | (BITS(inst_val, 19, 12) << 12) | (BITS(inst_val, 20, 20) << 11) | (BITS(inst_val, 30, 21) << 1), 21));
            dnpc = npc_state.halt_pc + imm;
#ifdef CONFIG_FTRACE
            if (rd == 1)
            {
                ftrace_call(npc_state.halt_pc, dnpc);
            }
#endif
        }
        else if (opcode == inst_jarl)
        {
            uint32_t imm = SEXT(BITS(i, 31, 20), 12);
            uint32_t src1 = cpu.gpr[rs1];
            dnpc = src1 + imm;
#ifdef CONFIG_FTRACE
            if (inst_val == 0x00008067)
            {
                ftrace_ret(npc_state.halt_pc);
            }
            else if ((rd == 1) || (imm == 0 && rd == 0))
            {
                ftrace_call(npc_state.halt_pc, dnpc);
            }
#endif
        }
#ifdef CONFIG_DIFFTEST
        difftest_step(npc_state.halt_pc);
#endif
    }
}

static void execute(Vtop *top, VerilatedContext *contextp, VerilatedVcdC *tfp, uint64_t n)
{
    for (; n > 0; n--)
    {
        single_cycle(top, contextp, tfp);
        g_nr_guest_inst++;
        if ((contextp->gotFinish()) || (npc_state.state == NPC_ABORT))
            break;
    }
}

void assert_fail_msg()
{
}

void npc_exec(Vtop *top, VerilatedContext *contextp, VerilatedVcdC *tfp, uint64_t n)
{
    g_print_step = (n < MAX_INST_TO_PRINT);
    if ((contextp->gotFinish()) || (npc_state.state == NPC_ABORT))
    {
        printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
        return;
    }
    execute(top, contextp, tfp, n);
}
