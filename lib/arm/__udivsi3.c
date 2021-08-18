#include <generic/types.hpp>

extern uint32_t __udivmodsi4(uint32_t num, uint32_t den, uint32_t *rem_p);

uint32_t __udivsi3(uint32_t num, uint32_t den)
{
    return __udivmodsi4(num, den, 0);
}