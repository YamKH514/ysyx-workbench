#include "common.h"
#include "utils.h"

extern "C" int get_inst(int pc)
{
    uint32_t inst = 0;
    if((uint32_t)pc >= 0x80000000)
    {
        inst = mem_read((uint32_t)pc);
    }
    return (int)inst;
}
