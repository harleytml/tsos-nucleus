#include <generic/types.hpp>

extern void *memmove(void *dstptr, const void *srcptr, size_t size);

void *memshift(char *mem, int shift, size_t n)
{
    void *dest = mem + shift;
    memmove(dest, mem, n);
    return dest;
}
