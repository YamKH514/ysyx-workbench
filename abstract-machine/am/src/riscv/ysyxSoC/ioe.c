#include <am.h>
#include <klib-macros.h>
#include <kbd.h>

#define WIDTH  640
#define HEIGHT 480

void __am_timer_init();

void __am_timer_rtc(AM_TIMER_RTC_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);
void __am_uart_getch(AM_UART_RX_T *);
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *draw);

static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) { cfg->present = true; cfg->has_rtc = true; }
static void __am_input_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true;  }
static void __am_uart_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true;  }
static void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
    cfg->width  = WIDTH;
    cfg->height = HEIGHT;
    cfg->vmemsz = WIDTH * HEIGHT * sizeof(uint32_t);
}

typedef void (*handler_t)(void *buf);
static void *lut[128] = {
  [AM_TIMER_CONFIG] = __am_timer_config,
  [AM_TIMER_RTC   ] = __am_timer_rtc,
  [AM_TIMER_UPTIME] = __am_timer_uptime,
  [AM_INPUT_CONFIG] = __am_input_config,
  [AM_INPUT_KEYBRD] = __am_input_keybrd,
  [AM_UART_CONFIG]  = __am_uart_config,
  [AM_UART_RX]      = __am_uart_getch,
  [AM_GPU_CONFIG]   = __am_gpu_config,
  [AM_GPU_FBDRAW]   = __am_gpu_fbdraw,
};

static void fail(void *buf) { panic("access nonexist register"); }

bool ioe_init() {
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i]) lut[i] = fail;
  __am_timer_init();
  return true;
}

void ioe_read (int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }

void __am_uart_getch(AM_UART_RX_T *rx) {
  extern char getch();
  rx->data = getch();
}

void __am_input_keybrd(AM_INPUT_KEYBRD_T *key) {
  extern uint8_t getkey();
  static int keydown = true;
  static int extend = false;
  const uint8_t key_val = getkey();

  key->keydown = false;
  key->keycode = AM_KEY_NONE;

  if (key_val == 0xF0) {
    keydown = false;
  } else if (key_val == 0xE0) {
    extend = 1;
  } else if (key_val != 0x00) {
    key->keydown = keydown;
    key->keycode = extend ? SCANCODE_EXTEND[key_val] : SCANCODE_NORMAL[key_val];
    keydown = true;
    extend = false;
  }
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *draw) {
  extern void setpixel(uint32_t waddr, uint32_t haddr, uint32_t data);
  int x_start = draw->x;
  int y_start = draw->y;
  int w = draw->w;
  int h = draw->h;
  uint32_t *pixels = draw->pixels;
  int x = 0, y = 0;

  for (int i = 0; i < w * h; i++) {
      setpixel(x_start + x, y_start + y, pixels[i]);
      x++;
      if (x == w) {
          // 当前行扫描结束
          x = 0;
          y++;
      }
  }
}
