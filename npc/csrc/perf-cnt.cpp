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

// void Perf_cnt::print_inst_info(void) {
//     for(int i = 0; i < __INST_TYPE_NUM; i ++) {
//         Log("%s inst was executed %d times, which is approximately %f of all instructions, and on average, it required %f cycles to execute.",
//             inst_type_lut[i],
//             this->__inst[i].num,
//             (double)(this->__inst[i].num)/(double)(this->__total_inst.num),
//             (double)(this->__inst[i].cyc)/(double)(this->__inst[i].num));
//     }
// }

void Perf_cnt::print_inst_info(void) {
    Log("----------------------------------------------------------------");
    Log("| %-9s | %10s | %9s | %18s |",
        "Inst Type", "Count", "Ratio(%)", "Avg Cycles (CPI)");
    Log("----------------------------------------------------------------");

    for (int i = 0; i < __INST_TYPE_NUM; i++) {
        if (this->__inst[i].num == 0) continue;

        double ratio =
            (double)this->__inst[i].num /
            (double)this->__total_inst.num * 100.0;

        double avg_cyc =
            (double)this->__inst[i].cyc /
            (double)this->__inst[i].num;

        Log("| %-9s | %10llu | %9.2f | %18.2f |",
            inst_type_lut[i],
            this->__inst[i].num,
            ratio,
            avg_cyc);
    }

    Log("----------------------------------------------------------------");
    Log("| %-9s | %10u | %9.2f | %18s |",
        "TOTAL",
        this->__total_inst.num,
        100.0,
        "-");
    Log("----------------------------------------------------------------");
}

Perf_cnt perf_cnt;
