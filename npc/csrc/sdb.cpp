#include "common.h"
#include "npc.h"
#include "memory/paddr.h"
#include "reg.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include "Vtop__Dpi.h"
#include "watchpoint.h"
#include "expr.h"

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

Vtop *top;
VerilatedContext *contextp;
VerilatedVcdC *tfp;
char str[1024] = "\0";
static int is_batch_mode = false;


static char *rl_gets()
{
    static char *line_read = NULL;

    if (line_read)
    {
        free(line_read);
        line_read = NULL;
    }

    line_read = readline("(npc) ");

    if (line_read && *line_read)
    {
        add_history(line_read);
    }

    return line_read;
}

static int cmd_c(char *args)
{
    npc_exec(top, contextp, tfp, -1);
    return 0;
}

static int cmd_si(char *args)
{
    int N = (args == NULL) ? 1 : (atoi(args));
    npc_exec(top, contextp, tfp, N);
    return 0;
}

static int cmd_info(char *args)
{
    if (strcmp(args, "r") == 0)
    {
        reg_display();
    }
    else if (strcmp(args, "w") == 0)
    {
        wp_info();
    }
    else
    {
        printf("Unknown argument\n");
    }
    return 0;
}

static int cmd_x(char *args)
{
    int n = atoi(strtok(args, " "));
    char *expr = strtok(NULL, " ");
    uint32_t addr = 0;

    addr = strtoul(expr, NULL, 16);
    for (int i = 0; i < n; i++)
    {
        printf("0x%08x  0x%08x\n", addr, paddr_read(addr));
        addr += 4;
    }
    return 0;
}

static int cmd_p(char *args) {
    printf("cmd_p args: %s\n", args);
    uint32_t res;
    bool *success;
    success = (bool *)malloc(sizeof(bool));
    res = expr(args, success);

    if(success) {
        printf("Result: %u\n", res);
    }
    else {
        printf("Unable to evaluate mathematical expressions.\n");
    }

    free(success);

    return 0;
}

static int cmd_w(char *args) {
    WP *cur = new_wp();
    strcpy(cur->expression, args);
    return 0;
}

static int cmd_d(char *args) {
    int n = atoi(args);
    free_wp(n);
    return 0;
}

static int cmd_q(char *args)
{
    Verilated::gotFinish(true);
    return -1;
}

static int cmd_help(char *args);

static struct
{
    const char *name;
    const char *description;
    int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"si", "Let's the programepause after executing N instructions in a single step. N defaults to 1", cmd_si},
    {"info", "Type r to print the register, type w for status watchpoint information", cmd_info},
    {"x", "x N EXPR, Scanning Memory, Outputs N consecutive 4 bytes starting from EXPR", cmd_x},
    {"p", "p EXPR, Find the value of the expression EXPR", cmd_p},
    {"w", "w EXPR, Watchpoint set", cmd_w},
    {"d", "d N, Delete the monitoring point with serial number N", cmd_d},
    {"q", "Exit NEMU", cmd_q},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args)
{
    /* extract the first argument */
    char *arg = strtok(NULL, " ");
    int i;

    if (arg == NULL)
    {
        /* no argument given */
        for (i = 0; i < NR_CMD; i++)
        {
            printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        }
    }
    else
    {
        for (i = 0; i < NR_CMD; i++)
        {
            if (strcmp(arg, cmd_table[i].name) == 0)
            {
                printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
                return 0;
            }
        }
        printf("Unknown command '%s'\n", arg);
    }
    return 0;
}

void sdb_set_batch_mode()
{
    printf("sdb_set_batch_mode\n");
    is_batch_mode = true;
}

void sdb_mainloop()
{
    if(is_batch_mode)
    {
        cmd_c(NULL);
        return;
    }

    for (char *str; (str = rl_gets()) != NULL;)
    {
        char *str_end = str + strlen(str);

        /* extract the first token as the command */
        char *cmd = strtok(str, " ");
        if (cmd == NULL)
        {
            continue;
        }

        /* treat the remaining string as the arguments,
         * which may need further parsing
         */
        char *args = cmd + strlen(cmd) + 1;
        if (args >= str_end)
        {
            args = NULL;
        }

        int i;
        for (i = 0; i < NR_CMD; i++)
        {
            if (strcmp(cmd, cmd_table[i].name) == 0)
            {
                if (cmd_table[i].handler(args) < 0)
                {
                    printf("cmd_table[%d]\n", );
                    return;
                }
                break;
            }
        }

        if (i == NR_CMD)
        {
            printf("Unknown command '%s'\n", cmd);
        }
    }
}

void init_sdb(Vtop *top_in, VerilatedContext *contextp_in, VerilatedVcdC *tfp_in)
{
    top = top_in;
    contextp = contextp_in;
    tfp = tfp_in;
}
