#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mem.h"
// #include <nvboard.h>
#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"

static void single_cycle()
{
    contextp->timeInc(1);
    top.clk = 0;
    top.eval();
    tfp->dump(contextp->time());
    contextp->timeInc(1);
    top.clk = 1;
    top.eval();
    tfp->dump(contextp->time());
}

static void reset(int n)
{
    top.rst = 1;
    while (n-- > 0)
        single_cycle();
    top.rst = 0;
}

int clk = 1;

int main(int argc, char **argv)
{
    Verilated::mkdir("logs");
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
    contextp->debug(0);
    contextp->traceEverOn(true);
    contextp->commandArgs(argc, argv);

    const std::unique_ptr<Vtop> top{new Vtop{contextp.get(), "TOP"}};
    VerilatedFstC *tfp = new VerilatedFstC;
    top->trace(tfp, 5);
    tfp->open("logs/sim_wave.fst");

    reset(10);

    while (1)
    {
        contextp->timeInc(1);
        top->clk = clk;
        top->inst = mem_read(top->pc);
        top->eval();
        tfp->dump(contextp->time());
        clk = !clk;
    }
    tfp->close();
    top->final();

    return 0;
}
