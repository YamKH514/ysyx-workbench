#include "common.h"
#include "perf-cnt.h"

perf_cnt_struct perf_cnt = {0};

void perf_cnt_module_add(bool cond, MODULE_ENUM module_name) {
    if(cond) perf_cnt.module[module_name] ++;
}

void perf_cnt_inst_add(INST_TYPE_ENUM inst_type, int num) {
    perf_cnt.inst[inst_type].num ++;
    perf_cnt.inst[inst_type].cyc += (unsigned long long)num;
}
