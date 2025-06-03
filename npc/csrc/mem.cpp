#include "common.h"
#include "mem.h"

#define INST_BASE 0x80000000

uint32_t *inst_mem = NULL;
long mem_size = 0;

void init_mem(uint32_t *img, long size)
{
  assert(img != NULL);
  inst_mem = img;
  mem_size = size / sizeof(inst_mem[0]);
}

void print_mem_read(uint32_t addr, int len)
{
  printf("MEM_READ at 0x%08x , len = %d\n", addr, len);
}

void print_mem_write(uint32_t addr, int len, uint32_t data)
{
  printf("MEM_WRITE at 0x%08x , len = %d, write data: 0x%08x \n", addr, len, data);
}

uint32_t mem_read(uint32_t pc) {
  #ifdef CONFIG_MTRACE
    print_mem_read(pc, 4);
  #endif
  assert(pc >= INST_BASE);
  uint32_t index = (pc - INST_BASE) >> 2;
  assert(index < mem_size);
  return inst_mem[index];
}

void mem_end()
{
  free(inst_mem);
}
