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

#define PS2_BASE 0x10011000L

#define VGA_BASE 0x21000000L

extern char _heap_start;
#define _heap_end 0xa8000000
int main(const char *args);

#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

#define MEMCOPY_BYTE(start, load_start, size) for (size_t i = 0; i < (size_t)(size); i++) { \
                                            *((start) + i) = *((load_start) + i); \
                                          }
#define MEMCOPY_WORD(start, load_start, size) for (uint32_t i = 0; i < ((uint32_t)(size)>>2); i++) { \
                                            *((start) + i) = *((load_start) + i); \
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

char getch() {
  if ((*(volatile char *)(UART_BASE + UART_LSR) & (1 << 0)) == 0) return 0xFF;
  else return *(volatile char *)(UART_BASE + UART_RX);
}

uint8_t getkey() {
  return *(volatile uint8_t *)(PS2_BASE);
}

void setpixel(uint32_t waddr, uint32_t haddr, uint32_t data) {
  *(volatile uint32_t *)(VGA_BASE + waddr * haddr) = data;
}

void _ssbl();
__attribute__((section("fsbl"))) __attribute__((used))
void _fsbl() {
  extern uint8_t ssbl_start [];
  extern uint8_t ssbl_size [];
  extern uint8_t ssbl_load_start [];
  MEMCOPY_BYTE(ssbl_start, ssbl_load_start, ssbl_size);
  _ssbl();
}

void _trm_init();
__attribute__((section("ssbl"))) __attribute__((used))
void _ssbl() {
  extern uint8_t text_start [];
  extern uint8_t text_size [];
  extern uint8_t text_load_start [];
  extern uint8_t rodata_start [];
  extern uint8_t rodata_end [];
  extern uint8_t rodata_size [];
  extern uint8_t rodata_load_start [];
  extern uint8_t data_start [];
  extern uint8_t data_end [];
  extern uint8_t data_size [];
  extern uint8_t data_load_start [];
  extern uint8_t data_extra_start [];
  extern uint8_t data_extra_end [];
  extern uint8_t data_extra_size [];
  extern uint8_t data_extra_load_start [];
  MEMCOPY_BYTE(text_start, text_load_start, text_size);
  if (rodata_end - rodata_start) MEMCOPY_BYTE(rodata_start, rodata_load_start, rodata_size);
  if (data_end - data_start) MEMCOPY_BYTE(data_start, data_load_start, data_size);
  if (data_extra_end - data_extra_start) MEMCOPY_BYTE(data_extra_start, data_extra_load_start, data_extra_size);
  _trm_init();
}

static void print_info() {
  uint32_t mvendorid;
  uint32_t marchid;
  asm volatile("csrr %0, mvendorid" : "=r"(mvendorid):);
  asm volatile("csrr %0, marchid" : "=r"(marchid):);
  for(int i = 3; i >= 0; i--){
      putch((char)((mvendorid >> i*8) & 0xFF));
  }
  printf("_%d\n", marchid);
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
