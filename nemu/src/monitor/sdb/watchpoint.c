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

#include "sdb.h"
#include "watchpoint.h"

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;
static int free_wp_num = 32;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].expression[0] = '\0';
    wp_pool[i].old_value = 0;
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP* new_wp() {
  if(free_wp_num < 1) assert(0);

  WP *temp = head;
  head = free_;
  free_ = free_->next;
  head->next = temp;

  free_wp_num --;

  return head;
}

void free_wp(int n){
  if(free_wp_num >= 32) {
    printf("Watchpoints that are not being used right now\n");
    return;
  }
  bool is_wp_used = false;
  WP *pre = NULL;
  WP *current = head;

  while (current != NULL) {
    if(current->NO == n) {
      is_wp_used = true;
      break;
    }
    pre = current;
    current = current->next;
  }
  
  if(is_wp_used == false) {
    printf("NO.%d wp not be used!\n", n);
    return;
  }

  current->expression[0] = '\0';
  current->old_value = 0;

  pre->next = current->next;
  current->next = free_;
  free_ = current;

  free_wp_num ++;
}

bool wp_scan() {
  if(head == NULL) return false;
  bool changed = false;
  WP *current = head;

  bool *success;
  success = (bool *)malloc(sizeof(bool));
  word_t res = expr(current->expression, success);

  do
  {
    if(current->old_value != res) {
      printf("wp %d: %s changed\n\n", current->NO, current->expression);
      printf("Old value = %u\n", current->old_value);
      printf("New value = %u\n", res);
      current->old_value = res;
      changed = true;
    }
  } while (current->next != NULL);
  
  return changed;
}

void wp_info() {
  if(head == NULL) {
    printf("Watchpoints that are not being used right now\n");
    return;
  }

  printf("NUM     What\n");
  WP *cur = head;
  while (cur != NULL)
  {
    printf("%-8d%s\n", cur->NO, cur->expression);
    cur = cur->next;
  }
}
