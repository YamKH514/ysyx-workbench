#include "utils.h"

NPCState npc_state = {.state = NPC_END, .halt_pc = 0, .npc = 0, .halt_ret = -1, .inited = false};
