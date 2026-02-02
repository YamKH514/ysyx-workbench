#include "common.h"
#include "perf-cnt.h"

perf_cnt_struct perf_cnt = {0};

void perf_cnt_module_add(bool cond, MODULE_ENUM module) {
    if(cond) perf_cnt.module_cnt[module] ++;
}

void perf_cnt_inst_add(bool cond, INST_TYPE_ENUM inst_type) {
    if(cond) perf_cnt.inst_cnt[inst_type] ++;
}
