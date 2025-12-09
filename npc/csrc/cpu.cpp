#include "common.h"
#include "cpu.h"

int running_cycle = 0;

void cpu_single_cycle(Vtop* top)
{
    top->clk = 0;
    top->eval();
    top->clk = 1;
    top->eval();
}

void cpu_reset(int n, Vtop* top)
{
    top->rstn = 0;
    while (n-- > 0)
    {
        cpu_single_cycle(top);
    }
}
