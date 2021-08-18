#include <generic/types.hpp>

extern uint32_t __udivmodsi4(uint32_t num, uint32_t den, uint32_t *rem_p);

int32_t __aeabi_idiv(int32_t num, int32_t den)
{
    int32_t minus = 0;
    int32_t v;

    if (num < 0)
    {
        num = -num;
        minus = 1;
    }
    if (den < 0)
    {
        den = -den;
        minus ^= 1;
    }

    v = __udivmodsi4(num, den, 0);
    if (minus)
    {
        v = -v;
    }

    return v;
}