#include <generic/types.hpp>

extern void *memset(void *bufptr, int value, size_t size);

void __aeabi_memclr4(void *dest, size_t n)
{
  memset(dest, 0, n);
}