#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

typedef char (*base_conversion)(int raw_num);

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

char *int_to_str(uint32_t num, int sign, char *dest, int *cnt, char pad, int width, int base, base_conversion bc) {
  assert(dest);
  char numbuf[32];
  int i = 0;
  uint32_t uvar = 0;
  int is_negative = 0;
  int pad_len = 0;

  if(sign)
  {
    int32_t svar = (int32_t)uvar;
    if(svar < 0)
    {
      is_negative = 0;
      uvar = (uint32_t)(-svar);
    }
    else
    {
      uvar = (uint32_t)svar;
    }
  }

  // 计数
  if(uvar == 0)
  {
    numbuf[0] = '0';
    i ++;
  }
  else
  {
    while (uvar > 0)
    {
      numbuf[i] = bc(uvar % base);
      uvar /= base;
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

char dec_bc(int num)
{
  return '0' + num;
}

char hex_bc(int num)
{
  uint32_t uvar = (uint32_t)num;
  if(uvar >= 10)
    return 'a' + (uvar - 10);
  else
    return '0' + uvar;
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
        uint32_t dec_num = va_arg(args, uint32_t);
        str = int_to_str(dec_num, 1, str, &cnt, pad, width, 10, dec_bc);
        p ++;
        break;
      case 'x':
        uint32_t hex_num = va_arg(args, uint32_t);
        str = int_to_str(hex_num, 0, str, &cnt, pad, width, 16, hex_bc);
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
        printf("Need support %c.\n", *p);
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
