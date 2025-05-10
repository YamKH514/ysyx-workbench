#ifndef MEM_H__
#define MEM_H__

#include "common.h"

void init_npcmem(int argc, char *argv[]);

void init_mem(uint32_t *img, long size);
uint32_t mem_read(uint32_t pc);
void mem_end();

#endif
