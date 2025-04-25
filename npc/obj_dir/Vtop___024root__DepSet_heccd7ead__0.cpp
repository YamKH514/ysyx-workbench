// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

void Vtop___024root____Vdpiimwrap_top__DOT__u_Decode__DOT__ebreak_trigger_TOP();

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    if ((0x6fU == (0x7fU & vlSelf->inst))) {
        Vtop___024root____Vdpiimwrap_top__DOT__u_Decode__DOT__ebreak_trigger_TOP();
    }
    vlSelf->top__DOT__src1 = vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf
        [(0x1fU & (vlSelf->inst >> 0xfU))];
    vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_h8e5fb8c0__0 
        = (IData)((0x13U == (0x707fU & vlSelf->inst)));
    vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_he6c9fe4d__0 
        = (IData)((0x67U == (0x707fU & vlSelf->inst)));
    vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_hbc9923dd__0 
        = ((IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_h8e5fb8c0__0) 
           | (IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_he6c9fe4d__0));
    vlSelf->top__DOT__imm_type = ((IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_hbc9923dd__0)
                                   ? 0U : (((0x17U 
                                             == (0x7fU 
                                                 & vlSelf->inst)) 
                                            | (0x37U 
                                               == (0x7fU 
                                                   & vlSelf->inst)))
                                            ? 3U : 
                                           ((0x6fU 
                                             == (0x7fU 
                                                 & vlSelf->inst))
                                             ? 4U : 0U)));
    vlSelf->top__DOT__src1_sel = ((0x37U == (0x7fU 
                                             & vlSelf->inst))
                                   ? 0U : (((0x17U 
                                             == (0x7fU 
                                                 & vlSelf->inst)) 
                                            | (0x6fU 
                                               == (0x7fU 
                                                   & vlSelf->inst)))
                                            ? 1U : 
                                           ((IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_hbc9923dd__0)
                                             ? 2U : 0U)));
    vlSelf->top__DOT__imm = ((0U == (IData)(vlSelf->top__DOT__imm_type))
                              ? (((- (IData)((vlSelf->inst 
                                              >> 0x1fU))) 
                                  << 0xbU) | (0x7ffU 
                                              & (vlSelf->inst 
                                                 >> 0x14U)))
                              : ((1U == (IData)(vlSelf->top__DOT__imm_type))
                                  ? (((- (IData)((vlSelf->inst 
                                                  >> 0x1fU))) 
                                      << 0xbU) | ((0x7e0U 
                                                   & (vlSelf->inst 
                                                      >> 0x14U)) 
                                                  | (0x1fU 
                                                     & (vlSelf->inst 
                                                        >> 7U))))
                                  : ((2U == (IData)(vlSelf->top__DOT__imm_type))
                                      ? (((- (IData)(
                                                     (vlSelf->inst 
                                                      >> 0x1fU))) 
                                          << 0xeU) 
                                         | ((0x3800U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & (vlSelf->inst 
                                                               >> 7U)))) 
                                                << 0xbU)) 
                                            | ((0x7e0U 
                                                & (vlSelf->inst 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelf->inst 
                                                     >> 7U)))))
                                      : ((3U == (IData)(vlSelf->top__DOT__imm_type))
                                          ? (0xfffff000U 
                                             & vlSelf->inst)
                                          : ((4U == (IData)(vlSelf->top__DOT__imm_type))
                                              ? (((- (IData)(
                                                             (vlSelf->inst 
                                                              >> 0x1fU))) 
                                                  << 0x14U) 
                                                 | ((0xff000U 
                                                     & vlSelf->inst) 
                                                    | ((0x800U 
                                                        & (vlSelf->inst 
                                                           >> 9U)) 
                                                       | (0x7feU 
                                                          & (vlSelf->inst 
                                                             >> 0x14U)))))
                                              : 0U)))));
    vlSelf->__VdfgTmp_h1bde3cb9__0 = ((1U == (IData)(vlSelf->top__DOT__src1_sel))
                                       ? vlSelf->pc
                                       : ((2U == (IData)(vlSelf->top__DOT__src1_sel))
                                           ? vlSelf->top__DOT__src1
                                           : 0U));
    vlSelf->top__DOT__npc = ((((~ ((IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_h8e5fb8c0__0) 
                                   | ((0x37U == (0x7fU 
                                                 & vlSelf->inst)) 
                                      | (0x17U == (0x7fU 
                                                   & vlSelf->inst))))) 
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
                                                 : 4U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x1fU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x1eU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x1dU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x1cU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x1bU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x1aU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x19U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x18U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x17U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x16U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x15U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x14U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x13U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x12U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x11U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x10U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0xfU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0xeU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0xdU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0xcU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0xbU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0xaU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 9U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 8U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 7U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 6U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 5U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 4U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 3U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 2U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 1U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__u_adder0__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & vlSelf->__VdfgTmp_h1bde3cb9__0);
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin 
        = ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__u_adder0__a) 
           & vlSelf->top__DOT__imm);
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 1U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 1U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 2U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 2U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 3U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 3U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 4U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 4U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 5U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 5U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 6U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 6U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 7U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 7U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 8U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 8U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 9U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 9U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0xaU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0xaU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0xbU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0xbU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0xcU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0xcU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0xdU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0xdU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0xeU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0xeU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0xfU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0xfU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x10U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x10U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x11U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x11U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x12U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x12U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x13U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x13U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x14U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x14U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x15U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x15U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x16U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x16U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x17U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x17U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x18U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x18U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x19U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x19U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x1aU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x1aU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x1bU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x1bU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x1cU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x1cU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x1dU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x1dU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x1eU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x1eU)));
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

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0;
    __Vdlyvdim0__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0;
    __Vdlyvval__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0 = 0;
    // Body
    __Vdlyvval__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0 
        = ((((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a) 
             + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin) 
                + (vlSelf->top__DOT__imm >> 0x1fU))) 
            << 0x1fU) | ((0x40000000U & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a) 
                                          + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
                                             + (vlSelf->top__DOT__imm 
                                                >> 0x1eU))) 
                                         << 0x1eU)) 
                         | ((0x20000000U & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a) 
                                             + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
                                                + (vlSelf->top__DOT__imm 
                                                   >> 0x1dU))) 
                                            << 0x1dU)) 
                            | ((0x10000000U & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a) 
                                                + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
                                                   + 
                                                   (vlSelf->top__DOT__imm 
                                                    >> 0x1cU))) 
                                               << 0x1cU)) 
                               | ((0x8000000U & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__a) 
                                                  + 
                                                  ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin) 
                                                   + 
                                                   (vlSelf->top__DOT__imm 
                                                    >> 0x1bU))) 
                                                 << 0x1bU)) 
                                  | ((0x4000000U & 
                                      (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__a) 
                                        + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin) 
                                           + (vlSelf->top__DOT__imm 
                                              >> 0x1aU))) 
                                       << 0x1aU)) | 
                                     ((0x2000000U & 
                                       (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__a) 
                                         + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin) 
                                            + (vlSelf->top__DOT__imm 
                                               >> 0x19U))) 
                                        << 0x19U)) 
                                      | ((0x1000000U 
                                          & (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__a) 
                                              + ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin) 
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
                                                                                + vlSelf->top__DOT__imm)))))))))))))))))))))))))))))))));
    __Vdlyvdim0__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0 
        = (0x1fU & (vlSelf->inst >> 7U));
    vlSelf->pc = ((IData)(vlSelf->rst) ? 0x80000000U
                   : vlSelf->top__DOT__npc);
    vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf[__Vdlyvdim0__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0] 
        = __Vdlyvval__top__DOT__u_GPR__DOT__general_reg__DOT__rf__v0;
    vlSelf->top__DOT__src1 = vlSelf->top__DOT__u_GPR__DOT__general_reg__DOT__rf
        [(0x1fU & (vlSelf->inst >> 0xfU))];
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->__VdfgTmp_h1bde3cb9__0 = ((1U == (IData)(vlSelf->top__DOT__src1_sel))
                                       ? vlSelf->pc
                                       : ((2U == (IData)(vlSelf->top__DOT__src1_sel))
                                           ? vlSelf->top__DOT__src1
                                           : 0U));
    vlSelf->top__DOT__npc = ((((~ ((IData)(vlSelf->top__DOT__u_Decode__DOT____VdfgTmp_h8e5fb8c0__0) 
                                   | ((0x37U == (0x7fU 
                                                 & vlSelf->inst)) 
                                      | (0x17U == (0x7fU 
                                                   & vlSelf->inst))))) 
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
                                                 : 4U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x1fU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x1eU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x1dU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x1cU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x1bU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x1aU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x19U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x18U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x17U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x16U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x15U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x14U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x13U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x12U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x11U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0x10U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0xfU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0xeU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0xdU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0xcU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0xbU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 0xaU));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 9U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 8U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 7U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 6U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 5U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 4U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 3U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 2U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & (vlSelf->__VdfgTmp_h1bde3cb9__0 >> 1U));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__u_adder0__a 
        = ((0U != (IData)(vlSelf->top__DOT__src1_sel)) 
           & vlSelf->__VdfgTmp_h1bde3cb9__0);
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin 
        = ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__u_adder0__a) 
           & vlSelf->top__DOT__imm);
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 1U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__1__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 1U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 2U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__2__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 2U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 3U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__3__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 3U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 4U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__4__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 4U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 5U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__5__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 5U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 6U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__6__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 6U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 7U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__7__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 7U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 8U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__8__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 8U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 9U))) | 
           ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__9__KET____DOT__u_adder1__Cin) 
            & (vlSelf->top__DOT__imm >> 9U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0xaU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__10__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0xaU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0xbU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__11__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0xbU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0xcU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__12__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0xcU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0xdU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__13__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0xdU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0xeU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__14__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0xeU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0xfU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__15__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0xfU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x10U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__16__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x10U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x11U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__17__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x11U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x12U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__18__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x12U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x13U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__19__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x13U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x14U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__20__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x14U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x15U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__21__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x15U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x16U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__22__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x16U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x17U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__23__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x17U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x18U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__24__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x18U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x19U))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__25__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x19U)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x1aU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__26__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x1aU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x1bU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__27__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x1bU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x1cU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__28__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x1cU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x1dU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__29__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x1dU)));
    vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__31__KET____DOT__u_adder1__Cin 
        = (((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__a) 
            & ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
               | (vlSelf->top__DOT__imm >> 0x1eU))) 
           | ((IData)(vlSelf->top__DOT__u_ADD__DOT__u_adder32__DOT____Vcellinp__gen_add__BRA__30__KET____DOT__u_adder1__Cin) 
              & (vlSelf->top__DOT__imm >> 0x1eU)));
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
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
