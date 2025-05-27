#include "common.h"
#include "utils.h"
#include "npc.h"
#include "mem.h"
#include "disasm.h"

#define MAX_INST_TO_PRINT 10

uint64_t g_nr_guest_inst = 0;
bool g_print_step = false;
int npc_init_num = 2;

static void trace(char *logbuf) {
    log_write("%s\n", logbuf);
    if(g_print_step)
    {
        puts(logbuf);
    }
}

static void single_cycle(Vtop *top, VerilatedContext *contextp, VerilatedVcdC *tfp)
{
    char logbuf[128];

    if (npc_state.inited)
    {
        top->rst = 0;
    }
    else
    {
        top->rst = 1;
    }
    npc_state.halt_pc = top->pc;
    npc_state.halt_ret = top->ReadData_a0;
    contextp->timeInc(1);
    top->clk = 1;
    top->eval();
    tfp->dump(contextp->time());
    contextp->timeInc(1);
    top->clk = 0;
    top->eval();
    tfp->dump(contextp->time());

    if (npc_state.halt_pc >= 0x80000000)
    {
        char *p = logbuf;
        p += snprintf(p, sizeof(logbuf), "0x%08x:", npc_state.halt_pc);
        int ilen = 4;
        int i;
        uint32_t inst_val = mem_read(npc_state.halt_pc);
        uint8_t inst[4];
        for (int j = 0; j < 4; j++)
        {
            inst[j] = (inst_val >> (8 * j)) & 0xff;
        }
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
    }
}

static void execute(Vtop *top, VerilatedContext *contextp, VerilatedVcdC *tfp, uint64_t n)
{
    for(; n > 0; n--)
    {
        single_cycle(top, contextp, tfp);
        if(!(npc_state.inited))
        {
            single_cycle(top, contextp, tfp);
            npc_state.inited = true;
        }
        g_nr_guest_inst ++;
        if (contextp->gotFinish())
            break;
    }
}

void assert_fail_msg()
{
}

void npc_exec(Vtop *top, VerilatedContext *contextp, VerilatedVcdC *tfp, uint64_t n)
{
    g_print_step = (n < MAX_INST_TO_PRINT);
    if (contextp->gotFinish())
    {
        printf("EBREAK, input q to quit\n");
        return;
    }
    execute(top, contextp, tfp, n);
}
