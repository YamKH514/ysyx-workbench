#include "common.h"
#include "debug.h"
#include "perf-cnt.hpp"

static const char *module_lut[__MODULE_CNT_NUM] = {
    [IFU] = "IFU",
    [EXU] = "EXU",
    [LSU] = "LSU",
};

static const char *inst_type_lut[__INST_TYPE_NUM] = {
    [i] = "TYPE_I",
    [s] = "TYPE_S",
    [b] = "TYPE_B",
    [u] = "TYPE_U",
    [j] = "TYPE_J",
    [r] = "TYPE_R",
};

void Perf_cnt::module_add(MODULE_ENUM module) {
    this->__module[module] ++;
}

void Perf_cnt::inst_add(INST_TYPE_ENUM inst_type, int num) {
    this->__inst[inst_type].num ++;
    this->__inst[inst_type].cyc += (unsigned long long)num;
    this->__total_inst.num ++;
    this->__total_inst.cyc += (unsigned long long)num;
}

double Perf_cnt::inst_proportion(INST_TYPE_ENUM inst_type) {
    return (double)this->__inst[inst_type].num/(double)this->__total_inst.num;
}

double Perf_cnt::inst_average(INST_TYPE_ENUM inst_type) {
    return (double)this->__inst[inst_type].cyc/(double)this->__inst[inst_type].num;
}

unsigned long long Perf_cnt::module(MODULE_ENUM module) {
    return this->__module[module];
}

void Perf_cnt::print_module_called(MODULE_ENUM module) {
    Log("%s called %llu", module_lut[module], this->__module[module]);
}

void Perf_cnt::print_inst_info(INST_TYPE_ENUM inst_type) {
    Log("%s inst was executed %d times, which is approximately %f of all instructions,\n    and on average, it required %f cycles to execute.",
        inst_type_lut[inst_type],
        this->__inst[inst_type].num,
        (double)(this->__inst[inst_type].num)/(double)(this->__total_inst.num),
        (double)(this->__inst[inst_type].cyc)/(double)(this->__inst[inst_type].num));
}

Perf_cnt perf_cnt;
