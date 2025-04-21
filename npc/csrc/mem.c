#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#define INST_BASE 0x80000000

uint32_t *inst_mem = NULL;
long mem_size = 0;

#define INST_MEM_SIZE (sizeof(inst_mem) / sizeof(inst_mem[0]))

void init_mem(uint32_t **img, long size)
{
  assert(*img != NULL);

}

uint32_t mem_read(uint32_t pc) {
    assert(pc >= INST_BASE);
    uint32_t index = (pc - INST_BASE) >> 2;
    assert(index < INST_MEM_SIZE);
    return inst_mem[index];
}
