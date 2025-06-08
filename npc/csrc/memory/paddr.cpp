#include "memory/paddr.h"
#include "macro.h"

uint8_t mem[MEM_MSIZE] PG_ALIGN = {};

uint32_t *inst_mem = NULL;
long mem_size = 0;

uint8_t *guest_to_host(uint32_t paddr) { return mem + paddr - MEM_BASE; }
uint32_t host_to_guest(uint8_t *haddr) { return haddr - mem + MEM_BASE; }

static uint32_t pmem_read(uint32_t addr, int len)
{
    uint32_t ret = 0;
    switch (len)
    {
    case 1:
        ret = *(uint8_t *)addr;
    case 2:
        ret = *(uint16_t *)addr;
    case 4:
        ret = *(uint32_t *)addr;
    default:
        ret = 0;
    }
    return ret;
}

static void pmem_write(uint32_t addr, int len, uint32_t data)
{
    switch (len)
    {
    case 1:
        *(uint8_t *)addr = data;
        return;
    case 2:
        *(uint16_t *)addr = data;
        return;
    case 4:
        *(uint32_t *)addr = data;
        return;
    default:
        assert(0);
    }
}

void init_mem()
{
    Log("physical memory area [ 0x%08x, 0x%08x]", PMEM_LEFT, PMEM_RIGHT);
}

void print_paddr_read(uint32_t addr, int len)
{
    printf("MEM_READ at 0x%08x , len = %d\n", addr, len);
}

void print_paddr_write(uint32_t addr, int len, uint32_t data)
{
    printf("MEM_WRITE at 0x%08x , len = %d, write data: 0x%08x \n", addr, len, data);
}

uint32_t paddr_read(uint32_t addr, int len)
{
#ifdef CONFIG_MTRACE
    print_paddr_read(pc, len);
#endif
    return pmem_read(addr, len);
}

void paddr_write(uint32_t addr, int len, uint32_t data)
{
}
