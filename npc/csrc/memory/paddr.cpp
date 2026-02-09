#include "memory/host.h"
#include "memory/paddr.h"
#include "macro.h"
#include "utils.h"
#include "timer.h"
#include "difftest-def.h"
#include "cpu.h"

#define DEVICE_BASE 0xa0000000
#define SERIAL_PORT (DEVICE_BASE + 0x00003f8)

// static uint32_t flash_data[10] =   {0x100007b7, // lui	a5,0x10000
//                                     0x04100713, // li	a4,65
//                                     0x00e78023, // sb	a4,0(a5) # 10000000
//                                     0x00a00713, // li	a4,10
//                                     0x00e78023, // sb	a4,0(a5)
//                                     0x00008067  // ret
//                                     };
#ifdef PLATFORM_YSYXSOC
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
static uint8_t psram[CONFIG_PSRAMSIZE] PG_ALIGN = {};
static uint8_t sdram[CONFIG_SDRAMSIZE] PG_ALIGN = {};
#else
static uint8_t pmem[CONFIG_NPC_PMEMSIZE] PG_ALIGN = {};
#endif

uint8_t *guest_to_host(uint32_t paddr) {
#ifdef PLATFORM_YSYXSOC
    if ((CONFIG_MBASE <= paddr) && (paddr <= CONFIG_MBASE + CONFIG_MSIZE)) return pmem + paddr - CONFIG_MBASE;
    else if ((CONFIG_PSRAMBASE <= paddr) && (paddr <= CONFIG_PSRAMBASE + CONFIG_PSRAMSIZE)) return psram + paddr - CONFIG_PSRAMBASE;
    else if ((CONFIG_SDRAMBASE <= paddr) && (paddr <= CONFIG_SDRAMBASE + CONFIG_SDRAMSIZE)) return sdram + paddr - CONFIG_SDRAMBASE;
#else
    if ((CONFIG_NPC_PMEMBASE <= paddr) && (paddr <= CONFIG_NPC_PMEMBASE + CONFIG_NPC_PMEMSIZE))
        return pmem + paddr - CONFIG_NPC_PMEMBASE;
#endif
    assert(0);
}

uint32_t host_to_guest(uint8_t *haddr) {
#ifdef PLATFORM_YSYXSOC
    if ((CONFIG_MBASE <= (uintptr_t)haddr) && ((uintptr_t)haddr <=  CONFIG_MBASE + CONFIG_MSIZE)) return haddr - pmem + CONFIG_MBASE;
    else if ((CONFIG_PSRAMBASE <= (uintptr_t)haddr) && ((uintptr_t)haddr <= CONFIG_PSRAMBASE + CONFIG_PSRAMSIZE)) return haddr - psram + CONFIG_PSRAMBASE;
    else if ((CONFIG_SDRAMBASE <= (uintptr_t)haddr) && ((uintptr_t)haddr <= CONFIG_SDRAMBASE + CONFIG_SDRAMSIZE)) return haddr - sdram + CONFIG_SDRAMBASE;
#else
    if ((CONFIG_NPC_PMEMBASE <= (uintptr_t)haddr) && ((uintptr_t)haddr <=  CONFIG_NPC_PMEMBASE + CONFIG_NPC_PMEMSIZE))
        return haddr - pmem + CONFIG_NPC_PMEMBASE;
#endif
    assert(0);
}

static uint32_t pmem_read(uint32_t addr, int len)
{
    uint32_t ret = host_read(guest_to_host(addr), len);
    return ret;
}

