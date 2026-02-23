#ifndef DCACHE_HPP__
#define DCACHE_HPP__

#include <cstdint>
#include <vector>

#define ADDR_BITS 32

typedef struct
{
    uint32_t tag;
    uint32_t index;
    uint32_t offset;
    bool valid;
} DCache_line;

class DCache
{
private:
    uint32_t c_m;
    uint32_t c_n;
    uint32_t cl_w;
    uint32_t cl_n;
    std::vector<DCache_line> cache_line;

    void split_addr(uint32_t addr, DCache_line &line)
    {
        line.offset = addr & ((1u << c_m) - 1);
        line.index = (addr >> c_m) & ((1u << c_n) - 1);
        line.tag = addr >> (c_m + c_n);
    }

public:
    double ave_misstime;

    DCache(uint32_t m, uint32_t n);
    bool access(uint32_t addr, bool is_write);
    void print_config() const;
};

#endif
