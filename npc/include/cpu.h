#ifndef CPU_H__
#define CPU_H__

#include "common.h"

extern unsigned long long running_cycle;
extern unsigned long long inst_num;

typedef struct
{
  uint32_t mepc;
  uint32_t mcause;
  uint32_t mtvec;
  uint32_t mstatus;
  uint32_t mvendorid;
  uint32_t marchid;
} rv32_crs;


typedef struct {
  int gpr[16];
  uint32_t pc;
  uint32_t npc;
  rv32_crs csr;
} CPU_state;

extern CPU_state cpu;

void cpu_single_cycle(VysyxSoCFull *top, VerilatedContext *contextp, VerilatedVcdC *tfp);
void cpu_reset(int n, VysyxSoCFull *top,VerilatedContext *contextp, VerilatedVcdC *tfp);

#endif
