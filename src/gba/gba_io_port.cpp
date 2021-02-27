//By Tsuki Superior
#include "gba_io_port.hpp"

GBA_IO_PORT_driver::GBA_IO_PORT_driver(void)
{
    name = "Gameboy Advanced IO Port";
}

bool GBA_IO_PORT_driver::detectsystem(void)
{
    return true;
}

bool GBA_IO_PORT_driver::isdevicethere(void)
{
    return false;
}

// Serial on the DMG is lovely and simple
uint8_t GBA_IO_PORT_driver::exchangebyte(uint8_t b)
{
    return 0;
}
