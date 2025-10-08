#include "common.h"
#include "memory/paddr.h"
#include "ftrace.h"
#include "npc-init.h"
#include "disasm.h"
#include "difftest-def.h"
#include "sdb.h"

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static char *elf_file = NULL;
static int difftest_port = 1234;

static long load_img()
{
    Assert(img_file, "No image is given.");

    FILE *fp = fopen(img_file, "rb");
    Assert(fp, "Can not open '%s'", img_file);

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    Log("The image is %s, size = %ld", img_file, size);

    fseek(fp, 0, SEEK_SET);
    int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
    assert(ret == 1);

    fclose(fp);
    return size;
}

static int parse_args(int argc, char *argv[])
{
    const struct option table[] = {
        {"batch",   no_argument      , NULL, 'b'},
        {"log",     required_argument, NULL, 'l'},
        {"diff",    required_argument, NULL, 'd'},
        {"elf",     required_argument, NULL, 'e'},
        {0, 0, NULL, 0},
    };
    int o;
    while ((o = getopt_long(argc, argv, "-l:d:e:", table, NULL)) != -1)
    {
        switch (o)
        {
        case 'b':
            sdb_set_batch_mode();
            break;
        case 'l':
            log_file = optarg;
            break;
        case 'd':
            diff_so_file = optarg;
            break;
        case 'e':
            elf_file = optarg;
            break;
        case 1:
            img_file = optarg;
            return 0;
        default:
            printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
            printf("\t-l,--log=FILE           output log to FILE\n");
            printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
            printf("\t-e,--elf=FILE           get ELF file\n");
            printf("\n");
            exit(0);
        }
    }
    return 0;
}

void init_npc(int argc, char *argv[])
{
    parse_args(argc, argv);

    init_log(log_file);

#ifdef CONFIG_FTRACE
    parse_elf(elf_file);
#endif

    init_mem();

    long img_size = load_img();

    init_difftest(diff_so_file, img_size, difftest_port);

    init_disasm();

    Log("init_npc has done.");
}
