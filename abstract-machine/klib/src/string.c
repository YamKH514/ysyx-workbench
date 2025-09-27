#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t cnt = 0;
  while (*s != '\0')
  {
    cnt ++;
    s ++;
  }
  return cnt;
}

char *strcpy(char *dst, const char *src) {
  char *ret = dst;
  while (*src != '\0')
  {
    *dst = *src;
    dst ++;
    src ++;
  }
  dst ++;
  *dst = '\0';

  return ret;
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
  char *ret = dst;
  while (*dst != '\0')
  {
    dst ++;
  }
  while (*src != '\0')
  {
    *dst = *src;
    dst ++;
    src ++;
  }
  *dst = '\0';

  return ret;
}

int strcmp(const char *s1, const char *s2) {
  while (*s1 != '\0' && *s2 != '\0')
  {
    if(*s1 != *s2)
    {
      return (*s1 < *s2) ? -1 : 1;
    }
    s1 ++;
    s2 ++;
  }
  if(*s1 == *s2) return 0;

  return (*s1 < *s2) ? -1 : 1;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {
  unsigned char *p = s;
  while (n > 0)
  {
    *p = (unsigned char)c;
    p ++;
    n --;
  }

  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  char *p = dst;
  for(int i = 0; i < n; i++)
  {
    *(p + i) = *((char *)src + i);
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *p1 = s1;
  const unsigned char *p2 = s2;
  for (size_t i = 0; i < n; i++)
  {
    if(p1[i] != p2[i]) return (p1[i] - p2[i]);
  }
  return 0;
}

#endif
