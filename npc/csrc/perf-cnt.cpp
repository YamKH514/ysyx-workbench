#include "common.h"
#include "perf-cnt.hpp"

// perf_cnt_struct perf_cnt = {0};

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

Perf_cnt perf_cnt;

// void perf_cnt_module_add(bool cond, MODULE_ENUM module_name) {
//     if(cond) {
//         perf_cnt.module[module_name] ++;
//         perf_cnt.module_total_call ++;
//     }
// }

// void perf_cnt_inst_add(INST_TYPE_ENUM inst_type, int num) {
//     perf_cnt.inst[inst_type].num ++;
//     perf_cnt.inst[inst_type].cyc += (unsigned long long)num;
//     perf_cnt.total_inst.num ++;
//     perf_cnt.total_inst.cyc += (unsigned long long)num;
// }
