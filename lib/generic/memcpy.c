#include <generic/types.hpp>

void* memcpy(void* dstptr, const void* srcptr, size_t size)
{
    uint8_t* dst = (uint8_t*)(dstptr);
    const uint8_t* src = (const uint8_t*)srcptr;
    for (size_t i = 0; i < size; i++) {
        dst[i] = src[i];
    }
    return dstptr;
}