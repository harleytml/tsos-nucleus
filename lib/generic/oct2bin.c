#include <generic/types.hpp>

size_t oct2bin(char *str, size_t size)
{
  int n = 0;
  char *c = str;
  while (size-- > 0)
  {
    n *= 8;
    n += *c - '0';
    c++;
  }
  return n;
}