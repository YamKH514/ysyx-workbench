#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__

#define NR_WP 32

#include <stdbool.h>

typedef struct watchpoint {
    int NO;
    struct watchpoint *next;
    char expression[1000];
    word_t old_value;
  
    /* TODO: Add more members if necessary */
  
  } WP;

  WP* new_wp();
  void free_wp(WP *wp);
  bool wp_scan();

#endif