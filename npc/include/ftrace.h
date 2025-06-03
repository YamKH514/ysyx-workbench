#ifndef FTRACE_H__
#define FTRACE_H__

void parse_elf(const char *elf_file);
void ftrace_call(uint32_t pc, uint32_t dnpc);
void ftrace_ret(uint32_t pc);

#endif
