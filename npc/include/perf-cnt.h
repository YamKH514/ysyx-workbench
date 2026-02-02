#ifndef PERF_CNT_H__
#define PERF_CNT_H__

#define __INST_TYPE_NUM 6
#define __MODULE_CNT_NUM 3

#define PERF_MODULE(name) perf_cnt.module[name]
#define PERF_INST_NUM(inst_t) perf_cnt.inst[type_##inst_t].num
#define PERF_INST_CYC(inst_t) perf_cnt.inst[type_##inst_t].cyc

typedef enum {
    type_i = 0, type_s, type_b, type_u, type_j, type_r
} INST_TYPE_ENUM;

typedef enum {
    IFU = 0, EXU, LSU
} MODULE_ENUM;

typedef struct {
    int num;
    unsigned long long cyc;
} inst_cnt;

typedef struct {
    unsigned long long module[__MODULE_CNT_NUM];
    inst_cnt inst[__INST_TYPE_NUM];
} perf_cnt_struct;

extern perf_cnt_struct perf_cnt;

void perf_cnt_module_add(bool cond, MODULE_ENUM module);
void perf_cnt_inst_add(INST_TYPE_ENUM inst_type, int num);

#endif
