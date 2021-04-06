//By Tsuki Superior
#ifndef __TSOS_NSPIRE_CX_KEYBOARD_QUARK__
#define __TSOS_NSPIRE_CX_KEYBOARD_QUARK__

#include <generic/input_quark.hpp>

class NSPIRE_CX_KEYBOARD_quark : public Input_quark
{
public:
  // Constructor
  NSPIRE_CX_KEYBOARD_quark(void);

  ~NSPIRE_CX_KEYBOARD_quark();

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
