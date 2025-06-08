#ifndef REG_H__
#define REG_H__

#include "common.h"

static inline int check_reg_idx(int idx) {
  assert(idx >= 0 && idx < 16);
  return idx;
}

#define gpr(idx) (npc_state.gpr_value[check_reg_idx(idx)])

#define pc_addr npc_state.halt_pc

static inline const char* reg_name(int idx) {
  extern const char* regs[];
  return regs[check_reg_idx(idx)];
}

void reg_display();

#endif
