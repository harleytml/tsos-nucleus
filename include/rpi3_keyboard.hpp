//By Tsuki Superior
#ifndef __TSOS_RPI3_KEYBOARD_DRIVER__
#define __TSOS_RPI3_KEYBOARD_DRIVER__

#include "input_driver.hpp"

class RPI3_KEYBOARD_driver : public Input_driver
{
public:
  // Constructor
  RPI3_KEYBOARD_driver(void);

  ~RPI3_KEYBOARD_driver();

  // Detects if the module should be used
  bool detectsystem(void) override;

  void reset(void) override;

  // Get the key currently pressed
  key_identifier getkey(void) override;

  //Wait for a key
  void waitkey(void) override;

  // Is shift pressed
  bool isshiftpressed(void) override;

  // Is alt pressed
  bool isaltpressed(void) override;

  // Is ctrl pressed
  bool isctrlpressed(void) override;

private:
};

#endif
