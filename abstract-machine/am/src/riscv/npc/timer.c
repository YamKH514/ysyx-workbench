#include <am.h>

#define DEVICE_BASE 0xa0000000
#define RTC_ADDR    (DEVICE_BASE + 0x0000048)

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t hi, lo;
  asm volatile("lw %0, 4(%1)" : "=r"(hi):  "r"(RTC_ADDR));
  asm volatile("lw %0, 0(%1)" : "=r"(lo):  "r"(RTC_ADDR));
  uptime->us = (((uint64_t)hi << 32) | (uint64_t)lo) * 5;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
