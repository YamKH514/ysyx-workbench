#include "common.h"
#include "utils.h"
#include "npc.h"
#include "mem.h"
#include "disasm.h"

int g_nr_guest_inst = 0;
int npc_init_num = 2;
int inited = 0;

static void single_cycle(Vtop *top, VerilatedContext *contextp, VerilatedVcdC *tfp)
{
    char logbuf[128];

    if (!inited)
    {
        top->rst = 1;
    }
    else
    {
        top->rst = 0;
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
        // printf("disassemble: %s\n", logbuf);
    }
}

void assert_fail_msg()
{
}

void npc_exec(Vtop *top, VerilatedContext *contextp, VerilatedVcdC *tfp, uint64_t n)
{
    if (contextp->gotFinish())
    {
        printf("EBREAK, input q to quit\n");
        return;
    }
    for (; n > 0; n--)
    {
        if (inited)
        {
            single_cycle(top, contextp, tfp);
        }
        else
        {
            for (; npc_init_num > 0; npc_init_num--)
            {
                single_cycle(top, contextp, tfp);
            }
            inited = 1;
        }
        g_nr_guest_inst++;
        if (contextp->gotFinish())
            break;
    }
}
