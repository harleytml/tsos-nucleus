#include <generic/types.hpp>

size_t strlen(const char* str)
{
    size_t pos = 0;
    while (str[pos++] != 0) {
    }
    return pos;
}