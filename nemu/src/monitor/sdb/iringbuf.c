#include <common.h>

#define MAX_IRINGBUF 64

typedef struct 
{
    word_t pc;
    uint32_t inst;
} itrackNode;

itrackNode iringbuf[MAX_IRINGBUF];
int p_cur = 0;
int is_full = 0;

void iringbuf_get_inst(word_t pc, uint32_t inst)
{
    iringbuf[p_cur].pc = pc;
    iringbuf[p_cur].inst = inst;
    p_cur = (p_cur + 1) % MAX_IRINGBUF;
    is_full = is_full || (p_cur == 0);
}

void iringbuf_print()
{
    if((p_cur == 0) && (is_full == 0)) return;

    int i = (is_full == 1) ? p_cur : 0;
    int end = p_cur;
    void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
    char buf[128];
    char *p = NULL;
    do
    {
        p = buf;
        p += snprintf(p, sizeof(buf), FMT_WORD ":", iringbuf[i].pc);
    } while ((i = (i + 1) % MAX_IRINGBUF) != end);
}