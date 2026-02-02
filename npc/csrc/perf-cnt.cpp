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

unsigned long long Perf_cnt::module(MODULE_ENUM module) {
    return this->__module[module];
}

void Perf_cnt::print_module_called(MODULE_ENUM module) {
    Log("%s called %llu", module_lut[module], this->__module[module]);
}

void Perf_cnt::print_inst_info(void) {
    Log("----------------------------------------------------------");
    Log("| %-9s | %10s | %9s | %18s |",
        "Inst Type", "Count", "Ratio(%)", "Avg Cycles (CPI)");
    Log("----------------------------------------------------------");

    for (int i = 0; i < __INST_TYPE_NUM; i++) {
        if (this->__inst[i].num == 0) continue;

        double ratio =
            (double)this->__inst[i].num /
            (double)this->__total_inst.num * 100.0;

        double avg_cyc =
            (double)this->__inst[i].cyc /
            (double)this->__inst[i].num;

        Log("| %-9s | %10u | %9.2f | %18.2f |",
            inst_type_lut[i],
            this->__inst[i].num,
            ratio,
            avg_cyc);
    }

    Log("----------------------------------------------------------");
    Log("| %-9s | %10u | %9.2f | %18s |",
        "TOTAL",
        this->__total_inst.num,
        100.0,
        "-");
    Log("----------------------------------------------------------");
}

void Perf_cnt::ifu_wait_pc(void) {
    this->__ifu.wait_pc ++;
}
void Perf_cnt::ifu_wait_rd(void) {
    this->__ifu.wait_rd ++;
}

void Perf_cnt::print_ifu_info(void) {
    double pc =
            (double)(this->__ifu.wait_pc) /
            (double)(this->__ifu.wait_pc + this->__ifu.wait_rd) * 100.0;
    double rd =
            (double)(this->__ifu.wait_rd) /
            (double)(this->__ifu.wait_pc + this->__ifu.wait_rd) * 100.0;

    Log("IFU waitng PC_Cnt update about %0.2f%%", pc);
    Log("IFU waitng R_Data ready  about %0.2f%%", rd);
}

void Perf_cnt::lsu_wait_num(char ch) {
    switch (ch) {
        case 'r':
            this->__lsu.read_num ++;
            break;
        case 'w':
            this->__lsu.write_num ++;
            break;
    }
}
void Perf_cnt::lsu_wait_cyc(char ch) {
    switch (ch) {
        case 'r':
            this->__lsu.read_cyc ++;
            break;
        case 'w':
            this->__lsu.write_cyc ++;
            break;
    }
}

void Perf_cnt::print_lsu_info(void) {
    Log("--------------------------------------------");
    Log("| %-10s | %9s | %16s |",
        "LSU Access", "Count", "Avg Latency(cyc)");
    Log("--------------------------------------------");

    if (this->__lsu.read_num > 0) {
        double read_avg =
            (double)this->__lsu.read_cyc /
            (double)this->__lsu.read_num;

        Log("| %-10s | %9llu | %16.2f |",
            "READ",
            this->__lsu.read_num,
            read_avg);
    }

    if (this->__lsu.write_num > 0) {
        double write_avg =
            (double)this->__lsu.write_cyc /
            (double)this->__lsu.write_num;

        Log("| %-10s | %9llu | %16.2f |",
            "WRITE",
            this->__lsu.write_num,
            write_avg);
    }

    Log("--------------------------------------------");
}

Perf_cnt perf_cnt;
