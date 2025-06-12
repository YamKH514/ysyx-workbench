#include "memory/paddr.h"

uint32_t vaddr_ifetch(uint32_t addr, int len)
{
    return paddr_read(addr, len);
}

uint32_t vaddr_read(uint32_t addr, int len)
{
    return paddr_read(addr, len);
}

void vaddr_write(uint32_t addr, int len, uint32_t data)
{
    paddr_write(addr, len, data);
}
