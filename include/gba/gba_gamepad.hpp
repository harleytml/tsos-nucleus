/* By Tsuki Superior
 * Gameboy Advanced Gamepad Quark 
 *
 * The quark for the GBA's control pad
 * Note that since the GBA's control pad has a few buttons,
 * you will have to scroll and choose your answer
 */

#ifndef __TSOS_GBA_GAMEPAD_QUARK__
#define __TSOS_GBA_GAMEPAD_QUARK__

#include "generic/input_quark.hpp"

class GBA_GAMEPAD_quark : public Input_quark
{
public:
  // Constructor
  GBA_GAMEPAD_quark(void);

  ~GBA_GAMEPAD_quark();

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
