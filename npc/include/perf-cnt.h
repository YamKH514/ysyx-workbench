#ifndef PERF_CNT_H__
#define PERF_CNT_H__

#define __INST_TYPE_NUM 6
#define __MODULE_CNT_NUM 3

#define PERF_MODULE(name) perf_cnt.module_cnt[name]
#define PERF_INST(inst_t) perf_cnt.inst_cnt[type_##inst_t]

typedef enum {
    type_i = 0, type_s, type_b, type_u, type_j, type_r
} INST_TYPE_ENUM;

typedef enum {
    IFU = 0, EXU, LSU
} MODULE_ENUM;

typedef struct {
    unsigned long long module_cnt[__MODULE_CNT_NUM];
    int inst_cnt[__INST_TYPE_NUM];
} perf_cnt_struct;

extern perf_cnt_struct perf_cnt;

void perf_cnt_module_add(bool cond, MODULE_ENUM module);
void perf_cnt_inst_add(bool cond, INST_TYPE_ENUM inst_type);

#endif
