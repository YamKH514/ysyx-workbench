#include "common.h"
#include "cpu.h"

unsigned long long running_cycle = 0;
unsigned long long inst_num = 0;

void cpu_single_cycle(VTOP *top, VerilatedContext *contextp, VerilatedVcdC *tfp)
{
    contextp->timeInc(1);
    top->clock = 0;
    top->eval();
#ifdef CONFIG_VCD_TRACE
    tfp->dump(contextp->time());
#endif
    contextp->timeInc(1);
    top->clock = 1;
    top->eval();
#ifdef CONFIG_VCD_TRACE
    tfp->dump(contextp->time());
#endif
}

void cpu_reset(int n, VTOP *top, VerilatedContext *contextp, VerilatedVcdC *tfp)
{
    top->reset = 1;
    while (n-- > 0)
    {
        cpu_single_cycle(top, contextp, tfp);
    }
    top->reset = 0;
    npc_state.inited = true;
}
