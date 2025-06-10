#include <dlfcn.h>

#include "common.h"
#include "utils.h"
#include "memory/paddr.h"
#include "reg.h"
#include "difftest-def.h"

void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

#ifdef CONFIG_DIFFTEST

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;

void init_difftest(char *ref_so_file, long img_size, int port)
{
  assert(ref_so_file != NULL);

  NPCState npc_state_init = npc_state;
  npc_state_init.halt_pc = 0x80000000;

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  if (!handle)
  assert(handle);

  ref_difftest_memcpy = (void (*)(uint32_t, void *, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void *, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.",
      ref_so_file);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&npc_state_init, DIFFTEST_TO_REF);
}

bool difftest_checkregs(NPCState *ref_r, uint32_t pc)
{
  int reg_num = ARRLEN(npc_state.gpr_value);
  for (int i = 0; i < reg_num; i++)
  {
    if (ref_r->gpr_value[i] != npc_state.gpr_value[i])
    {
      printf("Difftest: Inconsistent register values, pc = 0x%x\n", pc);
      printf("wrong ref reg: reg[%d] val: 0x%08x\n", i, ref_r->gpr_value[i]);
      printf("wrong dut reg: reg[%d] val: 0x%08x\n", i, npc_state.gpr_value[i]);
      return false;
    }
  }
  if (ref_r->halt_pc != npc_state.halt_pc)
  {
    printf("Difftest: Inconsistent register values, pc = 0x%x\n", pc);
    return false;
  }

  return true;
}

static void checkregs(NPCState *ref, uint32_t pc)
{
  if (!difftest_checkregs(ref, pc))
  {
    npc_state.halt_pc = pc;
    reg_display();
  }
}

void difftest_step(uint32_t pc)
{
  NPCState ref_r;
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
  
  printf("NPC regs:\n");
  checkregs(&ref_r, pc);
  printf("nemu pc: 0x%08x\n", ref_r.halt_pc);
  ref_difftest_exec(1);
}

#else
void init_difftest(char *ref_so_file, long img_size, int port) {}
#endif