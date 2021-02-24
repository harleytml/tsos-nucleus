//By Tsuki Superior
#include "serial_module.hpp"

Serial::Serial(void)
{
}

Serial::~Serial()
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

bool Serial::isdevicethere(void)
{
    return driver->isdevicethere();
}