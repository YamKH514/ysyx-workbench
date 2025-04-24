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
    tracep->declBit(c+170,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+171,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+172,"inst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+173,"pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+170,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+171,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+172,"inst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+173,"pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+174,"npc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+1,"imm_type",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBit(c+182,"wen",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+175,"pc_sel",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBus(c+2,"src1_sel",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBus(c+3,"imm",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+36,"src1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+37,"src",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+38,"res",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("u_ADD ");
    tracep->declBus(c+3,"imm",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+37,"src",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+38,"res",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+39,"carry",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+40,"overflow",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+41,"zero",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->pushNamePrefix("u_adder32 ");
    tracep->declBit(c+183,"mode",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+37,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+38,"result",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+39,"carry",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+40,"overflow",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+41,"zero",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+3,"b_complement",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,"carry_out",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,"t_add_Cin",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("gen_add[10] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+43,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+44,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+4,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+45,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+46,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[11] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+45,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+47,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+5,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+48,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+49,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[12] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+48,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+50,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+6,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+51,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+52,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[13] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+51,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+53,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+7,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+54,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+55,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[14] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+54,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+56,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+8,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+57,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+58,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[15] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+57,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+59,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+9,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+60,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[16] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+60,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+62,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+10,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+63,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+64,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[17] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+63,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+65,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+11,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+66,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+67,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[18] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+66,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+68,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+12,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+69,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+70,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[19] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+69,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+71,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+13,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+72,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+73,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[1] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+74,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+75,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+14,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+76,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+77,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[20] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+72,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+78,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+15,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+79,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+80,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[21] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+79,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+81,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+16,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+82,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+83,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[22] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+82,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+84,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+17,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+85,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+86,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[23] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+85,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+87,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+18,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+88,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+89,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[24] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+88,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+90,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+19,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+91,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+92,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[25] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+91,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+93,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+20,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+94,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+95,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[26] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+94,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+96,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+21,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+97,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+98,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[27] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+97,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+99,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+22,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+100,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+101,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[28] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+100,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+102,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+103,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+104,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[29] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+103,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+105,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+24,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+106,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+107,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[2] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+76,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+108,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+109,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+110,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[30] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+106,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+111,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+26,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+112,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+113,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[31] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+112,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+114,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+27,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+39,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+115,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[3] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+109,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+116,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+28,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+117,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+118,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[4] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+117,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+119,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+29,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+120,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+121,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[5] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+120,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+122,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+30,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+123,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+124,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[6] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+123,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+125,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+31,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+126,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+127,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[7] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+126,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+128,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+32,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+129,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+130,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[8] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+129,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+131,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+33,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+132,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+133,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("gen_add[9] ");
    tracep->pushNamePrefix("u_adder1 ");
    tracep->declBit(c+132,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+134,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+34,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+43,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+135,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("u_adder0 ");
    tracep->declBit(c+183,"Cin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+136,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+35,"b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+74,"Cout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+137,"sum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("u_Decode ");
    tracep->declBus(c+176,"opcode",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 6,0);
    tracep->declBus(c+177,"funct3",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+178,"funct7",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 6,0);
    tracep->declBus(c+1,"imm_type",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBit(c+182,"wen",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+2,"src1_sel",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBus(c+175,"pc_sel",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_GPR ");
    tracep->declBit(c+170,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+182,"wen",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+179,"waddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+180,"raddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+38,"wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+36,"rdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("general_reg ");
    tracep->declBus(c+184,"ADDR_WIDTH",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+185,"DATA_WIDTH",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBit(c+170,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+38,"wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+179,"waddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+180,"raddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+182,"wen",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+36,"rdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+138+i*1,"rf",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("u_ImmDecode ");
    tracep->declBus(c+1,"imm_type",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+181,"imm_in",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,7);
    tracep->declBus(c+3,"imm_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_PC ");
    tracep->declBit(c+170,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+171,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+174,"npc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+173,"pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
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
    bufp->fullCData(oldp+1,(vlSelf->top__DOT__imm_type),3);
    bufp->fullCData(oldp+2,(vlSelf->top__DOT__src1_sel),2);
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+4,((1U & (vlSelf->top__DOT__imm 
                                 >> 0xaU))));
    bufp->fullBit(oldp+5,((1U & (vlSelf->top__DOT__imm 
                                 >> 0xbU))));
    bufp->fullBit(oldp+6,((1U & (vlSelf->top__DOT__imm 
                                 >> 0xcU))));
    bufp->fullBit(oldp+7,((1U & (vlSelf->top__DOT__imm 
                                 >> 0xdU))));
    bufp->fullBit(oldp+8,((1U & (vlSelf->top__DOT__imm 
                                 >> 0xeU))));
    bufp->fullBit(oldp+9,((1U & (vlSelf->top__DOT__imm 
                                 >> 0xfU))));
    bufp->fullBit(oldp+10,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x10U))));
    bufp->fullBit(oldp+11,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x11U))));
    bufp->fullBit(oldp+12,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x12U))));
    bufp->fullBit(oldp+13,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x13U))));
    bufp->fullBit(oldp+14,((1U & (vlSelf->top__DOT__imm 
                                  >> 1U))));
    bufp->fullBit(oldp+15,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x14U))));
    bufp->fullBit(oldp+16,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x15U))));
    bufp->fullBit(oldp+17,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x16U))));
    bufp->fullBit(oldp+18,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x17U))));
    bufp->fullBit(oldp+19,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x18U))));
    bufp->fullBit(oldp+20,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x19U))));
    bufp->fullBit(oldp+21,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x1aU))));
    bufp->fullBit(oldp+22,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x1bU))));
    bufp->fullBit(oldp+23,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x1cU))));
    bufp->fullBit(oldp+24,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x1dU))));
    bufp->fullBit(oldp+25,((1U & (vlSelf->top__DOT__imm 
                                  >> 2U))));
    bufp->fullBit(oldp+26,((1U & (vlSelf->top__DOT__imm 
                                  >> 0x1eU))));
    bufp->fullBit(oldp+27,((vlSelf->top__DOT__imm >> 0x1fU)));
    bufp->fullBit(oldp+28,((1U & (vlSelf->top__DOT__imm 
                                  >> 3U))));
    bufp->fullBit(oldp+29,((1U & (vlSelf->top__DOT__imm 
                                  >> 4U))));
    bufp->fullBit(oldp+30,((1U & (vlSelf->top__DOT__imm 
                                  >> 5U))));
    bufp->fullBit(oldp+31,((1U & (vlSelf->top__DOT__imm 
                                  >> 6U))));
    bufp->fullBit(oldp+32,((1U & (vlSelf->top__DOT__imm 
                                  >> 7U))));
    bufp->fullBit(oldp+33,((1U & (vlSelf->top__DOT__imm 
                                  >> 8U))));
    bufp->fullBit(oldp+34,((1U & (vlSelf->top__DOT__imm 
                                  >> 9U))));
    bufp->fullBit(oldp+35,((1U & vlSelf->top__DOT__imm)));
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__src1),32);
    bufp->fullIData(oldp+37,(((0U == (IData)(vlSelf->top__DOT__src1_sel))
                               ? 0U : vlSelf->__VdfgTmp_h1bde3cb9__0)),32);
    bufp->fullIData(oldp+38,(((((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                                + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                   + (vlSelf->top__DOT__imm 
                                      >> 0x1fU))) << 0x1fU) 
                              | ((0x40000000U & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a) 
                                                  + 
                                                  ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
                                                   + 
                                                   (vlSelf->top__DOT__imm 
                                                    >> 0x1eU))) 
                                                 << 0x1eU)) 
                                 | ((0x20000000U & 
                                     (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a) 
                                       + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
                                          + (vlSelf->top__DOT__imm 
                                             >> 0x1dU))) 
                                      << 0x1dU)) | 
                                    ((0x10000000U & 
                                      (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a) 
                                        + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
                                           + (vlSelf->top__DOT__imm 
                                              >> 0x1cU))) 
                                       << 0x1cU)) | 
                                     ((0x8000000U & 
                                       (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__a) 
                                         + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin) 
                                            + (vlSelf->top__DOT__imm 
                                               >> 0x1bU))) 
                                        << 0x1bU)) 
                                      | ((0x4000000U 
                                          & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__a) 
                                              + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin) 
                                                 + 
                                                 (vlSelf->top__DOT__imm 
                                                  >> 0x1aU))) 
                                             << 0x1aU)) 
                                         | ((0x2000000U 
                                             & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__a) 
                                                 + 
                                                 ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin) 
                                                  + 
                                                  (vlSelf->top__DOT__imm 
                                                   >> 0x19U))) 
                                                << 0x19U)) 
                                            | ((0x1000000U 
                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__a) 
                                                    + 
                                                    ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin) 
                                                     + 
                                                     (vlSelf->top__DOT__imm 
                                                      >> 0x18U))) 
                                                   << 0x18U)) 
                                               | ((0x800000U 
                                                   & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__a) 
                                                       + 
                                                       ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin) 
                                                        + 
                                                        (vlSelf->top__DOT__imm 
                                                         >> 0x17U))) 
                                                      << 0x17U)) 
                                                  | ((0x400000U 
                                                      & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__a) 
                                                          + 
                                                          ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin) 
                                                           + 
                                                           (vlSelf->top__DOT__imm 
                                                            >> 0x16U))) 
                                                         << 0x16U)) 
                                                     | ((0x200000U 
                                                         & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__a) 
                                                             + 
                                                             ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin) 
                                                              + 
                                                              (vlSelf->top__DOT__imm 
                                                               >> 0x15U))) 
                                                            << 0x15U)) 
                                                        | ((0x100000U 
                                                            & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__a) 
                                                                + 
                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin) 
                                                                 + 
                                                                 (vlSelf->top__DOT__imm 
                                                                  >> 0x14U))) 
                                                               << 0x14U)) 
                                                           | ((0x80000U 
                                                               & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__a) 
                                                                   + 
                                                                   ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin) 
                                                                    + 
                                                                    (vlSelf->top__DOT__imm 
                                                                     >> 0x13U))) 
                                                                  << 0x13U)) 
                                                              | ((0x40000U 
                                                                  & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__a) 
                                                                      + 
                                                                      ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin) 
                                                                       + 
                                                                       (vlSelf->top__DOT__imm 
                                                                        >> 0x12U))) 
                                                                     << 0x12U)) 
                                                                 | ((0x20000U 
                                                                     & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__a) 
                                                                         + 
                                                                         ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin) 
                                                                          + 
                                                                          (vlSelf->top__DOT__imm 
                                                                           >> 0x11U))) 
                                                                        << 0x11U)) 
                                                                    | ((0x10000U 
                                                                        & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__a) 
                                                                            + 
                                                                            ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin) 
                                                                             + 
                                                                             (vlSelf->top__DOT__imm 
                                                                              >> 0x10U))) 
                                                                           << 0x10U)) 
                                                                       | ((0x8000U 
                                                                           & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__a) 
                                                                               + 
                                                                               ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0xfU))) 
                                                                              << 0xfU)) 
                                                                          | ((0x4000U 
                                                                              & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0xeU))) 
                                                                                << 0xeU)) 
                                                                             | ((0x2000U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0xdU))) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0xcU))) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0xbU))) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0xaU))) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 9U))) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 8U))) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 7U))) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 6U))) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 5U))) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 4U))) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 3U))) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 2U))) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 1U))) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__u_adder0__a) 
                                                                                + vlSelf->top__DOT__imm)))))))))))))))))))))))))))))))))),32);
    bufp->fullBit(oldp+39,((((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                             & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                | (vlSelf->top__DOT__imm 
                                   >> 0x1fU))) | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->top__DOT__imm 
                                                     >> 0x1fU)))));
    bufp->fullBit(oldp+40,((((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                             == (vlSelf->top__DOT__imm 
                                 >> 0x1fU)) & ((1U 
                                                & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                                                   + 
                                                   ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                                    + 
                                                    (vlSelf->top__DOT__imm 
                                                     >> 0x1fU)))) 
                                               != (IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a)))));
    bufp->fullBit(oldp+41,((1U & (~ (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 0x1fU))) 
                                     | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a) 
                                         + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
                                            + (vlSelf->top__DOT__imm 
                                               >> 0x1eU))) 
                                        | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a) 
                                            + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
                                               + (vlSelf->top__DOT__imm 
                                                  >> 0x1dU))) 
                                           | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a) 
                                               + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
                                                  + 
                                                  (vlSelf->top__DOT__imm 
                                                   >> 0x1cU))) 
                                              | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__a) 
                                                  + 
                                                  ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin) 
                                                   + 
                                                   (vlSelf->top__DOT__imm 
                                                    >> 0x1bU))) 
                                                 | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__a) 
                                                     + 
                                                     ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin) 
                                                      + 
                                                      (vlSelf->top__DOT__imm 
                                                       >> 0x1aU))) 
                                                    | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__a) 
                                                        + 
                                                        ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin) 
                                                         + 
                                                         (vlSelf->top__DOT__imm 
                                                          >> 0x19U))) 
                                                       | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__a) 
                                                           + 
                                                           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin) 
                                                            + 
                                                            (vlSelf->top__DOT__imm 
                                                             >> 0x18U))) 
                                                          | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__a) 
                                                              + 
                                                              ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin) 
                                                               + 
                                                               (vlSelf->top__DOT__imm 
                                                                >> 0x17U))) 
                                                             | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__a) 
                                                                 + 
                                                                 ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin) 
                                                                  + 
                                                                  (vlSelf->top__DOT__imm 
                                                                   >> 0x16U))) 
                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__a) 
                                                                    + 
                                                                    ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin) 
                                                                     + 
                                                                     (vlSelf->top__DOT__imm 
                                                                      >> 0x15U))) 
                                                                   | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__a) 
                                                                       + 
                                                                       ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin) 
                                                                        + 
                                                                        (vlSelf->top__DOT__imm 
                                                                         >> 0x14U))) 
                                                                      | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__a) 
                                                                          + 
                                                                          ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin) 
                                                                           + 
                                                                           (vlSelf->top__DOT__imm 
                                                                            >> 0x13U))) 
                                                                         | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__a) 
                                                                             + 
                                                                             ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin) 
                                                                              + 
                                                                              (vlSelf->top__DOT__imm 
                                                                               >> 0x12U))) 
                                                                            | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0x11U))) 
                                                                               | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0x10U))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0xfU))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0xeU))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0xdU))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0xcU))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0xbU))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 0xaU))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 9U))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 8U))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 7U))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 6U))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 5U))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 4U))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 3U))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 2U))) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__a) 
                                                                                + 
                                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
                                                                                + 
                                                                                (vlSelf->top__DOT__imm 
                                                                                >> 1U))) 
                                                                                | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__u_adder0__a) 
                                                                                + vlSelf->top__DOT__imm))))))))))))))))))))))))))))))))))));
    bufp->fullIData(oldp+42,((((((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                                 << 0x1fU) & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                               << 0x1fU) 
                                              | (0x80000000U 
                                                 & vlSelf->top__DOT__imm))) 
                               | (0x80000000U & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                                  << 0x1fU) 
                                                 & vlSelf->top__DOT__imm))) 
                              | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                  << 0x1eU) | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
                                                << 0x1dU) 
                                               | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
                                                   << 0x1cU) 
                                                  | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
                                                      << 0x1bU) 
                                                     | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin) 
                                                         << 0x1aU) 
                                                        | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin) 
                                                            << 0x19U) 
                                                           | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin) 
                                                               << 0x18U) 
                                                              | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin) 
                                                                  << 0x17U) 
                                                                 | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin) 
                                                                     << 0x16U) 
                                                                    | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin) 
                                                                        << 0x15U) 
                                                                       | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin) 
                                                                           << 0x14U) 
                                                                          | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin) 
                                                                              << 0x13U) 
                                                                             | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin))))))))))))))))))))))))))))))))),32);
    bufp->fullBit(oldp+43,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+44,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+45,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+46,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0xaU))))));
    bufp->fullBit(oldp+47,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+48,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+49,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0xbU))))));
    bufp->fullBit(oldp+50,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+51,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+52,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0xcU))))));
    bufp->fullBit(oldp+53,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+54,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+55,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0xdU))))));
    bufp->fullBit(oldp+56,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+57,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+58,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0xeU))))));
    bufp->fullBit(oldp+59,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+60,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+61,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0xfU))))));
    bufp->fullBit(oldp+62,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+63,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+64,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0x10U))))));
    bufp->fullBit(oldp+65,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+66,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+67,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0x11U))))));
    bufp->fullBit(oldp+68,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+69,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+70,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0x12U))))));
    bufp->fullBit(oldp+71,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+72,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+73,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0x13U))))));
    bufp->fullBit(oldp+74,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+75,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+76,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+77,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 1U))))));
    bufp->fullBit(oldp+78,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+79,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+80,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0x14U))))));
    bufp->fullBit(oldp+81,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+82,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+83,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0x15U))))));
    bufp->fullBit(oldp+84,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+85,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+86,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0x16U))))));
    bufp->fullBit(oldp+87,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+88,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+89,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0x17U))))));
    bufp->fullBit(oldp+90,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+91,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+92,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0x18U))))));
    bufp->fullBit(oldp+93,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+94,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+95,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0x19U))))));
    bufp->fullBit(oldp+96,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+97,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+98,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__a) 
                                  + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin) 
                                     + (vlSelf->top__DOT__imm 
                                        >> 0x1aU))))));
    bufp->fullBit(oldp+99,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+100,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+101,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 0x1bU))))));
    bufp->fullBit(oldp+102,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+103,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+104,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 0x1cU))))));
    bufp->fullBit(oldp+105,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+106,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+107,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 0x1dU))))));
    bufp->fullBit(oldp+108,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+109,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+110,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 2U))))));
    bufp->fullBit(oldp+111,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+112,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+113,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 0x1eU))))));
    bufp->fullBit(oldp+114,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+115,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 0x1fU))))));
    bufp->fullBit(oldp+116,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+117,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+118,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 3U))))));
    bufp->fullBit(oldp+119,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+120,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+121,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 4U))))));
    bufp->fullBit(oldp+122,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+123,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+124,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 5U))))));
    bufp->fullBit(oldp+125,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+126,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+127,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 6U))))));
    bufp->fullBit(oldp+128,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+129,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+130,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 7U))))));
    bufp->fullBit(oldp+131,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+132,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin));
    bufp->fullBit(oldp+133,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 8U))))));
    bufp->fullBit(oldp+134,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__a));
    bufp->fullBit(oldp+135,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 9U))))));
    bufp->fullBit(oldp+136,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__u_adder0__a));
    bufp->fullBit(oldp+137,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__u_adder0__a) 
                                   + vlSelf->top__DOT__imm))));
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[0]),32);
    bufp->fullIData(oldp+139,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[1]),32);
    bufp->fullIData(oldp+140,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[2]),32);
    bufp->fullIData(oldp+141,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[3]),32);
    bufp->fullIData(oldp+142,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[4]),32);
    bufp->fullIData(oldp+143,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[5]),32);
    bufp->fullIData(oldp+144,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[6]),32);
    bufp->fullIData(oldp+145,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[7]),32);
    bufp->fullIData(oldp+146,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[8]),32);
    bufp->fullIData(oldp+147,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[9]),32);
    bufp->fullIData(oldp+148,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[10]),32);
    bufp->fullIData(oldp+149,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[11]),32);
    bufp->fullIData(oldp+150,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[12]),32);
    bufp->fullIData(oldp+151,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[13]),32);
    bufp->fullIData(oldp+152,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[14]),32);
    bufp->fullIData(oldp+153,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[15]),32);
    bufp->fullIData(oldp+154,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[16]),32);
    bufp->fullIData(oldp+155,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[17]),32);
    bufp->fullIData(oldp+156,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[18]),32);
    bufp->fullIData(oldp+157,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[19]),32);
    bufp->fullIData(oldp+158,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[20]),32);
    bufp->fullIData(oldp+159,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[21]),32);
    bufp->fullIData(oldp+160,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[22]),32);
    bufp->fullIData(oldp+161,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[23]),32);
    bufp->fullIData(oldp+162,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[24]),32);
    bufp->fullIData(oldp+163,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[25]),32);
    bufp->fullIData(oldp+164,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[26]),32);
    bufp->fullIData(oldp+165,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[27]),32);
    bufp->fullIData(oldp+166,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[28]),32);
    bufp->fullIData(oldp+167,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[29]),32);
    bufp->fullIData(oldp+168,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[30]),32);
    bufp->fullIData(oldp+169,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[31]),32);
    bufp->fullBit(oldp+170,(vlSelf->clk));
    bufp->fullBit(oldp+171,(vlSelf->rst));
    bufp->fullIData(oldp+172,(vlSelf->inst),32);
    bufp->fullIData(oldp+173,(vlSelf->pc),32);
    bufp->fullIData(oldp+174,(((((~ ((IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_h8e5fb8c0__0) 
                                     | ((0x37U == (0x7fU 
                                                   & vlSelf->inst)) 
                                        | (0x17U == 
                                           (0x7fU & vlSelf->inst))))) 
                                 & ((0x6fU != (0x7fU 
                                               & vlSelf->inst)) 
                                    & (IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_he6c9fe4d__0)))
                                 ? vlSelf->top__DOT__src1
                                 : vlSelf->pc) + ((
                                                   (~ 
                                                    ((IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_h8e5fb8c0__0) 
                                                     | ((0x37U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelf->inst)) 
                                                        | (0x17U 
                                                           == 
                                                           (0x7fU 
                                                            & vlSelf->inst))))) 
                                                   & ((0x6fU 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->inst)) 
                                                      | (IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_he6c9fe4d__0)))
                                                   ? vlSelf->top__DOT__imm
                                                   : 4U))),32);
    bufp->fullCData(oldp+175,((((IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_h8e5fb8c0__0) 
                                | ((0x37U == (0x7fU 
                                              & vlSelf->inst)) 
                                   | (0x17U == (0x7fU 
                                                & vlSelf->inst))))
                                ? 0U : ((0x6fU == (0x7fU 
                                                   & vlSelf->inst))
                                         ? 1U : ((IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_he6c9fe4d__0)
                                                  ? 3U
                                                  : 0U)))),2);
    bufp->fullCData(oldp+176,((0x7fU & vlSelf->inst)),7);
    bufp->fullCData(oldp+177,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullCData(oldp+178,((vlSelf->inst >> 0x19U)),7);
    bufp->fullCData(oldp+179,((0x1fU & (vlSelf->inst 
                                        >> 7U))),5);
    bufp->fullCData(oldp+180,((0x1fU & (vlSelf->inst 
                                        >> 0xfU))),5);
    bufp->fullIData(oldp+181,((vlSelf->inst >> 7U)),25);
    bufp->fullBit(oldp+182,(1U));
    bufp->fullBit(oldp+183,(0U));
    bufp->fullIData(oldp+184,(5U),32);
    bufp->fullIData(oldp+185,(0x20U),32);
}
