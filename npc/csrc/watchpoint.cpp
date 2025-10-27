#include "sdb.h"
#include "watchpoint.h"
#include "expr.h"

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;
static int free_wp_num = 32;

void init_wp_pool()
{
    int i;
    for (i = 0; i < NR_WP; i++)
    {
        wp_pool[i].NO = i;
        wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
        wp_pool[i].expression[0] = '\0';
        wp_pool[i].old_value = 0;
    }

    head = NULL;
    free_ = wp_pool;
}

WP *new_wp()
{
    if (free_wp_num < 1)
        assert(0);

    WP *temp = head;
    head = free_;
    free_ = free_->next;
    head->next = temp;

    free_wp_num--;

    return head;
}

void free_wp(int n)
{
    if (free_wp_num >= 32)
    {
        printf("Watchpoints that are not being used right now\n");
        return;
    }
    bool is_wp_used = false;
    WP *pre = NULL;
    WP *need_del = NULL;
    WP *current = head;

    while (current != NULL)
    {
        if (current->NO == n)
        {
            is_wp_used = true;
            need_del = current;
            break;
        }
        pre = current;
        current = current->next;
    }

    if (is_wp_used == false)
    {
        printf("NO.%d wp not be used!\n", n);
        return;
    }

    need_del->expression[0] = '\0';
    need_del->old_value = 0;

    if (pre != NULL)
    {
        pre->next = need_del->next;
    }
    else
    {
        head = need_del->next;
    }
    need_del->next = free_;
    free_ = need_del;

    free_wp_num++;
}

bool wp_scan()
{
    if (head == NULL)
        return false;
    bool changed = false;
    WP *current = head;

    bool *success;
    success = (bool *)malloc(sizeof(bool));
    uint32_t res = expr(current->expression, success);

    while (current != NULL)
    {
        if (current->old_value != res)
        {
            printf("wp %d: %s changed\n\n", current->NO, current->expression);
            printf("Old value = %u\n", current->old_value);
            printf("New value = %u\n\n", res);
            current->old_value = res;
            changed = true;
        }
        current = current->next;
    }

    free(success);

    return changed;
}

void wp_info()
{
    if (head == NULL)
    {
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
