#include "utils.h"
// #include <nvboard.h>
#include "Vtop.h"
#include "Vtop__Dpi.h"
#include "verilated.h"
#include "verilated_fst_c.h"

void init_npcmem(int argc, char *argv[]);
uint32_t mem_read(uint32_t pc);
void mem_end();

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
int cnt = 0;
int npc_state = NPC_STOP;

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
        cnt ++;
        if(cnt > 50) break;
    }

    if(npc_state == NPC_END)
    {
        printf("\033[1;32;40mHIT GOOD TRAP\033[0m\n");
    }
    else
    {
        printf("\033[1;31;40mHIT BAD TRAP\033[0m at pc = 0x%8x\n", top->pc);
    }

    tfp->close();
    top->final();
    mem_end();

    return 0;
}
