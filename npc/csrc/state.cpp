#include "utils.h"
#ifdef CONFIG_NVBOARD
#include <nvboard.h>
#endif

NPCState npc_state = {.state = NPC_STOP, .halt_pc = 0, .halt_ret = -1, .inited = false};

int is_exit_status_bad() {
  int good = (npc_state.state == NPC_END && npc_state.halt_ret == 0) ||
    (npc_state.state == NPC_QUIT);
#ifdef CONFIG_NVBOARD
  nvboard_quit();
#endif
  return !good;
}
