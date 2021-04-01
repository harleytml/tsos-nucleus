//By Tsuki Superior
#ifndef __TSOS_RS232_QUARK__
#define __TSOS_RS232_QUARK__

#include "generic/serial_driver.hpp"

class RS232_driver : public Serial_driver
{
public:
  RS232_driver(void);
  void reset(void) final;
  bool detectsystem(void) final;
  bool isdevicethere(void) final;
  uint8_t exchangebyte(uint8_t b) final;
};

#endif