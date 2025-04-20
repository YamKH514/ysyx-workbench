// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+98,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+99,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+100,"inst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+101,"pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+98,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+99,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+100,"inst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+101,"pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+102,"wen",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+103,"success",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+103,"addi_en",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+104,"ebreak_en",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+105,"raddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+106,"waddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+105,"addr_s",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+106,"addr_d",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+1,"rdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+107,"wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+108,"imm",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("u_ADDI ");
    tracep->declBit(c+103,"en",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+105,"addr_s",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+106,"addr_d",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+108,"imm",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+1,"src1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+102,"wen",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+105,"addr_s_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+106,"addr_d_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+107,"res",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+103,"success",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+109,"carry",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+110,"overflow",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+111,"zero",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->pushNamePrefix("u_adder32 ");
    tracep->declBit(c+160,"mode",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+1,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+108,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+107,"result",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+109,"carry",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+110,"overflow",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+111,"zero",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+108,"b_complement",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+112,"carry_out",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,"t_add_Cin",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("gen_add[10] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+2,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+3,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+113,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+4,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+114,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[11] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+4,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+5,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+115,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+6,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+116,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[12] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+6,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+7,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+8,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+118,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[13] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+8,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+9,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+10,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+119,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[14] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+10,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+11,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+12,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+120,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[15] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+12,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+13,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+14,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+121,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[16] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+14,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+15,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+16,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+122,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[17] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+16,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+17,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+18,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+123,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[18] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+18,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+19,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+20,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+124,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[19] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+20,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+21,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+22,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+125,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[1] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+23,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+24,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+126,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+127,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[20] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+22,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+26,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+27,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+128,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[21] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+27,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+28,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+29,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+129,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[22] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+29,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+30,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+31,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+130,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[23] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+31,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+32,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+33,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+131,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[24] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+33,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+34,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+35,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+132,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[25] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+35,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+36,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+37,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+133,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[26] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+37,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+38,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+39,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+134,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[27] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+39,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+40,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+41,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+135,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[28] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+41,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+42,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+43,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+136,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[29] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+43,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+44,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+45,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+137,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[2] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+25,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+46,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+138,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+47,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+139,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[30] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+45,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+48,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+49,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+140,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[31] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+49,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+50,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+109,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+141,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[3] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+47,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+51,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+142,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+52,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+143,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[4] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+52,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+53,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+144,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+54,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+145,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[5] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+54,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+55,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+146,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+56,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+147,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[6] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+56,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+57,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+148,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+58,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+149,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[7] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+58,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+59,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+150,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+60,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+151,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[8] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+60,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+152,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+62,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+153,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[9] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+62,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+63,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+154,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+2,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+155,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("u_adder0 ");
    tracep->declBit(c+160,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+64,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+156,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+157,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("u_Decode ");
    tracep->declBus(c+100,"inst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+105,"addr_s",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+106,"addr_d",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+108,"imm",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+103,"addi_en",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+104,"ebreak_en",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+158,"opcode",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 6,0);
    tracep->declBus(c+159,"funct3",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_EBREAK ");
    tracep->declBit(c+104,"ebreak_en",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+98,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_GPR ");
    tracep->declBit(c+98,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+102,"wen",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+106,"waddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+105,"raddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+107,"wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+1,"rdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("general_reg ");
    tracep->declBus(c+161,"ADDR_WIDTH",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+162,"DATA_WIDTH",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBit(c+98,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+107,"wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+106,"waddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+105,"raddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+102,"wen",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+1,"rdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+65+i*1,"rf",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("u_PC ");
    tracep->declBit(c+98,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+99,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+103,"next",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+101,"pc_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+97,"pc",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__rdata),32);
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+3,((1U & (vlSelf->top__DOT__rdata 
                                 >> 0xaU))));
    bufp->fullBit(oldp+4,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+5,((1U & (vlSelf->top__DOT__rdata 
                                 >> 0xbU))));
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+7,((1U & (vlSelf->top__DOT__rdata 
                                 >> 0xcU))));
    bufp->fullBit(oldp+8,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+9,((1U & (vlSelf->top__DOT__rdata 
                                 >> 0xdU))));
    bufp->fullBit(oldp+10,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+11,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0xeU))));
    bufp->fullBit(oldp+12,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+13,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0xfU))));
    bufp->fullBit(oldp+14,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+15,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x10U))));
    bufp->fullBit(oldp+16,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+17,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x11U))));
    bufp->fullBit(oldp+18,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+19,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x12U))));
    bufp->fullBit(oldp+20,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+21,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x13U))));
    bufp->fullBit(oldp+22,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+23,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+24,((1U & (vlSelf->top__DOT__rdata 
                                  >> 1U))));
    bufp->fullBit(oldp+25,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+26,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x14U))));
    bufp->fullBit(oldp+27,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+28,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x15U))));
    bufp->fullBit(oldp+29,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+30,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x16U))));
    bufp->fullBit(oldp+31,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+32,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x17U))));
    bufp->fullBit(oldp+33,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+34,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x18U))));
    bufp->fullBit(oldp+35,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+36,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x19U))));
    bufp->fullBit(oldp+37,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+38,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x1aU))));
    bufp->fullBit(oldp+39,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+40,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x1bU))));
    bufp->fullBit(oldp+41,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+42,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x1cU))));
    bufp->fullBit(oldp+43,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+44,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x1dU))));
    bufp->fullBit(oldp+45,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+46,((1U & (vlSelf->top__DOT__rdata 
                                  >> 2U))));
    bufp->fullBit(oldp+47,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+48,((1U & (vlSelf->top__DOT__rdata 
                                  >> 0x1eU))));
    bufp->fullBit(oldp+49,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+50,((vlSelf->top__DOT__rdata 
                            >> 0x1fU)));
    bufp->fullBit(oldp+51,((1U & (vlSelf->top__DOT__rdata 
                                  >> 3U))));
    bufp->fullBit(oldp+52,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+53,((1U & (vlSelf->top__DOT__rdata 
                                  >> 4U))));
    bufp->fullBit(oldp+54,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+55,((1U & (vlSelf->top__DOT__rdata 
                                  >> 5U))));
    bufp->fullBit(oldp+56,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+57,((1U & (vlSelf->top__DOT__rdata 
                                  >> 6U))));
    bufp->fullBit(oldp+58,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+59,((1U & (vlSelf->top__DOT__rdata 
                                  >> 7U))));
    bufp->fullBit(oldp+60,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+61,((1U & (vlSelf->top__DOT__rdata 
                                  >> 8U))));
    bufp->fullBit(oldp+62,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+63,((1U & (vlSelf->top__DOT__rdata 
                                  >> 9U))));
    bufp->fullBit(oldp+64,((1U & vlSelf->top__DOT__rdata)));
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[0]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[1]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[2]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[3]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[4]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[5]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[6]),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[7]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[8]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[9]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[10]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[11]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[12]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[13]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[14]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[15]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[16]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[17]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[18]),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[19]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[20]),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[21]),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[22]),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[23]),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[24]),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[25]),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[26]),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[27]),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[28]),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[29]),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[30]),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[31]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__u_PC__DOT__pc),32);
    bufp->fullBit(oldp+98,(vlSelf->clk));
    bufp->fullBit(oldp+99,(vlSelf->rst));
    bufp->fullIData(oldp+100,(vlSelf->inst),32);
    bufp->fullIData(oldp+101,(vlSelf->pc),32);
    bufp->fullBit(oldp+102,(((0U != (0x1fU & (vlSelf->inst 
                                              >> 7U))) 
                             & (IData)(vlSelf->top__DOT__addi_en))));
    bufp->fullBit(oldp+103,(vlSelf->top__DOT__addi_en));
    bufp->fullBit(oldp+104,((IData)((0x73U == (0x707fU 
                                               & vlSelf->inst)))));
    bufp->fullCData(oldp+105,((0x1fU & (vlSelf->inst 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+106,((0x1fU & (vlSelf->inst 
                                        >> 7U))),5);
    bufp->fullIData(oldp+107,(((((vlSelf->top__DOT__rdata 
                                  >> 0x1fU) + ((vlSelf->inst 
                                                >> 0x1fU) 
                                               + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin))) 
                                << 0x1fU) | ((0x40000000U 
                                              & (((vlSelf->top__DOT__rdata 
                                                   >> 0x1eU) 
                                                  + 
                                                  ((vlSelf->inst 
                                                    >> 0x1fU) 
                                                   + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin))) 
                                                 << 0x1eU)) 
                                             | ((0x20000000U 
                                                 & (((vlSelf->top__DOT__rdata 
                                                      >> 0x1dU) 
                                                     + 
                                                     ((vlSelf->inst 
                                                       >> 0x1fU) 
                                                      + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin))) 
                                                    << 0x1dU)) 
                                                | ((0x10000000U 
                                                    & (((vlSelf->top__DOT__rdata 
                                                         >> 0x1cU) 
                                                        + 
                                                        ((vlSelf->inst 
                                                          >> 0x1fU) 
                                                         + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin))) 
                                                       << 0x1cU)) 
                                                   | ((0x8000000U 
                                                       & (((vlSelf->top__DOT__rdata 
                                                            >> 0x1bU) 
                                                           + 
                                                           ((vlSelf->inst 
                                                             >> 0x1fU) 
                                                            + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin))) 
                                                          << 0x1bU)) 
                                                      | ((0x4000000U 
                                                          & (((vlSelf->top__DOT__rdata 
                                                               >> 0x1aU) 
                                                              + 
                                                              ((vlSelf->inst 
                                                                >> 0x1fU) 
                                                               + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin))) 
                                                             << 0x1aU)) 
                                                         | ((0x2000000U 
                                                             & (((vlSelf->top__DOT__rdata 
                                                                  >> 0x19U) 
                                                                 + 
                                                                 ((vlSelf->inst 
                                                                   >> 0x1fU) 
                                                                  + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin))) 
                                                                << 0x19U)) 
                                                            | ((0x1000000U 
                                                                & (((vlSelf->top__DOT__rdata 
                                                                     >> 0x18U) 
                                                                    + 
                                                                    ((vlSelf->inst 
                                                                      >> 0x1fU) 
                                                                     + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin))) 
                                                                   << 0x18U)) 
                                                               | ((0x800000U 
                                                                   & (((vlSelf->top__DOT__rdata 
                                                                        >> 0x17U) 
                                                                       + 
                                                                       ((vlSelf->inst 
                                                                         >> 0x1fU) 
                                                                        + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin))) 
                                                                      << 0x17U)) 
                                                                  | ((0x400000U 
                                                                      & (((vlSelf->top__DOT__rdata 
                                                                           >> 0x16U) 
                                                                          + 
                                                                          ((vlSelf->inst 
                                                                            >> 0x1fU) 
                                                                           + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin))) 
                                                                         << 0x16U)) 
                                                                     | ((0x200000U 
                                                                         & (((vlSelf->top__DOT__rdata 
                                                                              >> 0x15U) 
                                                                             + 
                                                                             ((vlSelf->inst 
                                                                               >> 0x1fU) 
                                                                              + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin))) 
                                                                            << 0x15U)) 
                                                                        | ((0x100000U 
                                                                            & (((vlSelf->top__DOT__rdata 
                                                                                >> 0x14U) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin))) 
                                                                               << 0x14U)) 
                                                                           | ((0x80000U 
                                                                               & (((vlSelf->top__DOT__rdata 
                                                                                >> 0x13U) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin))) 
                                                                                << 0x13U)) 
                                                                              | ((0x40000U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 0x12U) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin))) 
                                                                                << 0x12U)) 
                                                                                | ((0x20000U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 0x11U) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin))) 
                                                                                << 0x11U)) 
                                                                                | ((0x10000U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 0x10U) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin))) 
                                                                                << 0x10U)) 
                                                                                | ((0x8000U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 0xfU) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin))) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 0xeU) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin))) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 0xdU) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin))) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 0xcU) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin))) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 0xbU) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x1fU))) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 0xaU) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x1eU))) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 9U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x1dU))) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 8U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x1cU))) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 7U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x1bU))) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 6U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x1aU))) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 5U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x19U))) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 4U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x18U))) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 3U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x17U))) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 2U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x16U))) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & (((vlSelf->top__DOT__rdata 
                                                                                >> 1U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x15U))) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (vlSelf->top__DOT__rdata 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x14U))))))))))))))))))))))))))))))))))),32);
    bufp->fullIData(oldp+108,(((((vlSelf->inst >> 0x1fU)
                                  ? 0xfffffU : 0U) 
                                << 0xcU) | (vlSelf->inst 
                                            >> 0x14U))),32);
    bufp->fullBit(oldp+109,((1U & (((vlSelf->top__DOT__rdata 
                                     >> 0x1fU) & ((vlSelf->inst 
                                                   >> 0x1fU) 
                                                  | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin))) 
                                   | ((vlSelf->inst 
                                       >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+110,((((vlSelf->top__DOT__rdata 
                               >> 0x1fU) == (1U & (
                                                   ((vlSelf->inst 
                                                     >> 0x1fU)
                                                     ? 0xfffffU
                                                     : 0U) 
                                                   >> 0x13U))) 
                             & ((1U & ((vlSelf->top__DOT__rdata 
                                        >> 0x1fU) + 
                                       ((vlSelf->inst 
                                         >> 0x1fU) 
                                        + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin)))) 
                                != (vlSelf->top__DOT__rdata 
                                    >> 0x1fU)))));
    bufp->fullBit(oldp+111,((1U & (~ (((vlSelf->top__DOT__rdata 
                                        >> 0x1fU) + 
                                       ((vlSelf->inst 
                                         >> 0x1fU) 
                                        + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin))) 
                                      | (((vlSelf->top__DOT__rdata 
                                           >> 0x1eU) 
                                          + ((vlSelf->inst 
                                              >> 0x1fU) 
                                             + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin))) 
                                         | (((vlSelf->top__DOT__rdata 
                                              >> 0x1dU) 
                                             + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin))) 
                                            | (((vlSelf->top__DOT__rdata 
                                                 >> 0x1cU) 
                                                + (
                                                   (vlSelf->inst 
                                                    >> 0x1fU) 
                                                   + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin))) 
                                               | (((vlSelf->top__DOT__rdata 
                                                    >> 0x1bU) 
                                                   + 
                                                   ((vlSelf->inst 
                                                     >> 0x1fU) 
                                                    + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin))) 
                                                  | (((vlSelf->top__DOT__rdata 
                                                       >> 0x1aU) 
                                                      + 
                                                      ((vlSelf->inst 
                                                        >> 0x1fU) 
                                                       + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin))) 
                                                     | (((vlSelf->top__DOT__rdata 
                                                          >> 0x19U) 
                                                         + 
                                                         ((vlSelf->inst 
                                                           >> 0x1fU) 
                                                          + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin))) 
                                                        | (((vlSelf->top__DOT__rdata 
                                                             >> 0x18U) 
                                                            + 
                                                            ((vlSelf->inst 
                                                              >> 0x1fU) 
                                                             + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin))) 
                                                           | (((vlSelf->top__DOT__rdata 
                                                                >> 0x17U) 
                                                               + 
                                                               ((vlSelf->inst 
                                                                 >> 0x1fU) 
                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin))) 
                                                              | (((vlSelf->top__DOT__rdata 
                                                                   >> 0x16U) 
                                                                  + 
                                                                  ((vlSelf->inst 
                                                                    >> 0x1fU) 
                                                                   + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin))) 
                                                                 | (((vlSelf->top__DOT__rdata 
                                                                      >> 0x15U) 
                                                                     + 
                                                                     ((vlSelf->inst 
                                                                       >> 0x1fU) 
                                                                      + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin))) 
                                                                    | (((vlSelf->top__DOT__rdata 
                                                                         >> 0x14U) 
                                                                        + 
                                                                        ((vlSelf->inst 
                                                                          >> 0x1fU) 
                                                                         + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin))) 
                                                                       | (((vlSelf->top__DOT__rdata 
                                                                            >> 0x13U) 
                                                                           + 
                                                                           ((vlSelf->inst 
                                                                             >> 0x1fU) 
                                                                            + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin))) 
                                                                          | (((vlSelf->top__DOT__rdata 
                                                                               >> 0x12U) 
                                                                              + 
                                                                              ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                               + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin))) 
                                                                             | (((vlSelf->top__DOT__rdata 
                                                                                >> 0x11U) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 0x10U) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 0xfU) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 0xeU) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 0xdU) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 0xcU) 
                                                                                + 
                                                                                ((vlSelf->inst 
                                                                                >> 0x1fU) 
                                                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 0xbU) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x1fU))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 0xaU) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x1eU))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 9U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x1dU))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 8U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x1cU))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 7U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x1bU))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 6U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x1aU))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 5U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x19U))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 4U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x18U))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 3U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x17U))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 2U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x16U))) 
                                                                                | (((vlSelf->top__DOT__rdata 
                                                                                >> 1U) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x15U))) 
                                                                                | (vlSelf->top__DOT__rdata 
                                                                                + 
                                                                                (vlSelf->inst 
                                                                                >> 0x14U)))))))))))))))))))))))))))))))))))));
    bufp->fullIData(oldp+112,(((0x80000000U & ((vlSelf->top__DOT__rdata 
                                                & ((0x80000000U 
                                                    & vlSelf->inst) 
                                                   | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                                      << 0x1fU))) 
                                               | (vlSelf->inst 
                                                  & ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                                     << 0x1fU)))) 
                               | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                   << 0x1eU) | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
                                                 << 0x1dU) 
                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
                                                    << 0x1cU) 
                                                   | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
                                                       << 0x1bU) 
                                                      | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin) 
                                                          << 0x1aU) 
                                                         | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin) 
                                                             << 0x19U) 
                                                            | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin) 
                                                                << 0x18U) 
                                                               | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin) 
                                                                   << 0x17U) 
                                                                  | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin) 
                                                                      << 0x16U) 
                                                                     | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin) 
                                                                         << 0x15U) 
                                                                        | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin) 
                                                                            << 0x14U) 
                                                                           | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin) 
                                                                               << 0x13U) 
                                                                              | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin))))))))))))))))))))))))))))))))),32);
    bufp->fullBit(oldp+113,((1U & (vlSelf->inst >> 0x1eU))));
    bufp->fullBit(oldp+114,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0xaU) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                                                + (vlSelf->inst 
                                                   >> 0x1eU))))));
    bufp->fullBit(oldp+115,((vlSelf->inst >> 0x1fU)));
    bufp->fullBit(oldp+116,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0xbU) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                                                + (vlSelf->inst 
                                                   >> 0x1fU))))));
    bufp->fullBit(oldp+117,((vlSelf->inst >> 0x1fU)));
    bufp->fullBit(oldp+118,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0xcU) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+119,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0xdU) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+120,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0xeU) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+121,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0xfU) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+122,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x10U) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+123,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x11U) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+124,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x12U) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+125,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x13U) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+126,((1U & (vlSelf->inst >> 0x15U))));
    bufp->fullBit(oldp+127,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 1U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
                                              + (vlSelf->inst 
                                                 >> 0x15U))))));
    bufp->fullBit(oldp+128,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x14U) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+129,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x15U) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+130,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x16U) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+131,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x17U) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+132,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x18U) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+133,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x19U) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+134,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x1aU) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+135,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x1bU) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+136,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x1cU) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+137,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x1dU) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+138,((1U & (vlSelf->inst >> 0x16U))));
    bufp->fullBit(oldp+139,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 2U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                                              + (vlSelf->inst 
                                                 >> 0x16U))))));
    bufp->fullBit(oldp+140,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x1eU) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+141,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 0x1fU) + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin))))));
    bufp->fullBit(oldp+142,((1U & (vlSelf->inst >> 0x17U))));
    bufp->fullBit(oldp+143,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 3U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                                              + (vlSelf->inst 
                                                 >> 0x17U))))));
    bufp->fullBit(oldp+144,((1U & (vlSelf->inst >> 0x18U))));
    bufp->fullBit(oldp+145,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 4U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                                              + (vlSelf->inst 
                                                 >> 0x18U))))));
    bufp->fullBit(oldp+146,((1U & (vlSelf->inst >> 0x19U))));
    bufp->fullBit(oldp+147,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 5U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                                              + (vlSelf->inst 
                                                 >> 0x19U))))));
    bufp->fullBit(oldp+148,((1U & (vlSelf->inst >> 0x1aU))));
    bufp->fullBit(oldp+149,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 6U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                                              + (vlSelf->inst 
                                                 >> 0x1aU))))));
    bufp->fullBit(oldp+150,((1U & (vlSelf->inst >> 0x1bU))));
    bufp->fullBit(oldp+151,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 7U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                                              + (vlSelf->inst 
                                                 >> 0x1bU))))));
    bufp->fullBit(oldp+152,((1U & (vlSelf->inst >> 0x1cU))));
    bufp->fullBit(oldp+153,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 8U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                                              + (vlSelf->inst 
                                                 >> 0x1cU))))));
    bufp->fullBit(oldp+154,((1U & (vlSelf->inst >> 0x1dU))));
    bufp->fullBit(oldp+155,((1U & ((vlSelf->top__DOT__rdata 
                                    >> 9U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                                              + (vlSelf->inst 
                                                 >> 0x1dU))))));
    bufp->fullBit(oldp+156,((1U & (vlSelf->inst >> 0x14U))));
    bufp->fullBit(oldp+157,((1U & (vlSelf->top__DOT__rdata 
                                   + (vlSelf->inst 
                                      >> 0x14U)))));
    bufp->fullCData(oldp+158,((0x7fU & vlSelf->inst)),7);
    bufp->fullCData(oldp+159,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullBit(oldp+160,(0U));
    bufp->fullIData(oldp+161,(5U),32);
    bufp->fullIData(oldp+162,(0x20U),32);
}
