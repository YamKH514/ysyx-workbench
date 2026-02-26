/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <memory/host.h>
#include <memory/paddr.h>
#include <memory/mtrace.h>
#include <device/mmio.h>
#include <isa.h>
#include <stdio.h>

#if   defined(CONFIG_PMEM_MALLOC)
#ifdef CONFIG_YSYXSOC
static uint8_t *sram = NULL;
static uint8_t *psram = NULL;
static uint8_t *sdram = NULL;
#endif
#ifdef CONFIG_SOC_BIN
static uint8_t *sram = NULL;
static uint8_t *psram = NULL;
static uint8_t *sdram = NULL;
static uint8_t *uart = NULL;
static uint8_t *clint = NULL;
#endif
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
#ifdef CONFIG_YSYXSOC
static uint8_t sram[CONFIG_SRAMSIZE] PG_ALIGN = {};
static uint8_t psram[CONFIG_PSRAMSIZE] PG_ALIGN = {};
static uint8_t sdram[CONFIG_SDRAMSIZE] PG_ALIGN = {};
#endif
#ifdef CONFIG_SOC_BIN
static uint8_t sram[CONFIG_SRAMSIZE] PG_ALIGN = {};
static uint8_t psram[CONFIG_PSRAMSIZE] PG_ALIGN = {};
static uint8_t sdram[CONFIG_SDRAMSIZE] PG_ALIGN = {};
static uint8_t uart[UART_RIGHT-UART_LEFT+1] PG_ALIGN = {};
static uint8_t clint[CLINT_RIGHT-CLINT_LEFT+1] PG_ALIGN = {};
#endif
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) {
#ifdef CONFIG_YSYXSOC
  if ((PMEM_LEFT <= paddr) && (paddr < PMEM_RIGHT)) return pmem + paddr - CONFIG_MBASE;
  if ((SRAM_LEFT <= paddr) && (paddr < SRAM_RIGHT)) return sram + paddr - CONFIG_SRAMBASE;
  if ((PSRAM_LEFT <= paddr) && (paddr < PSRAM_RIGHT)) return psram + paddr - CONFIG_PSRAMBASE;
  if ((SDRAM_LEFT <= paddr) && (paddr < SDRAM_RIGHT)) return psram + paddr - CONFIG_SDRAMBASE;
  return NULL;
#elifdef CONFIG_SOC_BIN
  if ((PMEM_LEFT <= paddr) && (paddr < PMEM_RIGHT)) return pmem + paddr - CONFIG_MBASE;
  if ((SRAM_LEFT <= paddr) && (paddr < SRAM_RIGHT)) return sram + paddr - CONFIG_SRAMBASE;
  if ((PSRAM_LEFT <= paddr) && (paddr < PSRAM_RIGHT)) return psram + paddr - CONFIG_PSRAMBASE;
  if ((SDRAM_LEFT <= paddr) && (paddr < SDRAM_RIGHT)) return psram + paddr - CONFIG_SDRAMBASE;
  if ((UART_LEFT <= paddr) && (paddr < UART_RIGHT)) return uart + paddr - UART_LEFT;
  if ((CLINT_LEFT <= paddr) && (paddr < CLINT_RIGHT)) return clint + paddr - CLINT_LEFT;
  return NULL;
#else
  return pmem + paddr - CONFIG_MBASE;
#endif
}

