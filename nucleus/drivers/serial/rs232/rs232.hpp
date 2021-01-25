//Driver by Tsuki Superior
#ifndef __TSOS_RS232_DRIVER__
#define __TSOS_RS232_DRIVER__

#include "../../../subsystems/serial.hpp"

class RS232_driver : public Serial_driver
{
public:
    RS232_driver(void);
    bool detectsystem(void);
    uint8_t exchangebyte(uint8_t b)
};

#endif