#ifndef SDB_H__
#define SDB_H__

#include "common.h"
#include "Vtop.h"
#include "verilated_vcd_c.h"

void init_sdb(Vtop *top_in, VerilatedContext *contextp_in, VerilatedVcdC *tfp_in);
void sdb_mainloop();

#endif
