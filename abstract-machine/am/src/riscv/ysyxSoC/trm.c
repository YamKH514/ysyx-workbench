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
#define _heap_end 0x0f001fff
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE 0x1000
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

Area heap = RANGE(&_heap_start, _heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

static void uart_init() {
  // *(volatile char *)(UART_BASE + UART_FCR) = 0x06; // Clear & reset RX&TX FIFOs
  // Set Divisor Latch register
  *(volatile char *)(UART_BASE + UART_LCR) = (1 << 7);
  *(volatile char *)(UART_BASE + UART_MSB) = 0x00;
  *(volatile char *)(UART_BASE + UART_LSB) = 0x01;
  *(volatile char *)(UART_BASE + UART_LCR) = 0x00;

  *(volatile char *)(UART_BASE + UART_IER) = 0x00; // Disable all interrupts
  *(volatile char *)(UART_BASE + UART_FCR) = 0xC0;
  *(volatile char *)(UART_BASE + UART_LCR) = 0x03; // Set LCR 8 bits of data, np parity and 1 stop bit
}

void putch(char ch) {
  *(volatile char *)(UART_BASE + UART_TX) = ch;
}

extern char data_start [];
extern char data_size [];
extern char data_load_start [];

static void bootloader()
{
  memcpy(data_start, data_load_start, (size_t) data_size);
}

void halt(int code) {
  npc_trap(code);

  while (1);
}

void _trm_init() {
  uart_init();
  bootloader();
  int ret = main(mainargs);
  halt(ret);
}
