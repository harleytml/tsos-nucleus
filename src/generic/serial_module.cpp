//By Tsuki Superior
#include "serial_module.hpp"

Serial::Serial(void)
{
#ifdef __PERSONAL_COMPUTER__
    static RS232_driver rs232_driver = RS232_driver();

    if (attachdriver(rs232_driver))
    {
        return;
    }
#endif

#ifdef __GAMEBOY_ADVANCED__
    static GBA_IO_PORT_driver gba_io_port_driver = GBA_IO_PORT_driver();

    if (attachdriver(gba_io_port_driver))
    {
        return;
    }
#endif

#ifdef __PLAYSTATION_X__

#endif
}

Serial::~Serial()
{
}

uint8_t Serial::exchangebyte(uint8_t b)
{
    return isdevicethere() ? driver->exchangebyte(b) : 0x00;
}

bool Serial::isdevicethere(void)
{
    return driver->isdevicethere();
}