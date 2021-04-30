#include <generic/types.hpp>

extern void *memset(void *bufptr, int value, size_t size);

void __aeabi_memset(void *dest, size_t n, int c)
{
    memset(dest, c, n);
}