#include "memory/host.h"
#include "memory/paddr.h"
#include "macro.h"
#include "utils.h"

static uint8_t pmem[MEM_MSIZE] PG_ALIGN = {};

uint8_t *guest_to_host(uint32_t paddr) { return pmem + paddr - MEM_BASE; }
uint32_t host_to_guest(uint8_t *haddr) { return haddr - pmem + MEM_BASE; }

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

extern "C" uint32_t paddr_read(uint32_t raddr)
{
    uint32_t addr = raddr & ~0x3u;
#ifdef CONFIG_MTRACE
    print_paddr_read(addr, 4);
#endif
    if(likely(in_pmem(addr)))
    {
        return pmem_read(addr, 4);
    }
    out_of_bound(addr);
    return 0;
}

extern "C" void paddr_write(uint32_t waddr, uint32_t wdata, char wmask)
{
    uint32_t addr = waddr & ~0x3u;
    int len = 0;
    switch (wmask)
    {
    case 0x1:
        len = 1;
        break;
    case 0x3:
        len = 2;
        break;
    case 0xF:
        len = 4;
        break;
    default:
        len = 4;
        break;
    }

#ifdef CONFIG_MTRACE
    print_paddr_write(addr, len, data);
#endif
    if(likely(in_pmem(addr)))
    {
        pmem_write(addr, len, wdata);
        return;
    }
    out_of_bound(addr);
}

extern "C" int get_inst(int pc)
{
    uint32_t inst = 0;
    if((uint32_t)pc >= 0x80000000)
    {
        inst = paddr_read((uint32_t)pc);
    }
    return (int)inst;
}
