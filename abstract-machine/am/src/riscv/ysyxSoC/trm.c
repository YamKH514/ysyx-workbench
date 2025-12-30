#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#define UART_BASE 0x10000000L
#define UART_TX 0x0

extern char _heap_start;
extern char _heap_end;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

extern char _data_start[], _data_load_start[], _data_load_end;

void putch(char ch) {
  *(volatile char *)(UART_BASE + UART_TX) = ch;
}

void bootloader() {
  size_t load_size = (uintptr_t)&_data_load_end - (uintptr_t)_data_load_start;
  memcpy(_data_start, _data_load_start, load_size);
}

void halt(int code) {
  npc_trap(code);

  while (1);
}

void _trm_init() {
  bootloader();
  int ret = main(mainargs);
  halt(ret);
}
