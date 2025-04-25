#include <stdint.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define INST_BASE 0x80000000

uint32_t *inst_mem = NULL;
long mem_size = 0;

void init_mem(uint32_t *img, long size)
{
  assert(img != NULL);
  inst_mem = img;
  mem_size = size / sizeof(inst_mem[0]);
}

uint32_t mem_read(uint32_t pc) {
  assert(pc >= INST_BASE);
  uint32_t index = (pc - INST_BASE) >> 2;
  assert(index < mem_size);
  printf("mem_read, inst: 0x%0.8x at pc = 0x%8x\n", inst_mem[index], pc);
  return inst_mem[index];
}

void mem_end()
{
  free(inst_mem);
}
