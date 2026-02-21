#include "common.h"
#include "memory/mtrace.h"

FILE *mt_fp = NULL;

void init_mtrace(const char *mt_file)
{
    mt_fp = stdout;
    if (mt_file != NULL)
    {
        FILE *fp = fopen(mt_file, "wb");
        Assert(fp, "Can not open '%s'", mt_file);
        mt_fp = fp;
    }
    Log("Log is written to %s", mt_file ? mt_file : "stdout");
}

void mtrace_write(uint32_t addr, bool is_write, bool is_inst)
{
    Trace trace = {addr, is_write, is_inst};
    fwrite(&trace, sizeof(Trace), 1, mt_fp);
    fflush(mt_fp);
}
