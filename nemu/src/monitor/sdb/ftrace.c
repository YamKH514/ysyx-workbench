#include <common.h>
#include <elf.h>

typedef struct
{
    char name[64];
    paddr_t addr;
    unsigned char info;
    word_t size;
} Symtab_func;

int func_num = 0;
Symtab_func *funcs = NULL;
int call_deep = 0;

size_t get_elf_header(FILE *file, Elf32_Ehdr *ehdr)
{
    fseek(file, 0, SEEK_SET);
    return fread(ehdr, sizeof(Elf32_Ehdr), 1, file);
}

size_t get_section_header(FILE *file, Elf32_Ehdr *ehdr, Elf32_Shdr **shdr)
{
    *shdr = malloc((ehdr->e_shnum) * sizeof(Elf32_Shdr));
    fseek(file, ehdr->e_shoff, SEEK_SET);
    return fread(*shdr, sizeof(Elf32_Shdr), ehdr->e_shnum, file);
}

size_t get_shstrtab(FILE *file, Elf32_Shdr *shstrhdr, char **shstrtab_name)
{
    *shstrtab_name = malloc(shstrhdr->sh_size);
    fseek(file, shstrhdr->sh_offset, SEEK_SET);
    return fread(*shstrtab_name, 1, shstrhdr->sh_size, file);
}

size_t get_symtab(FILE *file, Elf32_Shdr *symtab_header, Elf32_Sym **symtab)
{
    *symtab = malloc(symtab_header->sh_size);
    fseek(file, symtab_header->sh_offset, SEEK_SET);
    return fread(*symtab, 1, symtab_header->sh_size, file);
}

size_t get_strtab(FILE *file, Elf32_Shdr *strtab_header, char **strtab)
{
    *strtab = malloc(strtab_header->sh_size);
    fseek(file, strtab_header->sh_offset, SEEK_SET);
    return fread(*strtab, 1, strtab_header->sh_size, file);
}

char *get_func_name(Elf32_Sym *symbol, char *strtab)
{
    return &strtab[symbol->st_name];
}

size_t extract_func(FILE *file, Elf32_Shdr *symtab_header, Elf32_Shdr *strtab_header, Symtab_func **funcs)
{
    Elf32_Sym *symtab = NULL;
    assert(get_symtab(file, symtab_header, &symtab) == symtab_header->sh_size);

    char *strtab = NULL;
    assert(get_strtab(file, strtab_header, &strtab) == strtab_header->sh_size);

    int sym_num = symtab_header->sh_size / symtab_header->sh_entsize;
    int func_cnt = 0;

    for(int i = 0; i < sym_num; i++)
    {
        if(ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC)
        {
            func_cnt ++;
        }
    }

    *funcs = malloc(func_cnt * sizeof(Symtab_func));

    int j = 0;
    for(int i = 0; i < sym_num; i++)
    {
        if(ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC)
        {
            Symtab_func *func = &(*funcs)[j++];
            strncpy(func->name, get_func_name(&symtab[i], strtab), sizeof(func->name) - 1);
            (func->name)[sizeof(func->name) - 1] = '\0';
            func->addr = symtab[i].st_value;
            func->info = symtab[i].st_info;
            func->size = symtab[i].st_size;
        }
    }

    free(symtab);
    free(strtab);

    return func_cnt;
}

void parse_elf(const char *elf_file)
{
    FILE *file = fopen(elf_file, "rb");
    assert(file);

    Elf32_Ehdr elf_header;
    assert(get_elf_header(file, &elf_header) == 1);
    assert((elf_header.e_ident[0] == ELFMAG0) &&
            (elf_header.e_ident[1] == ELFMAG1) &&
            (elf_header.e_ident[2] == ELFMAG2) &&
            (elf_header.e_ident[3] == ELFMAG3));

    Elf32_Shdr *section_header = NULL;
    assert(get_section_header(file, &elf_header, &section_header) == elf_header.e_shnum);

    Elf32_Shdr *shstrtab_header = &section_header[elf_header.e_shstrndx];
    char *shstrtab_names = NULL;
    assert(get_shstrtab(file, shstrtab_header, &shstrtab_names) == shstrtab_header->sh_size);

    Elf32_Shdr *symtab_header = NULL, *strtab_header = NULL;
    for(int i = 0; i < elf_header.e_shnum; i++)
    {
        Elf32_Shdr *shdr = &section_header[i];
        const char *shstrtab_name = &shstrtab_names[shdr->sh_name];
        if(strcmp(shstrtab_name, ".symtab") == 0)
        {
            symtab_header = shdr;
        }
        if(strcmp(shstrtab_name, ".strtab") == 0)
        {
            strtab_header = shdr;
        }
    }
    assert(symtab_header);
    assert(strtab_header);

    func_num = extract_func(file, symtab_header, strtab_header, &funcs);

    free(shstrtab_names);
    free(section_header);
    fclose(file);
}

int find_func(word_t dnpc)
{
    for(int i = 0; i < func_num; i++)
    {
        if(funcs[i].addr == dnpc) return i;
    }
    return -1;
}

void ftrace_call(word_t pc, word_t dnpc)
{
    assert(funcs != NULL);

    ++call_deep;
    // if(call_deep <=2) return;

    int i = find_func(dnpc);
    printf(FMT_PADDR ": %*scall [%s@" FMT_PADDR "]\n", pc, call_deep * 2, "", i>=0?funcs[i].name:"???",dnpc);
}

void ftrace_ret(word_t pc, word_t dnpc)
{
    assert(funcs != NULL);

    --call_deep;
    // if(call_deep <= 2) return;

    int i = find_func(dnpc);
    printf(FMT_PADDR ": %*scall [%s@]\n", pc, call_deep * 2, "", i>=0?funcs[i].name:"???");
}

void ftrace_end()
{
    free(funcs);
}
