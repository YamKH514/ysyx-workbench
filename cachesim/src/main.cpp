#include <iostream>
#include <cassert>
#include <cstdlib>
#include "cache.hpp"

#define SDRAM_BASE 0xa0000000
#define SDRAM_SIZE 0x8000000

int main(int argc, char *argv[])
{
    uint32_t m = atoi(argv[1]);
    uint32_t n = atoi(argv[2]);

    try
    {
        Cache cache(m, n);
        cache.print_config();
        printf("\n");

        FILE *fp;
        fp = popen("bzcat pc-only.bin.bz2", "r");
        assert(fp != NULL);

        uint32_t pc;
        size_t count = 0;
        size_t cache_hit = 0;
        size_t cache_miss = 0;

        while (fread(&pc, sizeof(pc), 1, fp) == 1)
        {
            if ((SDRAM_BASE <= pc) && (pc < SDRAM_BASE + SDRAM_SIZE))
            {
                if (cache.check_hit(pc))
                    cache_hit++;
                else
                    cache_miss++;
                count++;
            }
        }

        printf("\nResults:\n");
        printf("  Total accesses: %zu\n", count);
        printf("  Cache hits: %zu\n", cache_hit);
        printf("  Cache misses: %zu\n", cache_miss);
        printf("  ICache Hit rate: %0.2f%%, Total Miss Time: %0.2f\n",
            (double)cache_hit / (double)(cache_hit + cache_miss) * 100.00, cache.ave_misstime * cache_miss * 4);

        pclose(fp);
        return 0;
    }
    catch (const std::exception &e)
    {
        fprintf(stderr, "Error: %s\n", e.what());
        return 1;
    }
}
