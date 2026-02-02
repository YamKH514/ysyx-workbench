#include "common.h"
#include "utils.h"
#include "npc-init.h"
#include "npc.h"
#include "sdb.h"
#include "cpu.h"
#include "perf-cnt.hpp"
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
    perf_cnt.print_module_called(IFU);
    perf_cnt.print_module_called(EXU);
    perf_cnt.print_module_called(LSU);
    perf_cnt.print_inst_info();
    // Log("type_i = %f, type_s = %f, type_b = %f, type_u = %f, type_j = %f, type_r = %f",
    //     perf_cnt.inst_proportion(i), perf_cnt.inst_proportion(s), perf_cnt.inst_proportion(b), perf_cnt.inst_proportion(u), perf_cnt.inst_proportion(j), perf_cnt.inst_proportion(r));
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
