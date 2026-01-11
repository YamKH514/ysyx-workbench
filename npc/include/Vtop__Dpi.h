#ifndef VTOP__DPI_H__
#define VTOP__DPI_H__

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void ebreak_trigger();
extern void mem_tracer_read(int32_t addr, int32_t data);
extern void mem_tracer_write(int32_t addr, int32_t data);
extern uint32_t paddr_read(uint32_t raddr);
extern void paddr_write(uint32_t waddr, uint32_t wdata, char wmask);
extern void get_gpr(int out_gpr[16]);
extern void get_csr(int csr[6]);
extern void uart_difftest_skip();
extern void clint_difftest_skip();

#ifdef __cplusplus
}
#endif

#endif
