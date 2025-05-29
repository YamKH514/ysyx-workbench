#include "common.h"
#include "mem.h"
#include "npc-init.h"
#include "disasm.h"

static char *log_file = NULL;
static char *img_file = NULL;
static char *elf_file = NULL;

void load_img()
{
    if (img_file == NULL)
    {
        Log("No image is given.\n");
    }

    FILE *fp = fopen(img_file, "rb");
    assert(fp);

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    Log("The image is %s, size = %ld", img_file, size);

    uint32_t *img_bin = (uint32_t *)malloc(size);
    fseek(fp, 0, SEEK_SET);
    int ret = fread(img_bin, size, 1, fp);
    assert(ret == 1);
    init_mem(img_bin, size);

    fclose(fp);
}

static int parse_args(int argc, char *argv[])
{
    const struct option table[] = {
        {"log", required_argument, NULL, 'l'},
        {"elf", required_argument, NULL, 'e'},
        {0, 0, NULL, 0},
    };
    int o;
    while ((o = getopt_long(argc, argv, "-l:i:", table, NULL)) != -1)
    {
        switch (o)
        {
        case 'l':
            log_file = optarg;
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

    load_img();

    init_disasm();
}
