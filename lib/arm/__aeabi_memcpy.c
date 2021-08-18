#include <generic/types.hpp>

extern void *memcpy(void *dstptr, const void *srcptr, size_t size);

void __aeabi_memcpy(void *dest, const void *src, size_t n)
{
    memcpy(dest, src, n);
}