#ifndef UTILS_H__
#define UTILS_H__

#include "common.h"

typedef struct {
    uint32_t halt_pc;
    int32_t halt_ret;
  } NPCState;

extern NPCState npc_state;

#endif
