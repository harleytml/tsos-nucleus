//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_INPUT_DRIVER__
#define __TSOS_NUCLEUS_INPUT_DRIVER__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"
#include "../../core/types.hpp"
#include "../../core/core.hpp"

class Input_driver : public Driver
{
public:
  // Constructor
  Input_driver(void);

  // Read a key, and convert its scancode
  virtual key_identifier getkey(void) = 0;

  // Is shift pressed
  virtual bool isshiftpressed(void) = 0;

  // Is alt pressed
  virtual bool isaltpressed(void) = 0;

  // Is ctrl pressed
  virtual bool isctrlpressed(void) = 0;
};

#endif
