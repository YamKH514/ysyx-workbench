#include "verilated.h"
#include "common.h"
#include "utils.h"

extern "C" void ebreak_trigger(uint32_t pc, uint32_t ret)
{
    printf("EBREAK, stopping simulation.\n");
    printf("ret = %u\n", ret);
    npc_state = {.state = NPC_END, .halt_pc = pc, .halt_ret = ret};
    Verilated::gotFinish(true);
}