#ifndef __MEMORY_MTRACE_H__
#define __MEMORY_MTRACE_H__

#include <common.h>

typedef struct
{
    uint32_t addr;
    bool is_write;
} Trace;

void init_mtrace(const char *mt_file);
void mtrace_write(uint32_t addr, bool is_write);

#endif