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
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>
#include "../../isa/riscv32/local-include/reg.h"

typedef struct
{
  int gpr_value[RISCV_GPR_NUM];
  uint32_t halt_pc;
} diff_context_t;

// 获取REF的寄存器状态到`dut`
void diff_get_regs(void *diff_context)
{
  diff_context_t *ctx = (diff_context_t *)diff_context;
  for(int i = 0; i < RISCV_GPR_NUM; i++)
  {
    ctx->gpr_value[i] = gpr(i);
  }
  ctx->halt_pc = cpu.pc;
}

// 设置REF的寄存器状态为`dut`
void diff_set_regs(void *diff_context)
{
  diff_context_t *ctx = (diff_context_t *)diff_context;
  for(int i = 0; i < RISCV_GPR_NUM; i++)
  {
    gpr(i) = ctx->gpr_value[i];
  }
  cpu.pc = ctx->halt_pc;
}

void diff_step(uint64_t n)
{
  cpu_exec(n);
}

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if (direction == DIFFTEST_TO_REF) memcpy(guest_to_host(addr), buf, n);
  else memcpy(buf, guest_to_host(addr), n);
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    diff_set_regs(dut);
  } else {
    diff_get_regs(dut);
  }
}

__EXPORT void difftest_exec(uint64_t n) {
  diff_step(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
