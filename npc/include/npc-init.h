#ifndef NPC_INIT_H__
#define NPC_INIT_H__

#include "common.h"

#include "Vtop.h"
#include "Vtop__Dpi.h"
#include "verilated_vcd_c.h"

void init_npc(int argc, char *argv[], Vtop* top, VerilatedContext* contextp, VerilatedVcdC* tfp);

#endif
