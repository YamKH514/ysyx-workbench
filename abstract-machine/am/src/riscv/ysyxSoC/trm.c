#include <am.h>
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

extern char _data_start_load, _data_start, _data_end;
extern char _bss_start, _bss_end;

void putch(char ch) {
  asm volatile("sb %0, 0(%1)" : : "r"(ch), "r"(UART_BASE + UART_TX));
}

void halt(int code) {
  npc_trap(code);

  while (1);
}

void cp_data_to_sram() {
  char *src = &_data_start_load;
  char *dst = &_data_start;

  while (dst < &_data_end) {
    *dst = *src;
    src++;
    dst++;
  }

  char *p = &_bss_start;
  while (p < &_bss_end)
  {
    *p = 0;
    p++;
  }
}

void _trm_init() {
  cp_data_to_sram();
  int ret = main(mainargs);
  halt(ret);
}
