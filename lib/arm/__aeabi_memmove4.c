#include <generic/types.hpp>

extern void* __aeabi_memmove(void* dest, const void* src, size_t n);

void* __aeabi_memmove4(void* dest, const void* src, size_t n)
{
    return __aeabi_memmove(dest, src, n);
}