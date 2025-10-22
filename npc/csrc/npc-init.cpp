#include "common.h"
#include "memory/paddr.h"
#include "ftrace.h"
#include "npc-init.h"
#include "disasm.h"
#include "difftest-def.h"
#include "sdb.h"
#include "cpu.h"
#include "Vtop__Dpi.h"

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
    while ((o = getopt_long(argc, argv, "-bl:d:e:", table, NULL)) != -1)
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
        case 1:
            img_file = optarg;
            return 0;
        default:
            printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
            printf("\t-b,--batch              run with batch mode\n");
            printf("\t-l,--log=FILE           output log to FILE\n");
            printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
            printf("\t-e,--elf=FILE           get ELF file\n");
            printf("\n");
            exit(0);
        }
    }
    return 0;
}

void reset_npc(Vtop* top, VerilatedContext* contextp, VerilatedVcdC* tfp)
{
    if (!npc_state.inited)
    {
        top->rst = 1;
        contextp->timeInc(1);
        top->clk = 0;
        top->eval();
        tfp->dump(contextp->time());
        contextp->timeInc(1);
        top->clk = 1;
        top->eval();
        tfp->dump(contextp->time());
        contextp->timeInc(1);
        printf("inited pc = 0x%08x\n", top->pc);
        npc_state.halt_pc = top->pc;
        npc_state.inited = true;
        cpu.pc = top->pc;
        svSetScope(svGetScopeFromName("TOP.top.u_GPR.u_RegisterFile"));
        get_gpr(cpu.gpr);
        svSetScope(svGetScopeFromName("TOP.top.u_CSR"));
        get_csr((int *)(&cpu.csr));
    }
}

void init_npc(int argc, char *argv[], Vtop* top, VerilatedContext* contextp, VerilatedVcdC* tfp)
{
    parse_args(argc, argv);

    init_log(log_file);

#ifdef CONFIG_FTRACE
    parse_elf(elf_file);
#endif

    reset_npc(top, contextp, tfp);

    init_mem();

    long img_size = load_img();

    init_difftest(diff_so_file, img_size, difftest_port);

    init_sdb(top, contextp, tfp);

    init_disasm();

#ifdef CONFIG_DIFFTEST
    difftest_step(npc_state.halt_pc);
#endif

    Log("init_npc has done.");
}
