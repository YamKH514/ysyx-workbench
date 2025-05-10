#include "common.h"
#include "utils.h"
#include "mem.h"
#include "npc.h"
#include "sdb.h"
// #include <nvboard.h>
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include "Vtop__Dpi.h"

int main(int argc, char *argv[])
{
    init_npcmem(argc, argv);

    Verilated::mkdir("logs");
    VerilatedContext* contextp = new VerilatedContext;
    contextp->debug(0);
    contextp->traceEverOn(true);
    contextp->commandArgs(argc, argv);

    Vtop* top = new Vtop{contextp, "TOP"};
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 5);
    tfp->open("logs/sim_wave.vcd");

    init_sdb(top, contextp, tfp);

    while (!contextp->gotFinish())
    {
        sdb_mainloop();
    }
    
    if(npc_state.halt_ret == 0)
    {
        printf("\033[1;32;40mHIT GOOD TRAP\033[0m");
    }
    else
    {
        printf("\033[1;31;40mHIT BAD TRAP\033[0m");
    }
    printf(" at pc = 0x%08x\n", npc_state.halt_pc);

    tfp->close();
    top->final();
    mem_end();

    return 0;
}
