#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

char *chwrite(char *dest, char *ch, int *cnt) {
  while (*ch != '\0')
  {
    *dest = *ch;
    ch ++;
    dest ++;
    (*cnt) ++;
  }
  return dest;
}

char *int_to_str(int num, char *dest, int *cnt, char pad, int width) {
  assert(dest);
  char numbuf[32];
  int i = 0;
  int is_negative = 0;
  int pad_len = 0;
  // 处理负号
  if(num < 0)
  {
    is_negative = 1;
    num = -num;
  }
  // 计数
  if(num == 0)
  {
    numbuf[0] = '0';
    i ++;
  }
  else
  {
    while (num > 0)
    {
      numbuf[i] = '0' + (num % 10);
      num /= 10;
      i ++;
    }
  }
  if(is_negative)
  {
    *dest = '-';
    (*cnt) ++;
    dest ++;
  }
  // 填充
  pad_len = (width > (i + is_negative)) ? width - (i + is_negative) : 0;
  (*cnt) += pad_len;
  for(int j = 0; j < pad_len; j++)
  {
    *dest = pad;
    dest ++;
  }

  (*cnt) += i;
  while (i-- > 0)
  {
    *dest = numbuf[i];
    dest ++;
  }
  return dest;
}

int get_format_str(const char *fmt, char *str, va_list args) {
  int cnt = 0;
  const char *p = fmt;

  while (*p != '\0')
  {
    if(*p != '%')
    {
      *str = *p;
      str ++;
      p ++;
      cnt ++;
      continue;
    }
    p ++;
    if(*p == '%')
    {
      *str = *p;
      str ++;
      p ++;
      cnt ++;
      continue;
    }

    // 解析格式字符
    char pad = ' ';
    int width = 0;

    if(*p == '0')
    {
      pad = '0';
      p ++;
    }

    if(*p >= '0' && *p <= '9')
    {
      width = width * 10 + (*p - '0');
      p ++;
    }

    switch (*p)
    {
      case 'd':
        int num = va_arg(args, int);
        str = int_to_str(num, str, &cnt, pad, width);
        p ++;
        break;
      case 'c':
        char ch = va_arg(args, int);
        *str = ch;
        str ++;
        p ++;
        break;
      case 's':
        char *s = va_arg(args, char *);
        str = chwrite(str, s, &cnt);
        p ++;
        break;
      default:
        assert(0);
    }
  }
  *str = '\0';
  return cnt;
}

int printf(const char *fmt, ...) {
  int cnt = 0;
  char buf[128];
  char *out = buf;
  va_list args;
  va_start(args, fmt);
  cnt = get_format_str(fmt, buf, args);
  va_end(args);
  while(*out != '\0')
  {
    putch(*out);
    out ++;
  }
  return cnt;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  if(out == NULL) return -1;
  int cnt = 0;
  va_list args;
  va_start(args, fmt);
  cnt = get_format_str(fmt, out, args);
  va_end(args);
  return cnt;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
