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
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__imm_type),3);
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__src1_sel),2);
        bufp->chgIData(oldp+2,(vlSelf->top__DOT__imm),32);
        bufp->chgBit(oldp+3,((1U & (vlSelf->top__DOT__imm 
                                    >> 0xaU))));
        bufp->chgBit(oldp+4,((1U & (vlSelf->top__DOT__imm 
                                    >> 0xbU))));
        bufp->chgBit(oldp+5,((1U & (vlSelf->top__DOT__imm 
                                    >> 0xcU))));
        bufp->chgBit(oldp+6,((1U & (vlSelf->top__DOT__imm 
                                    >> 0xdU))));
        bufp->chgBit(oldp+7,((1U & (vlSelf->top__DOT__imm 
                                    >> 0xeU))));
        bufp->chgBit(oldp+8,((1U & (vlSelf->top__DOT__imm 
                                    >> 0xfU))));
        bufp->chgBit(oldp+9,((1U & (vlSelf->top__DOT__imm 
                                    >> 0x10U))));
        bufp->chgBit(oldp+10,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x11U))));
        bufp->chgBit(oldp+11,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x12U))));
        bufp->chgBit(oldp+12,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x13U))));
        bufp->chgBit(oldp+13,((1U & (vlSelf->top__DOT__imm 
                                     >> 1U))));
        bufp->chgBit(oldp+14,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x14U))));
        bufp->chgBit(oldp+15,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x15U))));
        bufp->chgBit(oldp+16,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x16U))));
        bufp->chgBit(oldp+17,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x17U))));
        bufp->chgBit(oldp+18,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x18U))));
        bufp->chgBit(oldp+19,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x19U))));
        bufp->chgBit(oldp+20,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x1aU))));
        bufp->chgBit(oldp+21,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x1bU))));
        bufp->chgBit(oldp+22,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x1cU))));
        bufp->chgBit(oldp+23,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x1dU))));
        bufp->chgBit(oldp+24,((1U & (vlSelf->top__DOT__imm 
                                     >> 2U))));
        bufp->chgBit(oldp+25,((1U & (vlSelf->top__DOT__imm 
                                     >> 0x1eU))));
        bufp->chgBit(oldp+26,((vlSelf->top__DOT__imm 
                               >> 0x1fU)));
        bufp->chgBit(oldp+27,((1U & (vlSelf->top__DOT__imm 
                                     >> 3U))));
        bufp->chgBit(oldp+28,((1U & (vlSelf->top__DOT__imm 
                                     >> 4U))));
        bufp->chgBit(oldp+29,((1U & (vlSelf->top__DOT__imm 
                                     >> 5U))));
        bufp->chgBit(oldp+30,((1U & (vlSelf->top__DOT__imm 
                                     >> 6U))));
        bufp->chgBit(oldp+31,((1U & (vlSelf->top__DOT__imm 
                                     >> 7U))));
        bufp->chgBit(oldp+32,((1U & (vlSelf->top__DOT__imm 
                                     >> 8U))));
        bufp->chgBit(oldp+33,((1U & (vlSelf->top__DOT__imm 
                                     >> 9U))));
        bufp->chgBit(oldp+34,((1U & vlSelf->top__DOT__imm)));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__src1),32);
        bufp->chgIData(oldp+36,(((0U == (IData)(vlSelf->top__DOT__src1_sel))
                                  ? 0U : vlSelf->__VdfgTmp_h1bde3cb9__0)),32);
        bufp->chgIData(oldp+37,(((((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                                   + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                      + (vlSelf->top__DOT__imm 
                                         >> 0x1fU))) 
                                  << 0x1fU) | ((0x40000000U 
                                                & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a) 
                                                    + 
                                                    ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
                                                     + 
                                                     (vlSelf->top__DOT__imm 
                                                      >> 0x1eU))) 
                                                   << 0x1eU)) 
                                               | ((0x20000000U 
                                                   & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a) 
                                                       + 
                                                       ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
                                                        + 
                                                        (vlSelf->top__DOT__imm 
                                                         >> 0x1dU))) 
                                                      << 0x1dU)) 
                                                  | ((0x10000000U 
                                                      & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a) 
                                                          + 
                                                          ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
                                                           + 
                                                           (vlSelf->top__DOT__imm 
                                                            >> 0x1cU))) 
                                                         << 0x1cU)) 
                                                     | ((0x8000000U 
                                                         & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__a) 
                                                             + 
                                                             ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin) 
                                                              + 
                                                              (vlSelf->top__DOT__imm 
                                                               >> 0x1bU))) 
                                                            << 0x1bU)) 
                                                        | ((0x4000000U 
                                                            & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__a) 
                                                                + 
                                                                ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin) 
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
        bufp->chgBit(oldp+38,((((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                                & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                   | (vlSelf->top__DOT__imm 
                                      >> 0x1fU))) | 
                               ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                & (vlSelf->top__DOT__imm 
                                   >> 0x1fU)))));
        bufp->chgBit(oldp+39,((((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                                == (vlSelf->top__DOT__imm 
                                    >> 0x1fU)) & ((1U 
                                                   & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                                                      + 
                                                      ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                                       + 
                                                       (vlSelf->top__DOT__imm 
                                                        >> 0x1fU)))) 
                                                  != (IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a)))));
        bufp->chgBit(oldp+40,((1U & (~ (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                                         + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                            + (vlSelf->top__DOT__imm 
                                               >> 0x1fU))) 
                                        | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a) 
                                            + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
                                               + (vlSelf->top__DOT__imm 
                                                  >> 0x1eU))) 
                                           | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a) 
                                               + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
                                                  + 
                                                  (vlSelf->top__DOT__imm 
                                                   >> 0x1dU))) 
                                              | (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a) 
                                                  + 
                                                  ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
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
        bufp->chgIData(oldp+41,((((((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                                    << 0x1fU) & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                                  << 0x1fU) 
                                                 | (0x80000000U 
                                                    & vlSelf->top__DOT__imm))) 
                                  | (0x80000000U & 
                                     (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                       << 0x1fU) & vlSelf->top__DOT__imm))) 
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
        bufp->chgBit(oldp+42,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+43,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+44,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+45,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0xaU))))));
        bufp->chgBit(oldp+46,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+47,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+48,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0xbU))))));
        bufp->chgBit(oldp+49,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+50,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+51,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0xcU))))));
        bufp->chgBit(oldp+52,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+53,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+54,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0xdU))))));
        bufp->chgBit(oldp+55,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+56,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+57,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0xeU))))));
        bufp->chgBit(oldp+58,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+59,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+60,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0xfU))))));
        bufp->chgBit(oldp+61,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+62,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+63,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0x10U))))));
        bufp->chgBit(oldp+64,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+65,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+66,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0x11U))))));
        bufp->chgBit(oldp+67,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+68,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+69,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0x12U))))));
        bufp->chgBit(oldp+70,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+71,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+72,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0x13U))))));
        bufp->chgBit(oldp+73,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+74,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+75,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+76,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 1U))))));
        bufp->chgBit(oldp+77,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+78,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+79,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0x14U))))));
        bufp->chgBit(oldp+80,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+81,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+82,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0x15U))))));
        bufp->chgBit(oldp+83,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+84,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+85,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0x16U))))));
        bufp->chgBit(oldp+86,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+87,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+88,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0x17U))))));
        bufp->chgBit(oldp+89,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+90,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+91,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0x18U))))));
        bufp->chgBit(oldp+92,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+93,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+94,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0x19U))))));
        bufp->chgBit(oldp+95,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+96,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+97,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__a) 
                                     + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin) 
                                        + (vlSelf->top__DOT__imm 
                                           >> 0x1aU))))));
        bufp->chgBit(oldp+98,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+99,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+100,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 0x1bU))))));
        bufp->chgBit(oldp+101,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+102,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+103,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 0x1cU))))));
        bufp->chgBit(oldp+104,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+105,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+106,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 0x1dU))))));
        bufp->chgBit(oldp+107,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+108,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+109,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 2U))))));
        bufp->chgBit(oldp+110,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+111,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+112,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 0x1eU))))));
        bufp->chgBit(oldp+113,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+114,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 0x1fU))))));
        bufp->chgBit(oldp+115,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+116,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+117,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 3U))))));
        bufp->chgBit(oldp+118,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+119,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+120,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 4U))))));
        bufp->chgBit(oldp+121,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+122,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+123,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 5U))))));
        bufp->chgBit(oldp+124,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+125,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+126,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 6U))))));
        bufp->chgBit(oldp+127,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+128,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+129,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 7U))))));
        bufp->chgBit(oldp+130,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+131,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin));
        bufp->chgBit(oldp+132,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 8U))))));
        bufp->chgBit(oldp+133,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__a));
        bufp->chgBit(oldp+134,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__a) 
                                      + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                                         + (vlSelf->top__DOT__imm 
                                            >> 9U))))));
        bufp->chgBit(oldp+135,(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__u_adder0__a));
        bufp->chgBit(oldp+136,((1U & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__u_adder0__a) 
                                      + vlSelf->top__DOT__imm))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+137,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[0]),32);
        bufp->chgIData(oldp+138,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[1]),32);
        bufp->chgIData(oldp+139,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[2]),32);
        bufp->chgIData(oldp+140,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[3]),32);
        bufp->chgIData(oldp+141,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[4]),32);
        bufp->chgIData(oldp+142,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[5]),32);
        bufp->chgIData(oldp+143,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[6]),32);
        bufp->chgIData(oldp+144,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[7]),32);
        bufp->chgIData(oldp+145,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[8]),32);
        bufp->chgIData(oldp+146,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[9]),32);
        bufp->chgIData(oldp+147,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[10]),32);
        bufp->chgIData(oldp+148,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[11]),32);
        bufp->chgIData(oldp+149,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[12]),32);
        bufp->chgIData(oldp+150,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[13]),32);
        bufp->chgIData(oldp+151,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[14]),32);
        bufp->chgIData(oldp+152,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[15]),32);
        bufp->chgIData(oldp+153,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[16]),32);
        bufp->chgIData(oldp+154,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[17]),32);
        bufp->chgIData(oldp+155,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[18]),32);
        bufp->chgIData(oldp+156,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[19]),32);
        bufp->chgIData(oldp+157,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[20]),32);
        bufp->chgIData(oldp+158,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[21]),32);
        bufp->chgIData(oldp+159,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[22]),32);
        bufp->chgIData(oldp+160,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[23]),32);
        bufp->chgIData(oldp+161,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[24]),32);
        bufp->chgIData(oldp+162,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[25]),32);
        bufp->chgIData(oldp+163,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[26]),32);
        bufp->chgIData(oldp+164,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[27]),32);
        bufp->chgIData(oldp+165,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[28]),32);
        bufp->chgIData(oldp+166,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[29]),32);
        bufp->chgIData(oldp+167,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[30]),32);
        bufp->chgIData(oldp+168,(vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+169,(vlSelf->clk));
    bufp->chgBit(oldp+170,(vlSelf->rst));
    bufp->chgIData(oldp+171,(vlSelf->inst),32);
    bufp->chgIData(oldp+172,(vlSelf->pc),32);
    bufp->chgIData(oldp+173,(((((~ ((IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_h8e5fb8c0__0) 
                                    | ((0x37U == (0x7fU 
                                                  & vlSelf->inst)) 
                                       | (0x17U == 
                                          (0x7fU & vlSelf->inst))))) 
                                & ((0x6fU != (0x7fU 
                                              & vlSelf->inst)) 
                                   & (IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_he6c9fe4d__0)))
                                ? vlSelf->top__DOT__src1
                                : vlSelf->pc) + (((~ 
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
    bufp->chgCData(oldp+174,((((IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_h8e5fb8c0__0) 
                               | ((0x37U == (0x7fU 
                                             & vlSelf->inst)) 
                                  | (0x17U == (0x7fU 
                                               & vlSelf->inst))))
                               ? 0U : ((0x6fU == (0x7fU 
                                                  & vlSelf->inst))
                                        ? 1U : ((IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_he6c9fe4d__0)
                                                 ? 3U
                                                 : 0U)))),2);
    bufp->chgCData(oldp+175,((0x7fU & vlSelf->inst)),7);
    bufp->chgCData(oldp+176,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->chgCData(oldp+177,((vlSelf->inst >> 0x19U)),7);
    bufp->chgCData(oldp+178,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->chgCData(oldp+179,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->chgIData(oldp+180,((vlSelf->inst >> 7U)),25);
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
