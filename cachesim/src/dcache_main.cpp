#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include "dcache.hpp"

#define FLASH_BASE 0x30000000
#define FLASH_SIZE 0x1000000
#define SRAM_BASE 0x0f000000
#define SRAM_SIZE 0x2000
#define PSRAM_BASE 0x80000000
#define PSRAM_SIZE 0x400000
#define SDRAM_BASE 0xa0000000
#define SDRAM_SIZE 0x8000000

#define READ_MISS_CYCLES 44.0
#define WRITE_MISS_CYCLES 14.0

typedef struct
{
    uint32_t addr;
    uint8_t is_write;
    uint8_t pad[3];
} Trace;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <m> <n>\n", argv[0]);
        return 1;
    }

    uint32_t m = atoi(argv[1]);
    uint32_t n = atoi(argv[2]);

    try
    {
        static_assert(sizeof(Trace) == 8, "Trace record size mismatch");

        DCache cache(m, n);
        cache.print_config();
        printf("\n");

        FILE *mt_fp;
        mt_fp = popen("bzcat mtrace-log.bz2", "r");
        assert(mt_fp != NULL);

        FILE *pc_fp;
        pc_fp = popen("bzcat pc-only.bin.bz2", "r");
        assert(pc_fp != NULL);

        Trace trace = {};
        uint32_t pc = 0;
        size_t read_count = 0;
        size_t write_count = 0;
        size_t read_hit = 0;
        size_t read_miss = 0;
        size_t write_hit = 0;
        size_t write_miss = 0;

        while (fread(&trace, sizeof(trace), 1, mt_fp) == 1)
        {
            bool pc_valid = (fread(&pc, sizeof(pc), 1, pc_fp) == 1);
            bool bypass_pc = pc_valid && (trace.addr == pc);
            bool bypass_sram = (SRAM_BASE <= trace.addr) && (trace.addr < SRAM_BASE + SRAM_SIZE);
            if (bypass_pc || bypass_sram)
            {
                continue;
            }
            if ((SDRAM_BASE <= trace.addr) && (trace.addr < SDRAM_BASE + SDRAM_SIZE))
            {
                bool is_write = (trace.is_write != 0);
                bool hit = cache.access(trace.addr, is_write);

                if (is_write)
                {
                    if (hit)
                        write_hit++;
                    else
                        write_miss++;
                    write_count++;
                }
                else
                {
                    if (hit)
                        read_hit++;
                    else
                        read_miss++;
                    read_count++;
                }
            }
        }

        size_t total_access = read_count + write_count;
        size_t total_hit = read_hit + write_hit;
        size_t total_miss = read_miss + write_miss;
        double total_miss_time = read_miss * READ_MISS_CYCLES + write_miss * WRITE_MISS_CYCLES;

        printf("\nResults:\n");
        printf("  Total accesses: %zu\n", total_access);
        printf("  Reads: %zu (hit %zu, miss %zu)\n", read_count, read_hit, read_miss);
        printf("  Writes: %zu (hit %zu, miss %zu)\n", write_count, write_hit, write_miss);
        if (read_count > 0)
        {
            printf("  Read Hit rate: %0.2f%%\n",
                   (double)read_hit / (double)read_count * 100.00);
        }
        if (write_count > 0)
        {
            printf("  Write Hit rate: %0.2f%%\n",
                   (double)write_hit / (double)write_count * 100.00);
        }
        if (total_access > 0)
        {
            printf("  DCache Hit rate: %0.2f%%, Total Miss Time: %0.2f\n",
                   (double)total_hit / (double)total_access * 100.00,
                   total_miss_time);
        }

        pclose(mt_fp);
        pclose(pc_fp);
        return 0;
    }
    catch (const std::exception &e)
    {
        fprintf(stderr, "Error: %s\n", e.what());
        return 1;
    }
}
