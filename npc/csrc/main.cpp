#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mem.h"
// #include <nvboard.h>
#include "Vtop.h"
#include "Vtop__Dpi.h"
#include "verilated.h"
#include "verilated_fst_c.h"

void init_npcmem(int argc, char *argv[]);

static void single_cycle(std::unique_ptr<Vtop>& top, VerilatedContext* contextp, VerilatedFstC* tfp)
{
    contextp->timeInc(1);
    top->clk = 1;
    top->eval();
    tfp->dump(contextp->time());
    contextp->timeInc(1);
    top->clk = 0;
    top->eval();
    tfp->dump(contextp->time());
}

static void reset(std::unique_ptr<Vtop>& top, VerilatedContext* contextp, VerilatedFstC* tfp, int n)
{
    top->rst = 1;
    while (n-- > 0)
        single_cycle(top, contextp, tfp);
    top->rst = 0;
}

int clk = 1;

int main(int argc, char *argv[])
{
    init_npcmem(argc, argv);

    Verilated::mkdir("logs");
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
    contextp->debug(0);
    contextp->traceEverOn(true);
    contextp->commandArgs(argc, argv);

    std::unique_ptr<Vtop> top{new Vtop{contextp.get(), "TOP"}};
    VerilatedFstC *tfp = new VerilatedFstC;
    top->trace(tfp, 5);
    tfp->open("logs/sim_wave.fst");

    reset(top, contextp.get(), tfp, 5);

    while (!contextp->gotFinish())
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
