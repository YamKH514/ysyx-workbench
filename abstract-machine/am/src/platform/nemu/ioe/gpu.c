#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
  // int i;
  // int w = 400;  // TODO: get the correct width
  // int h = 300;  // TODO: get the correct height
  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // for (i = 0; i < w * h; i ++) fb[i] = i;
  // outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t vga_clt = inl(VGACTL_ADDR);
  uint32_t width = (vga_clt & 0xFFFF0000) >> 16;
  uint32_t height = vga_clt & 0x0000FFFF;
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = width, .height = height,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int w = ctl->w;
  int h = ctl->h;
  int x = ctl->x;
  int y = ctl->y;

  if (!ctl->sync && (w == 0 || h == 0))
    return;

  uint32_t *fb = (uint32_t *)FB_ADDR;
  uint32_t *pixels = (uint32_t *)(ctl->pixels);
  int screen_w = (inl(VGACTL_ADDR) & 0xFFFF0000) >> 16;

  for(int i = y; i < y + h; i++)
  {
    for(int j =x; j < x + w; j++)
    {
      fb[i * screen_w + j] = pixels[(i - y) * w + (j - x)];
    }
  }

  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
