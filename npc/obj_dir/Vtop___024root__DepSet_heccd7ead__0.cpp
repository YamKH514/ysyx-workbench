// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__addi_en = (IData)((0x13U == (0x707fU 
                                                   & vlSelf->inst)));
    vlSelf->top__DOT__rdata = vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf
        [(0x1fU & (vlSelf->inst >> 0xfU))];
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin 
        = (1U & (vlSelf->top__DOT__rdata & (vlSelf->inst 
                                            >> 0x14U)));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 1U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x15U))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x15U))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 2U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x16U))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x16U))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 3U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x17U))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x17U))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 4U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x18U))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x18U))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 5U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x19U))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x19U))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 6U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x1aU))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x1aU))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 7U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x1bU))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x1bU))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 8U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x1cU))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x1cU))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 9U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x1dU))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x1dU))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0xaU) 
                  & ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                     | (vlSelf->inst >> 0x1eU))) | 
                 ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                  & (vlSelf->inst >> 0x1eU))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0xbU) 
                  & ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                     | (vlSelf->inst >> 0x1fU))) | 
                 ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                  & (vlSelf->inst >> 0x1fU))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0xcU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0xdU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0xeU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0xfU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x10U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x11U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x12U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x13U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x14U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x15U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x16U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x17U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x18U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x19U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x1aU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x1bU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x1cU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x1dU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x1eU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin))));
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root____Vdpiimwrap_top__DOT__u_EBREAK__DOT__ebreak_trigger_TOP();

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0;
    __Vdlyvdim0__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0;
    __Vdlyvval__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0;
    __Vdlyvset__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdly__top__DOT__u_PC__DOT__pc;
    __Vdly__top__DOT__u_PC__DOT__pc = 0;
    // Body
    if ((IData)((0x73U == (0x707fU & vlSelf->inst)))) {
        Vtop___024root____Vdpiimwrap_top__DOT__u_EBREAK__DOT__ebreak_trigger_TOP();
    }
    __Vdly__top__DOT__u_PC__DOT__pc = vlSelf->top__DOT__u_PC__DOT__pc;
    __Vdlyvset__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0 = 0U;
    if (vlSelf->rst) {
        __Vdly__top__DOT__u_PC__DOT__pc = 0x80000000U;
    } else if (vlSelf->top__DOT__addi_en) {
        __Vdly__top__DOT__u_PC__DOT__pc = ((IData)(4U) 
                                           + vlSelf->top__DOT__u_PC__DOT__pc);
    }
    if (((0U != (0x1fU & (vlSelf->inst >> 7U))) & (IData)(vlSelf->top__DOT__addi_en))) {
        __Vdlyvval__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0 
            = ((((vlSelf->top__DOT__rdata >> 0x1fU) 
                 + ((vlSelf->inst >> 0x1fU) + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin))) 
                << 0x1fU) | ((0x40000000U & (((vlSelf->top__DOT__rdata 
                                               >> 0x1eU) 
                                              + ((vlSelf->inst 
                                                  >> 0x1fU) 
                                                 + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin))) 
                                             << 0x1eU)) 
                             | ((0x20000000U & (((vlSelf->top__DOT__rdata 
                                                  >> 0x1dU) 
                                                 + 
                                                 ((vlSelf->inst 
                                                   >> 0x1fU) 
                                                  + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin))) 
                                                << 0x1dU)) 
                                | ((0x10000000U & (
                                                   ((vlSelf->top__DOT__rdata 
                                                     >> 0x1cU) 
                                                    + 
                                                    ((vlSelf->inst 
                                                      >> 0x1fU) 
                                                     + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin))) 
                                                   << 0x1cU)) 
                                   | ((0x8000000U & 
                                       (((vlSelf->top__DOT__rdata 
                                          >> 0x1bU) 
                                         + ((vlSelf->inst 
                                             >> 0x1fU) 
                                            + (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin))) 
                                        << 0x1bU)) 
                                      | ((0x4000000U 
                                          & (((vlSelf->top__DOT__rdata 
                                               >> 0x1aU) 
                                              + ((vlSelf->inst 
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
                                                                                >> 0x14U))))))))))))))))))))))))))))))))));
        __Vdlyvset__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0 = 1U;
        __Vdlyvdim0__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0 
            = (0x1fU & (vlSelf->inst >> 7U));
    }
    vlSelf->top__DOT__u_PC__DOT__pc = __Vdly__top__DOT__u_PC__DOT__pc;
    if (__Vdlyvset__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0) {
        vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[__Vdlyvdim0__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0] 
            = __Vdlyvval__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0;
    }
    vlSelf->pc = vlSelf->top__DOT__u_PC__DOT__pc;
    vlSelf->top__DOT__rdata = vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf
        [(0x1fU & (vlSelf->inst >> 0xfU))];
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin 
        = (1U & (vlSelf->top__DOT__rdata & (vlSelf->inst 
                                            >> 0x14U)));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 1U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x15U))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x15U))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 2U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x16U))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x16U))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 3U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x17U))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x17U))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 4U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x18U))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x18U))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 5U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x19U))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x19U))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 6U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x1aU))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x1aU))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 7U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x1bU))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x1bU))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 8U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x1cU))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x1cU))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 9U) & 
                  ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                   | (vlSelf->inst >> 0x1dU))) | ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
                                                  & (vlSelf->inst 
                                                     >> 0x1dU))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0xaU) 
                  & ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                     | (vlSelf->inst >> 0x1eU))) | 
                 ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
                  & (vlSelf->inst >> 0x1eU))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0xbU) 
                  & ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                     | (vlSelf->inst >> 0x1fU))) | 
                 ((IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
                  & (vlSelf->inst >> 0x1fU))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0xcU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0xdU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0xeU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0xfU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x10U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x11U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x12U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x13U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x14U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x15U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x16U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x17U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x18U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x19U) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x1aU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x1bU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x1cU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x1dU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin))));
    vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin 
        = (1U & (((vlSelf->top__DOT__rdata >> 0x1eU) 
                  & ((vlSelf->inst >> 0x1fU) | (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin))) 
                 | ((vlSelf->inst >> 0x1fU) & (IData)(vlSelf->top__DOT__u_ADDI__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin))));
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
