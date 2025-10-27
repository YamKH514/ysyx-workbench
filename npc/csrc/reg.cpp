#include "reg.h"
#include "Vtop.h"
#include "Vtop__Dpi.h"
#include "cpu.h"

#define IS_THIS_REG(reg_name) (strcmp(s, reg_name) == 0)
#define csr_val(csr_name) cpu.csr.csr_name

const char *regs[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"};

int reg_length = sizeof(regs) / sizeof(regs[0]);
void reg_display()
{
    int gpr[16] = {0};
    svSetScope(svGetScopeFromName("TOP.top.u_GPR.u_RegisterFile"));
    get_gpr(gpr);
    for (int i = 0; i < reg_length; i++)
    {
        printf("%-10s 0x%08x  %-10u\n", regs[i], gpr[i], gpr[i]);
    }
    printf("MEPC       0x%08x  %-10u\n", cpu.csr.mepc, cpu.csr.mepc);
    printf("MCAUSE     0x%08x  %-10u\n", cpu.csr.mcause, cpu.csr.mcause);
    printf("MTVEC      0x%08x  %-10u\n", cpu.csr.mtvec, cpu.csr.mtvec);
    printf("MSTATUS    0x%08x  %-10u\n", cpu.csr.mstatus, cpu.csr.mstatus);
}

uint32_t reg_str2val(const char *s, bool *success)
{
    if (IS_THIS_REG("PC"))
    {
        printf("$PC: 0x%08x\n", cpu.pc);
        return cpu.pc;
    }
    else if (IS_THIS_REG("MEPC"))
    {
        printf("$MEPC: 0x%08x\n", cpu.csr.mepc);
        return csr_val(mepc);
    }
    else if (IS_THIS_REG("MCAUSE"))
    {
        printf("$MCAUSE: 0x%08x\n", cpu.csr.mcause);
        return csr_val(mcause);
    }
    else if (IS_THIS_REG("MTVEC"))
    {
        printf("$MTVEC: 0x%08x\n", cpu.csr.mtvec);
        return csr_val(mtvec);
    }
    else if (IS_THIS_REG("MSTATUS"))
    {
        printf("$MSTATUS: 0x%08x\n", cpu.csr.mstatus);
        return csr_val(mstatus);
    }
    else
    {
        int i;
        for (i = 0; i < reg_length; i++)
        {
            if (strcmp(s, regs[i]) == 0)
                break;
        }
        return gpr(i);
    }
}
