//By Tsuki Superior
#include "cd.hpp"

CD_driver::CD_driver(void)
{
    name = "Compact Disk";
}

char *CD_driver::getbytes(uint16_t offset, uint8_t len)
{
}

uint16_t CD_driver::getsectorsize(void)
{
    return SECTOR_SIZE;
}
