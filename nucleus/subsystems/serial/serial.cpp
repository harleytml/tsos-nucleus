//By Tsuki Superior
#include "serial.hpp"

Serial::Serial(void)
{
}

Serial::~Serial(void)
{
}

uint8_t Serial::exchangebyte(uint8_t b)
{
    if (isdevicethere())
    {
        return driver->exchangebyte(b);
    }
    else
    {
        return 0x00;
    }
}

BOOLEAN isdevicethere(void)
{
    return driver->isdevicethere();
}