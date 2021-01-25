//Driver by Tsuki Superior
#ifndef __TSOS_GBA_IO_PORT_DRIVER__
#define __TSOS_GBA_IO_PORT_DRIVER__

#include "../../../subsystems/serial.hpp"

class GBA_IO_PORT_driver : public Serial_driver
{
public:
    GBA_IO_PORT_driver(void);
    bool detectsystem(void);
    uint8_t exchangebyte(uint8_t b)
};

#endif
