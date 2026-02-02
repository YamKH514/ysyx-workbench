#include "common.h"
#include "utils.h"
#include "npc-init.h"
#include "npc.h"
#include "sdb.h"
#include "cpu.h"
#include "perf-cnt.h"
#ifdef CONFIG_NVBOARD
#include <nvboard.h>
#endif
#include "Vtop__Dpi.h"

int is_exit_status_bad();
void nvboard_bind_all_pins(VysyxSoCFull* top);

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

#ifdef CONFIG_NVBOARD
    nvboard_bind_all_pins(top);
    nvboard_init();
#endif

    init_npc(argc, argv, top, contextp, tfp); 

    while (!contextp->gotFinish())
    {
        sdb_mainloop();
    }

    Log("npc running cycle = %llu", running_cycle);
    Log("npc number of instructions executed = %llu", inst_num);
    Log("npc IPC = %f", (double)inst_num/(double)running_cycle);
    Log("IFU called %llu, EXU called %llu, LSU called %llu",
        PERF_MODULE(IFU), PERF_MODULE(EXU), PERF_MODULE(LSU));
    Log("type_i = %d, type_s = %d, type_b = %d, type_u = %d, type_j = %d, type_r = %d",
        PERF_INST(i), PERF_INST(s), PERF_INST(b), PERF_INST(u), PERF_INST(j), PERF_INST(r));
    Log("npc: %s at pc = 0x%08x", (
        npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
        npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) : ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED)), npc_state.halt_pc);

    tfp->close();
    top->final();

#ifdef CONFIG_NVBOARD
    nvboard_quit();
#endif

    return is_exit_status_bad();
}
