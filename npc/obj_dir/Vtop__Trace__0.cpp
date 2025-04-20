// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+0,(vlSelf->top__DOT__rdata),32);
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+2,((1U & (vlSelf->top__DOT__rdata 
                                    >> 0xaU))));
        bufp->chgBit(oldp+3,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+4,((1U & (vlSelf->top__DOT__rdata 
                                    >> 0xbU))));
        bufp->chgBit(oldp+5,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+6,((1U & (vlSelf->top__DOT__rdata 
                                    >> 0xcU))));
        bufp->chgBit(oldp+7,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+8,((1U & (vlSelf->top__DOT__rdata 
                                    >> 0xdU))));
        bufp->chgBit(oldp+9,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+10,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0xeU))));
        bufp->chgBit(oldp+11,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+12,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0xfU))));
        bufp->chgBit(oldp+13,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+14,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x10U))));
        bufp->chgBit(oldp+15,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+16,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x11U))));
        bufp->chgBit(oldp+17,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+18,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x12U))));
        bufp->chgBit(oldp+19,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+20,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x13U))));
        bufp->chgBit(oldp+21,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+22,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+23,((1U & (vlSelf->top__DOT__rdata 
                                     >> 1U))));
        bufp->chgBit(oldp+24,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+25,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x14U))));
        bufp->chgBit(oldp+26,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+27,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x15U))));
        bufp->chgBit(oldp+28,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+29,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x16U))));
        bufp->chgBit(oldp+30,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+31,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x17U))));
        bufp->chgBit(oldp+32,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+33,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x18U))));
        bufp->chgBit(oldp+34,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+35,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x19U))));
        bufp->chgBit(oldp+36,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+37,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x1aU))));
        bufp->chgBit(oldp+38,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+39,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x1bU))));
        bufp->chgBit(oldp+40,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+41,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x1cU))));
        bufp->chgBit(oldp+42,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+43,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x1dU))));
        bufp->chgBit(oldp+44,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+45,((1U & (vlSelf->top__DOT__rdata 
                                     >> 2U))));
        bufp->chgBit(oldp+46,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+47,((1U & (vlSelf->top__DOT__rdata 
                                     >> 0x1eU))));
        bufp->chgBit(oldp+48,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+49,((vlSelf->top__DOT__rdata 
                               >> 0x1fU)));
        bufp->chgBit(oldp+50,((1U & (vlSelf->top__DOT__rdata 
                                     >> 3U))));
        bufp->chgBit(oldp+51,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+52,((1U & (vlSelf->top__DOT__rdata 
                                     >> 4U))));
        bufp->chgBit(oldp+53,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+54,((1U & (vlSelf->top__DOT__rdata 
                                     >> 5U))));
        bufp->chgBit(oldp+55,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+56,((1U & (vlSelf->top__DOT__rdata 
                                     >> 6U))));
        bufp->chgBit(oldp+57,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+58,((1U & (vlSelf->top__DOT__rdata 
                                     >> 7U))));
        bufp->chgBit(oldp+59,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+60,((1U & (vlSelf->top__DOT__rdata 
                                     >> 8U))));
        bufp->chgBit(oldp+61,(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+62,((1U & (vlSelf->top__DOT__rdata 
                                     >> 9U))));
        bufp->chgBit(oldp+63,((1U & vlSelf->top__DOT__rdata)));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+64,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[0]),32);
        bufp->chgIData(oldp+65,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[1]),32);
        bufp->chgIData(oldp+66,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[2]),32);
        bufp->chgIData(oldp+67,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[3]),32);
        bufp->chgIData(oldp+68,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[4]),32);
        bufp->chgIData(oldp+69,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[5]),32);
        bufp->chgIData(oldp+70,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[6]),32);
        bufp->chgIData(oldp+71,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[7]),32);
        bufp->chgIData(oldp+72,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[8]),32);
        bufp->chgIData(oldp+73,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[9]),32);
        bufp->chgIData(oldp+74,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[10]),32);
        bufp->chgIData(oldp+75,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[11]),32);
        bufp->chgIData(oldp+76,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[12]),32);
        bufp->chgIData(oldp+77,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[13]),32);
        bufp->chgIData(oldp+78,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[14]),32);
        bufp->chgIData(oldp+79,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[15]),32);
        bufp->chgIData(oldp+80,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[16]),32);
        bufp->chgIData(oldp+81,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[17]),32);
        bufp->chgIData(oldp+82,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[18]),32);
        bufp->chgIData(oldp+83,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[19]),32);
        bufp->chgIData(oldp+84,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[20]),32);
        bufp->chgIData(oldp+85,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[21]),32);
        bufp->chgIData(oldp+86,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[22]),32);
        bufp->chgIData(oldp+87,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[23]),32);
        bufp->chgIData(oldp+88,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[24]),32);
        bufp->chgIData(oldp+89,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[25]),32);
        bufp->chgIData(oldp+90,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[26]),32);
        bufp->chgIData(oldp+91,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[27]),32);
        bufp->chgIData(oldp+92,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[28]),32);
        bufp->chgIData(oldp+93,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[29]),32);
        bufp->chgIData(oldp+94,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[30]),32);
        bufp->chgIData(oldp+95,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[31]),32);
        bufp->chgIData(oldp+96,(vlSelf->top__DOT__u_PC__DOT__pc),32);
    }
    bufp->chgBit(oldp+97,(vlSelf->clk));
    bufp->chgBit(oldp+98,(vlSelf->rst));
    bufp->chgIData(oldp+99,(vlSelf->inst),32);
    bufp->chgIData(oldp+100,(vlSelf->pc),32);
    bufp->chgBit(oldp+101,(((0U != (0x1fU & (vlSelf->inst 
                                             >> 7U))) 
                            & (IData)(vlSelf->top__DOT__addi_en))));
    bufp->chgBit(oldp+102,(vlSelf->top__DOT__addi_en));
    bufp->chgBit(oldp+103,((IData)((0x73U == (0x707fU 
                                              & vlSelf->inst)))));
    bufp->chgCData(oldp+104,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->chgCData(oldp+105,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->chgIData(oldp+106,(((((vlSelf->top__DOT__rdata 
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
    bufp->chgIData(oldp+107,(((((vlSelf->inst >> 0x1fU)
                                 ? 0xfffffU : 0U) << 0xcU) 
                              | (vlSelf->inst >> 0x14U))),32);
    bufp->chgBit(oldp+108,((1U & (((vlSelf->top__DOT__rdata 
                                    >> 0x1fU) & ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin))) 
                                  | ((vlSelf->inst 
                                      >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+109,((((vlSelf->top__DOT__rdata 
                              >> 0x1fU) == (1U & ((
                                                   (vlSelf->inst 
                                                    >> 0x1fU)
                                                    ? 0xfffffU
                                                    : 0U) 
                                                  >> 0x13U))) 
                            & ((1U & ((vlSelf->top__DOT__rdata 
                                       >> 0x1fU) + 
                                      ((vlSelf->inst 
                                        >> 0x1fU) + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin)))) 
                               != (vlSelf->top__DOT__rdata 
                                   >> 0x1fU)))));
    bufp->chgBit(oldp+110,((1U & (~ (((vlSelf->top__DOT__rdata 
                                       >> 0x1fU) + 
                                      ((vlSelf->inst 
                                        >> 0x1fU) + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin))) 
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
                                               + ((vlSelf->inst 
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
    bufp->chgIData(oldp+111,(((0x80000000U & ((vlSelf->top__DOT__rdata 
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
    bufp->chgBit(oldp+112,((1U & (vlSelf->inst >> 0x1eU))));
    bufp->chgBit(oldp+113,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0xaU) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                                               + (vlSelf->inst 
                                                  >> 0x1eU))))));
    bufp->chgBit(oldp+114,((vlSelf->inst >> 0x1fU)));
    bufp->chgBit(oldp+115,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0xbU) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                                               + (vlSelf->inst 
                                                  >> 0x1fU))))));
    bufp->chgBit(oldp+116,((vlSelf->inst >> 0x1fU)));
    bufp->chgBit(oldp+117,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0xcU) + ((vlSelf->inst 
                                                >> 0x1fU) 
                                               + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+118,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0xdU) + ((vlSelf->inst 
                                                >> 0x1fU) 
                                               + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+119,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0xeU) + ((vlSelf->inst 
                                                >> 0x1fU) 
                                               + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+120,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0xfU) + ((vlSelf->inst 
                                                >> 0x1fU) 
                                               + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+121,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x10U) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+122,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x11U) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+123,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x12U) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+124,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x13U) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+125,((1U & (vlSelf->inst >> 0x15U))));
    bufp->chgBit(oldp+126,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 1U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
                                             + (vlSelf->inst 
                                                >> 0x15U))))));
    bufp->chgBit(oldp+127,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x14U) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+128,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x15U) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+129,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x16U) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+130,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x17U) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+131,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x18U) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+132,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x19U) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+133,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x1aU) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+134,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x1bU) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+135,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x1cU) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+136,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x1dU) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+137,((1U & (vlSelf->inst >> 0x16U))));
    bufp->chgBit(oldp+138,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 2U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                                             + (vlSelf->inst 
                                                >> 0x16U))))));
    bufp->chgBit(oldp+139,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x1eU) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+140,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 0x1fU) + ((vlSelf->inst 
                                                 >> 0x1fU) 
                                                + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin))))));
    bufp->chgBit(oldp+141,((1U & (vlSelf->inst >> 0x17U))));
    bufp->chgBit(oldp+142,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 3U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                                             + (vlSelf->inst 
                                                >> 0x17U))))));
    bufp->chgBit(oldp+143,((1U & (vlSelf->inst >> 0x18U))));
    bufp->chgBit(oldp+144,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 4U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                                             + (vlSelf->inst 
                                                >> 0x18U))))));
    bufp->chgBit(oldp+145,((1U & (vlSelf->inst >> 0x19U))));
    bufp->chgBit(oldp+146,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 5U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                                             + (vlSelf->inst 
                                                >> 0x19U))))));
    bufp->chgBit(oldp+147,((1U & (vlSelf->inst >> 0x1aU))));
    bufp->chgBit(oldp+148,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 6U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                                             + (vlSelf->inst 
                                                >> 0x1aU))))));
    bufp->chgBit(oldp+149,((1U & (vlSelf->inst >> 0x1bU))));
    bufp->chgBit(oldp+150,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 7U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                                             + (vlSelf->inst 
                                                >> 0x1bU))))));
    bufp->chgBit(oldp+151,((1U & (vlSelf->inst >> 0x1cU))));
    bufp->chgBit(oldp+152,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 8U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                                             + (vlSelf->inst 
                                                >> 0x1cU))))));
    bufp->chgBit(oldp+153,((1U & (vlSelf->inst >> 0x1dU))));
    bufp->chgBit(oldp+154,((1U & ((vlSelf->top__DOT__rdata 
                                   >> 9U) + ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                                             + (vlSelf->inst 
                                                >> 0x1dU))))));
    bufp->chgBit(oldp+155,((1U & (vlSelf->inst >> 0x14U))));
    bufp->chgBit(oldp+156,((1U & (vlSelf->top__DOT__rdata 
                                  + (vlSelf->inst >> 0x14U)))));
    bufp->chgCData(oldp+157,((0x7fU & vlSelf->inst)),7);
    bufp->chgCData(oldp+158,((7U & (vlSelf->inst >> 0xcU))),3);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
