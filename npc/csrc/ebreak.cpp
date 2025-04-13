#include "verilated.h"

extern "C" void ebreak_trigger()
{
    printf("EBREAK, stopping simulation.\n");
    Verilated::gotFinish(true);
}