//By Tsuki Superior
#ifndef __TSOS_RPI3_KEYBOARD_QUARK__
#define __TSOS_RPI3_KEYBOARD_QUARK__

#include <generic/input_quark.hpp>

class RPI3_KEYBOARD_quark : public Input_quark
{
public:
  // Constructor
  RPI3_KEYBOARD_quark(void);

  ~RPI3_KEYBOARD_quark();

  // Detects if the nucleon should be used
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
