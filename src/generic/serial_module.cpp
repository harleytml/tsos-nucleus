//By Tsuki Superior
#include "serial_module.hpp"

Serial::Serial(void)
{
#ifdef __PERSONAL_COMPUTER__
    RS232_driver rs232_driver = RS232_driver();

    attachdriver(rs232_driver);
#endif

#ifdef __GAMEBOY_ADVANCED__
    GBA_IO_PORT_driver gba_io_port_driver = GBA_IO_PORT_driver();

    attachdriver(gba_io_port_driver);
#endif
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