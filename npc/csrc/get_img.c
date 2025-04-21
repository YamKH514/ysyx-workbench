#include <stddef.h>
#include <getopt.h>
#include <stdio.h>
#include <stdint.h>

static char *img_file = NULL;

static long load_img() {
    if (img_file == NULL) {
      Log("No image is given. Use the default build-in image.");
      return 4096; // built-in image size
    }
  
    FILE *fp = fopen(img_file, "rb");
    Assert(fp, "Can not open '%s'", img_file);
  
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
  
    Log("The image is %s, size = %ld", img_file, size);
  
    uint32_t *img_bin = (uint32_t *)malloc(size);
    fseek(fp, 0, SEEK_SET);
    int ret = fread(img_bin, size, 1, fp);
    assert(ret == 1);

  
    fclose(fp);
    return size;
  }

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

    load_img();
}
