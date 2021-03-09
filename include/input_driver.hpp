//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_INPUT_DRIVER__
#define __TSOS_NUCLEUS_INPUT_DRIVER__

#include "driver.hpp"
#include "types.hpp"
#include "input_key_identifier.hpp"

class Input_driver : public Driver
{
public:
  // Constructor
  Input_driver(void);

  //Deconstructor
  ~Input_driver();

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
