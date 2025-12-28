#include "common.h"
#include "cpu.h"

int running_cycle = 0;

void cpu_single_cycle(VysyxSoCFull *top, VerilatedContext *contextp, VerilatedVcdC *tfp)
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

void cpu_reset(int n, VysyxSoCFull *top, VerilatedContext *contextp, VerilatedVcdC *tfp)
{
    top->reset = 1;
    while (n-- > 0)
    {
        cpu_single_cycle(top, contextp, tfp);
    }
    top->reset = 0;
    // npc_state.inited = true;
}