static void pmem_write(uint32_t addr, int len, uint32_t data)
{
    host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(uint32_t addr)
{
    panic("address = 0x%08x is out of bound of pmem [ 0x%08x , 0x%08x ] at pc = 0x%08x",
          addr, PMEM_LEFT, PMEM_RIGHT, npc_state.halt_pc);
}

void init_mem()
{
#ifdef PLATFORM_YSYXSOC
    Log("flash area [ 0x%08x, 0x%08x]", PMEM_LEFT, PMEM_RIGHT);
    Log("sram  area [ 0x%08x, 0x%08x]", SRAM_LEFT, SRAM_RIGHT);
    Log("psram area [ 0x%08x, 0x%08x]", PSRAM_LEFT, PSRAM_RIGHT);
    Log("sdram area [ 0x%08x, 0x%08x]", SDRAM_LEFT, SDRAM_RIGHT);
#else
    Log("pmem area [ 0x%08x, 0x%08x]", PMEM_LEFT, PMEM_RIGHT);
#endif
}

extern "C" void mem_tracer_read(int32_t addr, int32_t data)
{
#ifdef CONFIG_MTRACE
    printf("MEM_READ , raddr=0x%08x, rdata=0x%08x\n", addr, data);
#endif
}

extern "C" void mem_tracer_write(int32_t addr, int32_t data, int32_t strb)
{
    if ((CONFIG_SDRAMBASE <= addr) && (addr <= CONFIG_SDRAMBASE + CONFIG_SDRAMSIZE)) {
        if (strb & 1 << 0) pmem_write(addr+0, 1, (data >> 0) & 0xFF);
        if (strb & 1 << 1) pmem_write(addr+1, 1, (data >> 8) & 0xFF);
        if (strb & 1 << 2) pmem_write(addr+2, 1, (data >>16) & 0xFF);
        if (strb & 1 << 3) pmem_write(addr+3, 1, (data >>24) & 0xFF);
    }
#ifdef CONFIG_MTRACE
    printf("MEM_WRITE, waddr=0x%08x, wdata=0x%08x, wstrb=0x%08x\n", addr, data, strb);
#endif
}

extern "C" void mrom_read(int32_t addr, int32_t *data)
{
    assert(0);
    uint32_t raddr = ((uint32_t)addr) & ~0x3u;
    uint32_t rdata = pmem_read(raddr, 4);
    *data = (int32_t)rdata;
    return;
}

extern "C" void flash_read(int32_t addr, int32_t *data)
{
    uint32_t raddr = CONFIG_MBASE + (((uint32_t)addr) & ~0x3u);
    if(likely(in_pmem(raddr)))
    {
        uint32_t rdata = pmem_read(raddr, 4);
        *data = (int32_t)rdata;
        return;
    }
    out_of_bound(raddr);
    return;
}

extern "C" void psram_read(int32_t addr, int32_t *data) {
    uint32_t raddr = CONFIG_PSRAMBASE + (uint32_t)addr;
    *data = pmem_read(raddr, 4);
    return;
}

extern "C" void psram_write(int32_t addr, int32_t data, int32_t mask) {
    uint32_t waddr = CONFIG_PSRAMBASE + (uint32_t)addr;
    uint32_t wdata = data >> ((8-mask)*4);
    int len;
    switch (mask/2) {
        case 0x1: case 0x10: case 0x100: case 0x1000:
            len = 1;
            break;
        case 0x11: case 0x110: case 0x1100:
            len = 2;
            break;
        case 0x1111:
            len = 4;
            break;
    }
    pmem_write(waddr, len, wdata);
    return;
}

extern "C" int32_t sdram_read(int32_t addr) {
    uint32_t raddr = CONFIG_SDRAMBASE + (uint32_t)addr;
    uint32_t rdata = pmem_read(raddr, 2);
    printf("sdram_read: raddr: 0x%08x, data: 0x%08x\n", raddr, rdata);
    return (int32_t)rdata;
}

extern "C" void sdram_write(int32_t addr, int32_t data, int32_t dqm) {
    uint32_t waddr = CONFIG_SDRAMBASE + (uint32_t)addr;
    uint32_t wdata;
    int len;
    switch (dqm) {
        case 0x3:   // 16bit均无效
            return;
        case 0x2:   // 低8bit有效
            len = 1;
            wdata = (data & 0x00FF);
            break;
        case 0x1:   // 高8bit有效
            len = 1;
            waddr += 1;
            wdata = (data & 0xFF00) >> 8;
            break;
        case 0x0:   // 16bit均有效
            len = 2;
            wdata = data;
            break;
    }
    pmem_write(waddr, len, wdata);
    return;
}

uint32_t paddr_read(uint32_t raddr)
{
#ifdef PLATFORM_YSYXSOC
    uint32_t rdata = 0;
    if ((PMEM_LEFT <= raddr) & (raddr < PMEM_RIGHT)) flash_read(raddr - PMEM_LEFT, (int32_t *)&rdata);
    else if ((PSRAM_LEFT <= raddr) & (raddr < PSRAM_RIGHT)) psram_read(raddr - PSRAM_LEFT, (int32_t *)&rdata);
    else if ((SDRAM_LEFT <= raddr) & (raddr < SDRAM_RIGHT)) rdata = sdram_read(raddr - SDRAM_LEFT);
    else assert(0);
    return rdata;
#else
    if ((PMEM_LEFT <= raddr) & (raddr < PMEM_RIGHT)) return pmem_read(raddr, 4);
#endif
    assert(0);
}

extern int npcmem_read(int raddr)
{
    uint32_t addr = (uint32_t)raddr & ~0x3u;
    
    if(likely(in_pmem(addr)))
    {
        return pmem_read(addr, 4);
    }
    out_of_bound(addr);
    return 0;
}

extern void npcmem_write(int waddr, int wdata, char wmask)
{
    uint32_t addr = (uint32_t)waddr & ~0x3u, data = (uint32_t)wdata;
    uint8_t  mask = (uint8_t) wmask;
    if(addr == SERIAL_PORT)
    {
        putchar(data & 0xFF);
        return;
    }

    int cnt = 0;
    if(likely(in_pmem(addr)))
    {
        for (int i = 0; i < 4; i++)
        {
            if (mask & (1 << i))
            {
                uint8_t byte = (data >> (i * 8)) & 0xFF;
                pmem_write(addr + i, 1, byte);
            }
        }
        return;
    }

    out_of_bound(addr);
}

extern "C" void perip_difftest_skip(int32_t addr)
{
    if (!in_pmem(addr)){
#ifdef CONFIG_DIFFTEST
        difftest_skip_ref();
#endif
    }
    return;
}

extern "C" void clint_difftest_skip()
{
#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();
#endif
    return;
}
