#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#define UART_BASE 0x10000000L
#define UART_TX 0x0

extern char _heap_start;
#define _heap_end 0x0f001fff
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE 0x1000
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

Area heap = RANGE(&_heap_start, _heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void putch(char ch) {
  *(volatile char *)(UART_BASE + UART_TX) = ch;
}



void bootloader(void)
{
  extern char data_start [];
extern char data_size [];
extern char data_load_start [];
  memcpy(data_start, data_load_start, (size_t) data_size);
}

// static void bootloader() {
//   extern char _data_start[], _load_data_start[], _load_data_size;
//     memcpy(_data_start, _load_data_start, (size_t)_load_data_size);
// }

void halt(int code) {
  npc_trap(code);

  while (1);
}

void _trm_init() {
  bootloader();
  int ret = main(mainargs);
  halt(ret);
}
