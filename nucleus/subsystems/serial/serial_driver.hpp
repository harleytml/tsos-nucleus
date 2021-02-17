//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_SERIAL_DRIVER__
#define __TSOS_NUCLEUS_SERIAL_DRIVER__

#include "../../core/driver.hpp"
#include "../../core/types.hpp"

class Serial_driver : public Driver
{
public:
  // Constructor
  Serial_driver(void);

  // Exchange a byte
  virtual uint8_t exchangebyte(uint8_t b) = 0;

  // Is device there
  virtual bool isdevicethere(void) = 0;
};

#endif
