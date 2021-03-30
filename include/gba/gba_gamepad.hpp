//By Tsuki Superior
#ifndef __TSOS_GBA_GAMEPAD_DRIVER__
#define __TSOS_GBA_GAMEPAD_DRIVER__

#include "input_driver.hpp"

class GBA_GAMEPAD_driver : public Input_driver
{
public:
  // Constructor
  GBA_GAMEPAD_driver(void);

  ~GBA_GAMEPAD_driver();

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
