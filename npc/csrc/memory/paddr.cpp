#include "memory/host.h"
#include "memory/paddr.h"
#include "macro.h"
#include "utils.h"

#define DEVICE_BASE 0xa0000000
#define SERIAL_PORT (DEVICE_BASE + 0x00003f8)
#define RTC_ADDR    (DEVICE_BASE + 0x0000048)

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
    printf("MEM_READ  data: 0x%08x, at 0x%08x , len = %d\n", pmem_read(addr, len), addr, len);
}

void print_paddr_write(uint32_t addr, int len, uint32_t data)
{
    printf("MEM_WRITE data: 0x%08x, at 0x%08x , len = %d\n", data, addr, len);
}

extern "C" uint32_t paddr_read(uint32_t raddr)
{
    uint32_t addr = raddr & ~0x3u;
    
#ifdef CONFIG_MTRACE
    print_paddr_read(addr, 4);
#endif
if(addr == RTC_ADDR)
    {
        return 0;
    }
    if(likely(in_pmem(addr)))
    {
        return pmem_read(addr, 4);
    }
    out_of_bound(addr);
    return 0;
}

extern "C" void paddr_write(uint32_t waddr, uint32_t wdata, uint8_t wmask)
{
    uint32_t addr = waddr & ~0x3u;
    uint32_t data = 0;
    uint32_t offset = waddr & 0x3;
    if(addr == SERIAL_PORT)
    {
        putchar(wdata);
        return;
    }
    switch (wmask)
    {
    case 0x1:
        data = ((wdata & 0xFF) << (offset * 8)) | (pmem_read(addr, 4) & ~(0xFFu << (offset * 8)));
        break;
    case 0x3:
        data = ((wdata & 0xFFFF) << (offset * 8)) | (pmem_read(addr, 4) & ~(0xFFFFu << (offset * 8)));
        break;
    case 0xF:
        data = wdata;
        break;
    default:
        data = 0;
        break;
    }


#ifdef CONFIG_MTRACE
    print_paddr_write(addr, 4, data);
#endif
    if(likely(in_pmem(addr)))
    {
        pmem_write(addr, 4, data);
        return;
    }
    printf("paddr_write out_of_bound addr = 0x%x\n", addr);
    out_of_bound(addr);
}

extern "C" int get_inst(int pc)
{
    uint32_t inst = 0;
    if((uint32_t)pc >= MEM_BASE)
    {
        inst = paddr_read((uint32_t)pc);
    }
    return (int)inst;
}
