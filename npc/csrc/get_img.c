#include <stddef.h>
#include <getopt.h>

static char *img_file = NULL;

static int parse_args(int argc, char *argv[])
{
    const struct option table[] = {
        {"get_img", required_argument, NULL, 'i'},
        {0, 0, NULL, 0},
    };
    int o;
    while ((o = getopt_long(argc, argv, "-i:", table, NULL)) != -1)
    {
        switch (o)
        {
        case 'i':
            img_file = optarg;
            return 0;
        default:
            printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
            printf("\t-i,--img=FILE           get img file\n");
            printf("\n");
            exit(0);
        }
    }
    return 0;
}

void init_npcmem(int argc, char *argv[])
{
    parse_args(argc, argv);
}
