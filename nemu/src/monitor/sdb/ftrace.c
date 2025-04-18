#include <common.h>
#include <elf.h>

void parse_elf(const char *elf_file)
{
    FILE *file = fopen(elf_file, "rb");
    assert(file);

    

    fclose(file);
}
