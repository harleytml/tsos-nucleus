//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_SERIAL_MODULE__
#define __TSOS_NUCLEUS_SERIAL_MODULE__

#include "driver.hpp"
#include "module.hpp"
#include "types.hpp"
#include "serial_driver.hpp"

// The main class controlling serial
class Serial : public Module<Serial_driver>
{
public:
  // Constructor
  Serial(void);

  // Destructor
  ~Serial();

  // Exchange a byte
  uint8_t exchangebyte(uint8_t b);

  // Is device there
  bool isdevicethere(void);

private:
  // Serial driver
  Serial_driver *driver;
};

#endif
