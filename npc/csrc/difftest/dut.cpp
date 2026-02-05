#include <dlfcn.h>

#include "common.h"
#include "utils.h"
#include "memory/paddr.h"
#include "reg.h"
#include "difftest-def.h"
#include "cpu.h"

void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

#ifdef CONFIG_DIFFTEST

#define MAX_SKIP_NUM 16
static bool is_skip_ref = false;

void difftest_skip_ref(){
  is_skip_ref = true;
}

void init_difftest(char *ref_so_file, long img_size, int port)
{
  assert(ref_so_file != NULL);

  CPU_state cpu_init = cpu;
#ifdef PLATFORM_YSYXSOC
  cpu_init.pc = CONFIG_MBASE;
#else
  cpu_init.pc = CONFIG_NPC_PMEMBASE;
#endif
  cpu_init.csr.mstatus = 0x00001800;

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
  ref_difftest_regcpy(&cpu_init, DIFFTEST_TO_REF);
}

bool difftest_checkregs(CPU_state*ref_r, uint32_t pc)
{
  int reg_num = ARRLEN(cpu.gpr);
  for (int i = 0; i < reg_num; i++)
  {
    if (ref_r->gpr[i] != cpu.gpr[i])
    {
      printf("Difftest: Inconsistent register values, pc = 0x%08x\n", pc);
      printf("    ref reg[%d] val: 0x%08x\n", i, ref_r->gpr[i]);
      printf("    dut reg[%d] val: 0x%08x\n", i, cpu.gpr[i]);
      return false;
    }
  }
  if (ref_r->pc != cpu.pc)
  {
    printf("Difftest: Inconsistent PC register values, pc = 0x%08x\n", pc);
    printf("ref: 0x%08x, dut: 0x%08x\n", ref_r->pc, cpu.pc);
    return false;
  }
  if(ref_r->csr.mepc != cpu.csr.mepc)
  {
    printf("Difftest: Inconsistent MEPC register values, pc = 0x%08x\n", pc);
    printf("ref: 0x%08x, dut: 0x%08x\n", ref_r->csr.mepc, cpu.csr.mepc);
    return false;
  }
  if(ref_r->csr.mcause != cpu.csr.mcause)
  {
    printf("Difftest: Inconsistent MCAUSE register values, pc = 0x%08x\n", pc);
    printf("ref: 0x%08x, dut: 0x%08x\n", ref_r->csr.mcause, cpu.csr.mcause);
    return false;
  }
  if(ref_r->csr.mtvec != cpu.csr.mtvec)
  {
    printf("Difftest: Inconsistent MTVEC register values, pc = 0x%08x\n", pc);
    printf("ref: 0x%08x, dut: 0x%08x\n", ref_r->csr.mtvec, cpu.csr.mtvec);
    return false;
  }
  if(ref_r->csr.mstatus != cpu.csr.mstatus)
  {
    printf("Difftest: Inconsistent MSTATUS register values, pc = 0x%08x\n", pc);
    printf("ref: 0x%08x, dut: 0x%08x\n", ref_r->csr.mstatus, cpu.csr.mstatus);
    return false;
  }

  return true;
}

static void checkregs(CPU_state *ref, uint32_t pc)
{
  if (!difftest_checkregs(ref, pc))
  {
    npc_state = {.state = NPC_ABORT, .halt_pc = pc};
    reg_display();
  }
}

void difftest_step(uint32_t pc)
{
  CPU_state ref_r;

  if(is_skip_ref)
  {
    ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
    is_skip_ref = false;
    return;
  }

  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  checkregs(&ref_r, pc);
}

#else
void init_difftest(char *ref_so_file, long img_size, int port) {}
#endif