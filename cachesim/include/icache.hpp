#ifndef ICACHE_HPP__
#define ICACHE_HPP__

#include <cstdint>
#include <vector>

#define ADDR_BITS 32

typedef struct
{
    uint32_t tag;
    uint32_t index;
    uint32_t offset;
    bool valid;
} Cache_line;

class Cache
{
private:
    uint32_t c_m;
    uint32_t c_n;
    uint32_t cl_w;
    uint32_t cl_n;
    std::vector<Cache_line> cache_line;

    void split_pc(uint32_t pc, Cache_line &cache_line)
    {
        cache_line.offset = pc & ((1u << c_m) - 1);
        cache_line.index = (pc >> c_m) & ((1u << c_n) - 1);
        cache_line.tag = pc >> (c_m + c_n);
    }

public:
    double ave_misstime;

    Cache(uint32_t m, uint32_t n);
    bool check_hit(uint32_t pc);
    void print_config() const;
};

#endif