paddr_t host_to_guest(uint8_t *haddr) {
#ifdef CONFIG_YSYXSOC
  if ((pmem <= haddr) && (haddr < pmem + CONFIG_MSIZE)) return haddr - pmem + CONFIG_MBASE;
  if ((sram <= haddr) && (haddr < sram + CONFIG_SRAMSIZE)) return haddr - sram + CONFIG_SRAMBASE;
  if ((psram <= haddr) && (haddr < psram + CONFIG_PSRAMSIZE)) return haddr - psram + CONFIG_PSRAMBASE;
  if ((sdram <= haddr) && (haddr < sdram + CONFIG_SDRAMSIZE)) return haddr - psram + CONFIG_SDRAMBASE;
  return 0;
#elifdef CONFIG_SOC_BIN
  if ((pmem <= haddr) && (haddr < pmem + CONFIG_MSIZE)) return haddr - pmem + CONFIG_MBASE;
  if ((sram <= haddr) && (haddr < sram + CONFIG_SRAMSIZE)) return haddr - sram + CONFIG_SRAMBASE;
  if ((psram <= haddr) && (haddr < psram + CONFIG_PSRAMSIZE)) return haddr - psram + CONFIG_PSRAMBASE;
  if ((sdram <= haddr) && (haddr < sdram + CONFIG_SDRAMSIZE)) return haddr - psram + CONFIG_SDRAMBASE;
  if ((uart <= haddr) && (haddr < uart + UART_RIGHT-UART_LEFT+1)) return haddr - uart + UART_LEFT;
  if ((clint <= haddr) && (haddr < clint + CLINT_RIGHT-CLINT_LEFT+1)) return haddr - clint + CLINT_LEFT;
  return 0;
#else
  return haddr - pmem + CONFIG_MBASE;
#endif
}

// uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
// paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#ifdef CONFIG_YSYXSOC
  sram = malloc(CONFIG_SRAMSIZE);
  assert(sram);
  psram = malloc(CONFIG_PSRAMSIZE);
  assert(psram);
  sdram = malloc(CONFIG_SDRAMSIZE);
  assert(sdram);
#endif
#ifdef CONFIG_SOC_BIN
  sram = malloc(CONFIG_SRAMSIZE);
  assert(sram);
  psram = malloc(CONFIG_PSRAMSIZE);
  assert(psram);
  sdram = malloc(CONFIG_SDRAMSIZE);
  assert(sdram);
  uart = malloc(UART_RIGHT-UART_LEFT+1);
  assert(uart);
  clint = malloc(CLINT_RIGHT-CLINT_LEFT+1);
  assert(clint);
#endif
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
#ifdef CONFIG_YSYXSOC
  Log("SRAM area [" FMT_PADDR ", " FMT_PADDR "]", SRAM_LEFT, SRAM_RIGHT);
  Log("PSRAM area [" FMT_PADDR ", " FMT_PADDR "]", PSRAM_LEFT, PSRAM_RIGHT);
  Log("SDRAM area [" FMT_PADDR ", " FMT_PADDR "]", SDRAM_LEFT, SDRAM_RIGHT);
#endif
#ifdef CONFIG_SOC_BIN
  Log("SRAM area [" FMT_PADDR ", " FMT_PADDR "]", SRAM_LEFT, SRAM_RIGHT);
  Log("PSRAM area [" FMT_PADDR ", " FMT_PADDR "]", PSRAM_LEFT, PSRAM_RIGHT);
  Log("SDRAM area [" FMT_PADDR ", " FMT_PADDR "]", SDRAM_LEFT, SDRAM_RIGHT);
#endif
}

void print_paddr_read(paddr_t addr, int len)
{
  printf("PADDR_READ at" FMT_PADDR ", len = %d\n", addr, len);
}

void print_paddr_write(paddr_t addr, int len, word_t data)
{
  printf("PADDR_WRITE at" FMT_PADDR ", len = %d, write data: " FMT_WORD "\n", addr, len, data);
}

word_t paddr_read(paddr_t addr, int len) {
  IFDEF(CONFIG_MTRACE, print_paddr_read(addr, len));
  if (likely(in_pmem(addr))) IFDEF(CONFIG_MTRACE_BIN, mtrace_write(addr, false));
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  IFDEF(CONFIG_MTRACE, print_paddr_write(addr, len, data));
  if (likely(in_pmem(addr))) IFDEF(CONFIG_MTRACE_BIN, mtrace_write(addr, true));
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}

extern void mem_dump() {
  FILE *fp;
  fp = fopen("mem_dump.bin", "wb");
  assert(fp != NULL);
  fwrite(pmem, sizeof(uint8_t), CONFIG_MSIZE, fp);
  fclose(fp);
}
