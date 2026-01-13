#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#define UART_BASE 0x10000000L
#define UART_TX 0x0
#define UART_RX 0x0
#define UART_IER 0x1
#define UART_IIR 0x2
#define UART_FCR 0x2
#define UART_LCR 0x3
#define UART_MCR 0x4
#define UART_LSR 0x5
#define UART_MSR 0x6
#define UART_LSB 0x0
#define UART_MSB 0x1

extern char _heap_start;
#define _heap_end 0x80400000
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE 0x1000
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

#define MEMCOPY(start, load_start, size) for (size_t i = 0; i < (size_t)(size); i++) { \
                                            *((start) + i) = *((load_start) + i); \
                                          }
#define MEMSETZ(start, size) for (size_t i = 0; i < (size_t)(size); i++) { \
                                *((start) + i) = 0;\
                              }

Area heap = RANGE(&_heap_start, _heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

static void uart_init() {
  // Set Divisor Latch register
  *(volatile char *)(UART_BASE + UART_LCR) = (1 << 7);
  *(volatile char *)(UART_BASE + UART_MSB) = 0x00;
  *(volatile char *)(UART_BASE + UART_LSB) = 0x01;

  *(volatile char *)(UART_BASE + UART_LCR) = 0x03; // Set LCR 8N1
  *(volatile char *)(UART_BASE + UART_IER) = 0x00; // Disable all interrupts
  *(volatile char *)(UART_BASE + UART_FCR) = 0xC7; // Clear & reset RX&TX FIFOs, receiver FIFO Interrupt trigger level 14bytes
}

void putch(char ch) {
  while ((*(volatile char *)(UART_BASE + UART_LSR) & (1 << 5)) == 0); // Waiting the Transmit FIFO empty
  *(volatile char *)(UART_BASE + UART_TX) = ch;
}

void _ssbl();
__attribute__((section("fsbl"))) __attribute__((used))
void _fsbl() {
  extern char ssbl_start [];
  extern char ssbl_size [];
  extern char ssbl_load_start [];
  MEMCOPY(ssbl_start, ssbl_load_start, ssbl_size);
  _ssbl();
}

void _trm_init();
__attribute__((section("ssbl"))) __attribute__((used))
void _ssbl() {
  extern char text_start [];
  extern char text_size [];
  extern char text_load_start [];
  extern char rodata_start [];
  extern char rodata_size [];
  extern char rodata_load_start [];
  extern char data_start [];
  extern char data_size [];
  extern char data_load_start [];
  MEMCOPY(text_start, text_load_start, text_size);
  MEMCOPY(rodata_start, rodata_load_start, rodata_size);
  MEMCOPY(data_start, data_load_start, data_size);
  _trm_init();
}

static void print_info() {
  uint32_t mvendorid;
  uint32_t marchid;
  asm volatile("csrr %0, mvendorid" : "=r"(mvendorid):);
  asm volatile("csrr %0, marchid" : "=r"(marchid):);
  printf("%s_%d\n", &mvendorid, marchid);
}

void halt(int code) {
  npc_trap(code);

  while (1);
}

void _trm_init() {
  uart_init();
  print_info();
  int ret = main(mainargs);
  halt(ret);
}
