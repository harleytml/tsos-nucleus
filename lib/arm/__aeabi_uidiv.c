#include <generic/types.hpp>

uint32_t __aeabi_uidiv(uint32_t num, uint32_t den)
{
    typedef struct uidiv_t
    {
        uint32_t quot;
        uint32_t rem;
    } uidiv_t;

    uidiv_t ret;
    uint32_t quot = 0;
    while (num >= den)
    {
        uint32_t q = 1;
        while ((q << 1) * den <= num && q * den <= __UINT32_MAX__ / 2)
        {
            q <<= 1;
        }
        num -= q * den;
        quot += q;
    }
    ret.quot = quot;
    ret.rem = num;
    return ret.quot;
}
