#ifndef MTRACE_H__
#define MTRACE_H__

#include "common.h"

typedef struct
{
    uint32_t addr;
    bool is_write;
    bool is_inst;
} Trace;

void init_mtrace(const char *mt_file);
void mtrace_write(uint32_t addr, bool is_write, bool is_inst);

#endif