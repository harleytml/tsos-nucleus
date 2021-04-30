#include <generic/types.hpp>

extern int __cxa_atexit(void (*f)(void*), void* objptr, void* dso);

int __aeabi_atexit(void* arg, void (*func)(void*), void* d)
{
    return __cxa_atexit(func, arg, d);
}