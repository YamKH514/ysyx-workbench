#include "verilated.h"
#include "utils.h"

extern "C" void ebreak_trigger()
{
    printf("EBREAK, stopping simulation.\n");
    npc_state = NPC_END;
    Verilated::gotFinish(true);
}