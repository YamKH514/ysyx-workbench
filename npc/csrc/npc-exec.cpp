#include "common.h"
#include "utils.h"
#include "npc.h"
#include "memory/paddr.h"
#include "difftest-def.h"
#include "disasm.h"
#include "ftrace.h"
#include "cpu.h"
#include "watchpoint.h"
#include "perf-cnt.hpp"
#ifdef CONFIG_NVBOARD
#include <nvboard.h>
#endif

#define BITMASK(bits) ((1ull << (bits)) - 1)
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1)) // similar to x[hi:lo] in verilog
#define SEXT(x, len) ({ struct { int64_t n : len; } __x = { .n = (int64_t)(x) }; (uint64_t)__x.n; })

#define MAX_INST_TO_PRINT 10
#define inst_jar 0x6f
#define inst_jarl 0x67

uint64_t g_nr_guest_inst = 0;
bool g_print_step = false;
CPU_state cpu = {};
static uint32_t pc = 0;
static bool inst_end = false;
static INST_TYPE_ENUM inst_type;
static int current_inst_cyc = 0;

static void trace_and_difftest(VTOP *top, char *logbuf)
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

static void exec_once(VTOP *top, VerilatedContext *contextp, VerilatedVcdC *tfp)
{
    char logbuf[128];

    if (!npc_state.inited) cpu_reset(10, top, contextp, tfp);

    cpu_single_cycle(top, contextp, tfp);

    // Perf CNT
    if (!CPU_RESET) {
        current_inst_cyc ++;
        FIND_DPIC(u_WBU); if (wbu_commit()) inst_num ++; // wbu每提交一次commit，表明完整执行一次指令
        FIND_DPIC(u_IFU); if (ifu_commit()) perf_cnt.module_add(IFU); // IFU每锁存一次pc值，认为IFU调用一次
        FIND_DPIC(u_EXU); if (exu_commit()) perf_cnt.module_add(EXU);
        FIND_DPIC(u_LSU); if (lsu_commit()) perf_cnt.module_add(LSU);
        if (S_CPU(id_idex_valid) & S_CPU(id_idex_ready)) inst_type = (INST_TYPE_ENUM)S_CPU(idu_imm_type);
        // Recoding IFU wait Inst
        if ((int)S_IFU(state) == 1) perf_cnt.ifu_wait_rd();
        else if ((int)S_IFU(state) == 0) perf_cnt.ifu_wait_pc();
        // Recoding LSU wait memory read
        FIND_DPIC(u_LSU);
        if (lsu_r_call()) perf_cnt.lsu_wait_num('r');
        if ((int)S_LSU(state) == 2 | (int)S_LSU(state) == 3) perf_cnt.lsu_wait_cyc('r');
        // Recoding LSU wait memory write
        if (lsu_w_call()) perf_cnt.lsu_wait_num('w');
        if ((int)S_LSU(state) == 4 | (int)S_LSU(state) == 6) perf_cnt.lsu_wait_cyc('w');
    }

    FIND_DPIC(u_WBU);
    if (wbu_commit())
    {
        pc = S_WBU(pc_r);
        cpu.pc = S_PCCnt(target_pc_r);
        cpu.npc = S_PCCnt(target_pc_r);
        inst_end = true;
    }
    else if (inst_end) // 写回后一周期，寄存器才能更新为正确的值
    {
        perf_cnt.inst_add(inst_type, current_inst_cyc);
        current_inst_cyc = 0;

        inst_end = false;
        FIND_DPIC(u_GPR);
        get_gpr(cpu.gpr);
        FIND_DPIC(u_CSR);
        get_csr((int *)(&cpu.csr));
#ifdef CONFIG_WATCHPOINT
        bool changed = wp_scan();
        if (changed)
        {
            npc_state.state = NPC_STOP;
        }
#endif
#ifdef CONFIG_DIFFTEST
        difftest_step(pc);
#endif
    }

    if (in_pmem(pc))
    {
        // 反汇编 itrace
        char *p = logbuf;
        p += snprintf(p, sizeof(logbuf), "0x%08x:", pc);
        int ilen = 4;
        int i;
        uint32_t inst_val = paddr_read(pc);
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

        disassemble(p, logbuf + sizeof(logbuf) - p, pc, inst, ilen);
#endif
        trace_and_difftest(top, logbuf);

        // 函数调用 ftrace
        uint8_t opcode = BITS(inst_val, 6, 0);
        int rd = BITS(inst_val, 11, 7);
        int rs1 = BITS(inst_val, 19, 15);
        uint32_t dnpc = 0x0;
        if (opcode == inst_jar)
        {
            uint32_t imm = (SEXT((BITS(inst_val, 31, 31) << 20) | (BITS(inst_val, 19, 12) << 12) | (BITS(inst_val, 20, 20) << 11) | (BITS(inst_val, 30, 21) << 1), 21));
            dnpc = pc + imm;
#ifdef CONFIG_FTRACE
            if (rd == 1)
            {
                ftrace_call(pc, dnpc);
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
                ftrace_ret(pc);
            }
            else if ((rd == 1) || (imm == 0 && rd == 0))
            {
                ftrace_call(pc, dnpc);
            }
#endif
        }
    }
}

static void execute(VTOP *top, VerilatedContext *contextp, VerilatedVcdC *tfp, uint64_t n)
{
    for (; n > 0; n--)
    {
#ifdef CONFIG_NVBOARD
        nvboard_update();
#endif
        exec_once(top, contextp, tfp);
        running_cycle ++;
        g_nr_guest_inst++;
        if (npc_state.state != NPC_RUNNING)
        {
            npc_state.halt_pc = cpu.pc;
            npc_state.halt_ret = cpu.gpr[10];
            break;
        }
    }
}

void assert_fail_msg()
{
}

void npc_exec(VTOP *top, VerilatedContext *contextp, VerilatedVcdC *tfp, uint64_t n)
{
    g_print_step = (n < MAX_INST_TO_PRINT);
    switch (npc_state.state) {
    case NPC_END: case NPC_ABORT: case NPC_QUIT:
        Verilated::gotFinish(true);
        printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
        return;
    default: npc_state.state = NPC_RUNNING;
    }

    execute(top, contextp, tfp, n);

    if (npc_state.state == NPC_RUNNING) npc_state.state = NPC_STOP;
}
