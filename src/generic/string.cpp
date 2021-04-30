#include <generic/string.hpp>

String::String(void)
{
    internaldata = nullptr;
    internaldatalength = 0;
}

String::String(const char* str)
{
    uint32_t len = strnlen(str, 0xff);
    internaldata = new char[len];
    memcpy(internaldata, str, len);
    internaldatalength = len;
}