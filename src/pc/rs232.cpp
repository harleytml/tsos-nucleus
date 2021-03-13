//Driver by Tsuki Superior
#include "rs232.hpp"

RS232_driver::RS232_driver(void)
{
    name = "Recommended Standard 232";
}

bool RS232_driver::detectsystem(void)
{
    return true;
}

void RS232_driver::reset(void)
{
}

bool RS232_driver::isdevicethere(void)
{
    return false;
}

uint8_t RS232_driver::exchangebyte(uint8_t b)
{
    return 0;
}
