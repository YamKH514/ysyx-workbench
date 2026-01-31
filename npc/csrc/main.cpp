#include "common.h"
#include "utils.h"
#include "npc-init.h"
#include "npc.h"
#include "sdb.h"
#include "cpu.h"
#include <nvboard.h>
#include "Vtop__Dpi.h"

static TOP_NAME VysyxSoCFull;
void nvboard_bind_all_pins(TOP_NAME* top);

int is_exit_status_bad();

int main(int argc, char *argv[])
{
    Verilated::commandArgs(argc, argv);

    Verilated::mkdir("logs");
    VerilatedContext *contextp = new VerilatedContext;
    contextp->debug(0);
    contextp->traceEverOn(true);
    contextp->commandArgs(argc, argv);

    VysyxSoCFull *top = new VysyxSoCFull{contextp, "TOP"};
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 5);
    tfp->open("logs/sim_wave.vcd");

    nvboard_bind_all_pins(&top);
    nvboard_init();

    init_npc(argc, argv, top, contextp, tfp); 

    while (!contextp->gotFinish())
    {
        nvboard_update();
        sdb_mainloop();
    }

    Log("npc running cycle = %llu", running_cycle);
    Log("npc: %s at pc = 0x%08x", (
        npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
        npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) : ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED)), npc_state.halt_pc);

    tfp->close();
    top->final();

    return is_exit_status_bad();
}
