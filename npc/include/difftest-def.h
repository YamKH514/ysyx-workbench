#ifndef DIFFTEST_DEF_H__
#define DIFFTEST_DEF_H__

#include <stdint.h>
#include "macro.h"
#include "generated/autoconf.h"

#define __EXPORT __attribute__((visibility("default")))
enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

#define RISCV_GPR_TYPE uint32_t
#define RISCV_GPR_NUM 16
#define DIFFTEST_REG_SIZE (sizeof(RISCV_GPR_TYPE) * (RISCV_GPR_NUM + 1)) // GPRs + pc

void init_difftest(char *ref_so_file, long img_size, int port);
void difftest_step(uint32_t pc, uint32_t npc);
void difftest_skip_ref();

#endif
