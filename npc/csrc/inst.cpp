#include "common.h"
#include "utils.h"
#include "memory/paddr.h"

extern "C" int get_inst(int pc)
{
    uint32_t inst = 0;
    if((uint32_t)pc >= 0x80000000)
    {
        inst = paddr_read((uint32_t)pc, 4);
    }
    return (int)inst;
}
