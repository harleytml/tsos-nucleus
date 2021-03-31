//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_SERIAL_MODULE__
#define __TSOS_NUCLEUS_SERIAL_MODULE__

#include "generic/driver.hpp"
#include "generic/module.hpp"
#include "generic/types.hpp"
#include "generic/serial_driver.hpp"
#include "generic/current_config.hpp"

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
};

#endif
