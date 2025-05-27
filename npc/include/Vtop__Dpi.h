#ifndef VTOP__DPI_H__
#define VTOP__DPI_H__

#include "common.h"

extern void ebreak_trigger();
extern int get_inst(int pc);
extern void get_gpr(int out_gpr[16]);

#endif
