//By Tsuki Superior
#include "gba_io_port.hpp"

GBA_IO_PORT_driver::GBA_IO_PORT_driver(void)
{
}

bool GBA_IO_PORT_driver::detectsystem(void)
{
}

// Serial on the DMG is lovely and simple
uint8_t GBA_IO_PORT_driver::exchangebyte(uint8_t b)
{

    // Confirming that a reciving DMG is actually there
    uint8_t *SB = (uint8_t *)0xff01;
    *SB = 0x00
}
