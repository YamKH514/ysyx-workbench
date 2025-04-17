#include <common.h>
#include <cpu/decode.h>
#include <isa.h>

#define MAX_IRINGBUF 64

typedef struct 
{
    word_t pc;
    word_t snpc;
    uint32_t inst;
} itrackNode;

itrackNode iringbuf[MAX_IRINGBUF];
int p_cur = 0;
int is_full = 0;

void iringbuf_get_inst(Decode *s)
{
    iringbuf[p_cur].pc = s->pc;
    iringbuf[p_cur].snpc = s->snpc;
    iringbuf[p_cur].inst = s->isa.inst;
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
        int ilen = iringbuf[i].snpc - iringbuf[i].pc;
        int j;
        uint8_t *inst = (uint8_t *)&iringbuf[i].inst;
#ifdef CONFIG_ISA_x86
        for(j = 0; j < ilen; j ++)
#else
        for(j = ilen - 1; j >= 0; j ++)
#endif
        {
            p += snprintf(p, 4, "%02x", inst[j]);
        }
        int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
        int space_len = ilen_max - ilen;
        if (space_len < 0) space_len = 0;
        space_len = space_len * 3 + 1;
        memset(p, ' ', space_len);
        p += space_len;

        disassemble(p, buf + sizeof(buf) - p,
            MUXDEF(CONFIG_ISA_x86, iringbuf[i].snpc, iringbuf[i].pc), (uint8_t *)&iringbuf[i].inst, ilen);
        
        if((i + 1) % MAX_IRINGBUF == end)
        {
            printf(ANSI_FG_RED);
        }
        puts(buf);
    } while ((i = (i + 1) % MAX_IRINGBUF) != end);
    puts(ANSI_NONE);
}