/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include "local-include/reg.h"

#define IS_THIS_REG(reg_name) (strcmp(s, reg_name) == 0)
#define csr_val(csr_name) cpu.csr.csr_name

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

int reg_length = sizeof(regs)/sizeof(regs[0]);

void isa_reg_display() {
  for(int i = 0; i < reg_length; i++) {
    printf("%-10s 0x%-8x  %-10u\n", regs[i], gpr(i), gpr(i));
  }
  printf("MEPC       0x%-8x  %-10u\n", cpu.csr.mepc, cpu.csr.mepc);
  printf("MCAUSE     0x%-8x  %-10u\n", cpu.csr.mcause, cpu.csr.mcause);
  printf("MTVEC      0x%-8x  %-10u\n", cpu.csr.mtvec, cpu.csr.mtvec);
  printf("MSTATUS    0x%-8x  %-10u\n", cpu.csr.mstatus, cpu.csr.mstatus);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  if(IS_THIS_REG("pc")) {
    printf("pc: %x\n", pc_addr);
    return pc_addr;
  }
  else if(IS_THIS_REG("mepc"))
    return csr_val(mepc);
  else if(IS_THIS_REG("mcause"))
    return csr_val(mcause);
  else if(IS_THIS_REG("mtvec"))
    return csr_val(mtvec);
  else if(IS_THIS_REG("mstatus"))
    return csr_val(mstatus);
  else {
    int i;
    for(i = 0; i < reg_length; i++) {
      if(strcmp(s, regs[i]) == 0) break;
    }
    return gpr(i);
  }
}
