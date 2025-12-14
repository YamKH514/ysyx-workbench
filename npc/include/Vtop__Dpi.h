#ifndef VTOP__DPI_H__
#define VTOP__DPI_H__

#include "common.h"

extern void ebreak_trigger();
extern uint32_t paddr_read(uint32_t raddr);
extern void paddr_write(uint32_t waddr, uint32_t wdata, char wmask);
extern void get_gpr(int out_gpr[16]);
extern void get_csr(int csr[4]);
extern void uart_difftest_skip();

#endif
