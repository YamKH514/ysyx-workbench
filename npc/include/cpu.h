#ifndef CPU_H__
#define CPU_H__

#include "common.h"

typedef struct
{
  uint32_t mepc;
  uint32_t mcause;
  uint32_t mtvec;
  uint32_t mstatus;
} rv32_crs;


typedef struct {
  int gpr[16];
  uint32_t pc;
  rv32_crs csr;
} CPU_state;

extern CPU_state cpu;

void cpu_single_cycle(Vtop* top);
void cpu_reset(int n, Vtop* top);

#endif
