#ifndef MEMORY_PADDR_H__
#define MEMORY_PADDR_H__

#include "common.h"

#ifdef PLATFORM_YSYXSOC
#define PMEM_LEFT  ((uint32_t)CONFIG_MBASE)
#define PMEM_RIGHT ((uint32_t)CONFIG_MBASE + CONFIG_MSIZE - 1)
#define SRAM_LEFT  ((uint32_t)CONFIG_SRAMBASE)
#define SRAM_RIGHT ((uint32_t)CONFIG_SRAMBASE + CONFIG_SRAMSIZE - 1)
#define PSRAM_LEFT  ((uint32_t)CONFIG_PSRAMBASE)
#define PSRAM_RIGHT ((uint32_t)CONFIG_PSRAMBASE + CONFIG_PSRAMSIZE - 1)
#define SDRAM_LEFT  ((uint32_t)CONFIG_SDRAMBASE)
#define SDRAM_RIGHT ((uint32_t)CONFIG_SDRAMBASE + CONFIG_SDRAMSIZE - 1)
#else
#define PMEM_LEFT  ((uint32_t)CONFIG_NPC_PMEMBASE)
#define PMEM_RIGHT ((uint32_t)CONFIG_NPC_PMEMBASE + CONFIG_NPC_PMEMSIZE - 1)
#endif
#define RESET_VECTOR PMEM_LEFT

uint8_t *guest_to_host(uint32_t paddr);
uint32_t host_to_guest(uint8_t *haddr);

static inline bool in_pmem(uint32_t addr)
{
#ifdef PLATFORM_YSYXSOC
    bool in_mrom = (PMEM_LEFT <= addr) && (addr < PMEM_RIGHT);
    bool in_sram = (SRAM_LEFT <= addr) && (addr < SRAM_RIGHT);
    bool in_psram = (PSRAM_LEFT <= addr) && (addr < PSRAM_RIGHT);
    bool in_sdram = (SDRAM_LEFT <= addr) && (addr < SDRAM_RIGHT);
    return in_mrom | in_sram | in_psram | in_sdram;
#else
    return (PMEM_LEFT <= addr) && (addr < PMEM_RIGHT);
#endif
}

void init_mem();
extern "C" void mrom_read(int32_t addr, int32_t *data);
extern "C" uint32_t paddr_read(uint32_t raddr);

#endif
