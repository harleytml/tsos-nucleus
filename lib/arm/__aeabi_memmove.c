#include <generic/types.hpp>

extern void* memmove(void* dstptr, const void* srcptr, size_t size);

void __aeabi_memmove(void* dest, const void* src, size_t n)
{
    memmove(dest, src, n);
}