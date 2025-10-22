#ifndef VTOP__DPI_H__
#define VTOP__DPI_H__

#include "common.h"

extern void ebreak_trigger();
extern uint32_t paddr_read(uint32_t raddr);
extern void paddr_write(uint32_t waddr, uint32_t wdata, char wmask);
extern int get_inst(int pc);
extern void get_gpr(int out_gpr[16]);
extern void get_csr(int csr[4]);

#ifdef CONFIG_DIFFTEST
extern void difftest_skip_ref(int pc);
#endif

#endif
