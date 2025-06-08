#ifndef MEMORY_PADDR_H__
#define MEMORY_PADDR_H__

#include "common.h"

#define MEM_BASE 0x80000000
#define MEM_MSIZE 0x8000000

#define PMEM_LEFT ((uint32_t)MEM_BASE)
#define PMEM_RIGHT ((uint32_t)MEM_BASE + MEM_MSIZE - 1)
#define RESET_VECTOR PMEM_LEFT

uint8_t *guest_to_host(uint32_t paddr);
uint32_t host_to_guest(uint8_t *haddr);

static inline bool in_pmem(uint32_t addr)
{
    return addr - MEM_BASE < MEM_MSIZE;
}

void init_mem();
uint32_t paddr_read(uint32_t addr, int len);
void paddr_write(uint32_t addr, int len, uint32_t data);

#endif
