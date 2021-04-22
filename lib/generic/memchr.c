#include <generic/types.hpp>

void *memchr(const void *str, int c, size_t n)
{
  uint8_t *s = (uint8_t *)str;

  for (size_t i = 0; i < n; i++)
  {
    if (*(s + i) == c)
    {
      return (s + i);
    }
  }

  return NULL;
}