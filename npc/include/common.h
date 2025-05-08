#ifndef COMMON_H__
#define COMMON_H__

#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <getopt.h>
#include <stdio.h>

void init_npcmem(int argc, char *argv[]);

void init_mem(uint32_t *img, long size);
uint32_t mem_read(uint32_t pc);
void mem_end();

int is_exit_status_bad();

#endif
