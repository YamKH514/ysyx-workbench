#include "common.h"
#include "cpu.h"

void cpu_single_cycle(Vtop* top)
{
    top->clk = 0;
    top->eval();
    top->clk = 0;
    top->eval();
}

void cpu_reset(int n, Vtop* top)
{
    top->rst = 1;
    while (n-- > 0)
    {
        cpu_single_cycle(top);
    }
    top->rst = 0;
}
