#include "common.h"
#include "utils.h"
#include "npc.h"

int npc_init_num = 2;
int inited = 0;

static void single_cycle(Vtop* top, VerilatedContext* contextp, VerilatedVcdC* tfp)
{
    if(!inited)
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
}

void npc_exec(Vtop* top, VerilatedContext* contextp, VerilatedVcdC* tfp, uint64_t n)
{
    if(contextp->gotFinish())
    {
        printf("EBREAK, input q to quit\n");
        return;
    }
    for(; n > 0; n --)
    {
        if(inited){
            single_cycle(top, contextp, tfp);
        }
        else
        {
            for(; npc_init_num > 0; npc_init_num--)
            {
                single_cycle(top, contextp, tfp);
            }
            inited = 1;
        }
        if(contextp->gotFinish()) break;
    }
}
