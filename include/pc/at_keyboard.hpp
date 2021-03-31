//By Tsuki Superior
#ifndef __TSOS_AT_KEYBOARD_DRIVER__
#define __TSOS_AT_KEYBOARD_DRIVER__

#include "generic/input_driver.hpp"

class AT_KEYBOARD_driver : public Input_driver
{
public:
  // Constructor
  AT_KEYBOARD_driver(void);

  ~AT_KEYBOARD_driver();

  // Detects if the module should be used
  bool detectsystem(void) final;

  void reset(void) final;

  // Get the key currently pressed
  key_identifier getkey(void) final;

  //Wait for a key
  void waitkey(void) final;

  // Is shift pressed
  bool isshiftpressed(void) final;

  // Is alt pressed
  bool isaltpressed(void) final;

  // Is ctrl pressed
  bool isctrlpressed(void) final;

private:
};

#endif
