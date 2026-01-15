#include "verilated.h"
#include "common.h"
#include "utils.h"

extern "C" void ebreak_trigger()
{
    Log("EBREAK, stopping simulation.");
    Verilated::gotFinish(true);
    npc_state.state = NPC_END;
}