#include "common.h"
#include "debug.h"
#include "perf-cnt.hpp"

static const char *module_lut[__MODULE_CNT_NUM] = {
    [IFU] = "IFU",
    [EXU] = "EXU",
    [LSU] = "LSU",
};

void Perf_cnt::module_add(MODULE_ENUM module) {
    this->__module[module] ++;
    this->__total_module ++;
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

unsigned long long Perf_cnt::total_module() {
    return this->__total_module;
}

void Perf_cnt::print_module_called(MODULE_ENUM module) {
    Log("%s called %llu", module_lut[module], this->__module[module]);
}

Perf_cnt perf_cnt;
