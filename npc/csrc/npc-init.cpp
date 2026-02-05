#include "common.h"
#include "memory/paddr.h"
#include "ftrace.h"
#include "npc-init.h"
#include "disasm.h"
#include "difftest-def.h"
#include "sdb.h"
#include "cpu.h"

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static char *elf_file = NULL;
static int difftest_port = 1234;
PLATFORM_ENUM platform = npc;

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
        {"platform",required_argument, NULL, 'p'},
        {0, 0, NULL, 0},
    };
    int o;
    while ((o = getopt_long(argc, argv, "-bl:d:e:p:", table, NULL)) != -1)
    {
        switch (o)
        {
        case 'b':
#ifdef CONFIG_BATCH_MODE
            sdb_set_batch_mode();
#endif
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
        case 'p':
            printf("PLATFORM: %c\n", optarg[0]);
            platform = (PLATFORM_ENUM)optarg[0];
            break;
        case 1:
            img_file = optarg;
            return 0;
        default:
            printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
            printf("\t-b,--batch              run with batch mode\n");
            printf("\t-l,--log=FILE           output log to FILE\n");
            printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
            printf("\t-e,--elf=FILE           get ELF file\n");
            printf("\t-p,--platform=PLATFORM  set platform used\n");
            printf("\n");
            exit(0);
        }
    }
    return 0;
}

void init_npc(int argc, char *argv[], VysyxSoCFull *top, VerilatedContext *contextp, VerilatedVcdC *tfp)
{
    parse_args(argc, argv);

    init_log(log_file);

#ifdef CONFIG_FTRACE
    parse_elf(elf_file);
#endif

    init_mem();

    long img_size = load_img();

    cpu_reset(10, top, contextp, tfp);

    init_difftest(diff_so_file, img_size, difftest_port);

    init_sdb(top, contextp, tfp);

    init_disasm();

    if (platform == npc) printf("NPC\n");
    else if (platform == ysyxSoC) printf("ysyxSoC\n");

    Log("init_npc has done.");
}
