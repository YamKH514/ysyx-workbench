#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__

#define NR_WP 32

#include "common.h"

typedef struct watchpoint
{
    int NO;
    struct watchpoint *next;
    char expression[1000];
    uint32_t old_value;
} WP;

void init_wp_pool();
WP *new_wp();
void free_wp(int n);
bool wp_scan();
void wp_info();

#endif