#include "icache.hpp"
#include <iostream>
#include <stdexcept>

#define AVE_MT_ONCE 32.87
#define AVE_MT_MUL_TRANSFER 7.00

Cache::Cache(uint32_t m, uint32_t n)
{
    if (m + n > ADDR_BITS)
    {
        throw std::invalid_argument("m + n must be <= 32 for 32-bit address space");
    }
    if (m == 0)
    {
        throw std::invalid_argument("m must be > 0 (need at least 1 byte per cache line)");
    }
    if (n == 0)
    {
        throw std::invalid_argument("n must be > 0 (need at least 1 cache line)");
    }

    c_m = m;
    c_n = n;
    cl_w = 8 * (1u << c_m);
    cl_n = 1u << c_n;
    cache_line = std::vector<Cache_line>(cl_n);
    if (m == 2) ave_misstime = AVE_MT_ONCE; // When m = 2
    else ave_misstime = AVE_MT_ONCE + (cl_w / 16 - 1) * AVE_MT_MUL_TRANSFER; // When m > 2

    for (auto &line : cache_line)
    {
        line.valid = false;
    }
}

bool Cache::check_hit(uint32_t pc)
{
    Cache_line cache_line = {};
    split_pc(pc, cache_line);

    if ((this->cache_line[cache_line.index].tag == cache_line.tag) &&
        (this->cache_line[cache_line.index].valid == true))
    {
        return true;
    }
    else
    {
        this->cache_line[cache_line.index] = cache_line;
        this->cache_line[cache_line.index].valid = true;
        return false;
    }
}

void Cache::print_config() const
{
    printf("ICache Configuration:\n");
    printf("  Address bits: %u\n", ADDR_BITS);
    printf("  m: %u\n", c_m);
    printf("  n: %u\n", c_n);
    printf("  Cache line size: %u bytes\n", (1u << c_m));
    printf("  Cache line count: %u\n", cl_n);
    printf("  Total cache size: %u bytes\n", (1u << c_m) * cl_n);
}
