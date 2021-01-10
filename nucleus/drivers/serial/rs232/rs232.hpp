//Driver by Tsuki Superior
#ifndef __TSOS_RS232_DRIVER__
#define __TSOS_RS232_DRIVER__

#include "serial.hpp"

class RS232_driver : public Serial_driver
{
    RS232_driver(void);
    BOOLEAN detectsystem(void);
    uint8_t exchangebyte(uint8_t b)
};

#endif