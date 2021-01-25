//By Tsuki Superior
#ifndef __TSOS_DMG_IO_PORT_DRIVER__
#define __TSOS_DMG_IO_PORT_DRIVER__

#include "../../../subsystems/serial.hpp"

class DMG_IO_PORT_driver : public Serial_driver
{
public:
    DMG_IO_PORT_driver(void);
    bool detectsystem(void);
    uint8_t exchangebyte(uint8_t b);
    bool isdevicethere(void);
};

#endif