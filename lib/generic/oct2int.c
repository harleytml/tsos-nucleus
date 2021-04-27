#include <generic/types.hpp>

size_t oct2int(char *str, size_t size)
{
  size_t n = 0;
  char *c = str;
  while (size-- > 0)
  {
    n *= 8;
    n += *c - '0';
    c++;
  }
  return n;
}