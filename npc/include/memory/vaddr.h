#ifndef MEMORY_VADDR_H__
#define MEMORY_VADDR_H__

#include "common.h"

uint32_t vaddr_ifetch(uint32_t addr, int len);
uint32_t vaddr_read(uint32_t addr, int len);
void vaddr_write(uint32_t addr, int len, uint32_t data);

#endif
