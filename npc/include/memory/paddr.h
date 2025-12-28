#ifndef MEMORY_PADDR_H__
#define MEMORY_PADDR_H__

#include "common.h"

#define PMEM_LEFT  ((uint32_t)CONFIG_MBASE)
#define PMEM_RIGHT ((uint32_t)CONFIG_MBASE + CONFIG_MSIZE - 1)
#define RESET_VECTOR PMEM_LEFT

uint8_t *guest_to_host(uint32_t paddr);
uint32_t host_to_guest(uint8_t *haddr);

static inline bool in_pmem(uint32_t addr)
{
    return addr - CONFIG_MBASE < CONFIG_MSIZE;
}

void init_mem();
extern "C" void mrom_read(int32_t addr, int32_t *data);

#endif
