#include "reg.h"

const char *regs[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"};

int reg_length = sizeof(regs) / sizeof(regs[0]);
void reg_display()
{
    for (int i = 0; i < reg_length; i++)
    {
        printf("%-10s 0x%-08x  %-10u\n", regs[i], gpr(i), gpr(i));
    }
}
