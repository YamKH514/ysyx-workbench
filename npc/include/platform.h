#ifndef PLATFORM_H__
#define PLATFORM_H__

#ifdef PLATFORM_YSYXSOC

#include "VysyxSoCFull.h"
#include "VysyxSoCFull__Dpi.h"
#include "VysyxSoCFull__Syms.h"
typedef VysyxSoCFull VTOP;

#define CPU_RESET top->rootp->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset
#define S_CPU(signal) top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__##signal
#define S_PCCnt(signal) top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_PCCnt__DOT__##signal
#define S_IFU(signal) top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_IFU__DOT__##signal
#define S_ICache_top(signal) top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_IFU__DOT__u_ICache_top__DOT__##signal
#define S_LSU(signal) top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_LSU__DOT__##signal
#define S_WBU(signal) top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_WBU__DOT__##signal

#else

#include "Vtop.h"
#include "Vtop__Dpi.h"
#include "Vtop__Syms.h"
typedef Vtop VTOP;

#define CPU_RESET top->reset
#define S_CPU(signal) top->rootp->top__DOT__##signal
#define S_PCCnt(signal) top->rootp->top__DOT__u_PCCnt__DOT__##signal
#define S_IFU(signal) top->rootp->top__DOT__u_IFU__DOT__##signal
#define S_ICache_top(signal) top->rootp->top__DOT__u_IFU__DOT__u_ICache_top__DOT__##signal
#define S_LSU(signal) top->rootp->top__DOT__u_LSU__DOT__##signal
#define S_WBU(signal) top->rootp->top__DOT__u_WBU__DOT__##signal

#endif

#endif
