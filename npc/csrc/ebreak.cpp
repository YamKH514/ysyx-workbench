#include "verilated.h"
#include "common.h"
#include "utils.h"

extern "C" void ebreak_trigger()
{
    printf("EBREAK, stopping simulation.\n");
    Verilated::gotFinish(true);
}