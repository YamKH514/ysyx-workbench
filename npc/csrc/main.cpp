#include "common.h"
#include "utils.h"
#include "npc-init.h"
#include "npc.h"
#include "sdb.h"
// #include <nvboard.h>
#include "Vtop__Dpi.h"

int main(int argc, char *argv[])
{

    Verilated::mkdir("logs");
    VerilatedContext *contextp = new VerilatedContext;
    contextp->debug(0);
    contextp->traceEverOn(true);
    contextp->commandArgs(argc, argv);

    Vtop *top = new Vtop{contextp, "TOP"};
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 5);
    tfp->open("logs/sim_wave.vcd");

    init_npc(argc, argv, top, contextp, tfp);

    while (!contextp->gotFinish())
    {
        sdb_mainloop();
    }

    Log("npc: %s at pc = 0x%08x", (
        npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
        npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) : ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED)), npc_state.halt_pc);

    tfp->close();
    top->final();

    return 0;
}
