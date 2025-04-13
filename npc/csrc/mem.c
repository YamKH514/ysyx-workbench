#include <stdint.h>
#include <assert.h>

#define INST_BASE 0x80000000

uint32_t inst_mem[] = {
    0x11500613,
    0x00260613,
    0x00060693,
    0x00100073,
};

#define INST_MEM_SIZE (sizeof(inst_mem) / sizeof(inst_mem[0]))

uint32_t mem_read(uint32_t pc) {
    assert(pc >= INST_BASE);
    uint32_t index = (pc - INST_BASE) >> 2;
    assert(index < INST_MEM_SIZE);
    return inst_mem[index];
}
