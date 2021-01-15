//By Tsuki Superior
#ifndef __TSOS_DMG_IO_PORT_DRIVER__
#define __TSOS_DMG_IO_PORT_DRIVER__

#include "serial.hpp"

class DMG_IO_PORT_driver : public Serial_driver
{
    DMG_IO_PORT_driver(void);
    bool detectsystem(void);
    uint8_t exchangebyte(uint8_t b);
    bool isdevicethere(void);
};

#endif