//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_INPUT__
#define __TSOS_NUCLEUS_INPUT__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"
#include "../../core/types.hpp"

extern static Tsos tsos;

enum key_identifier
{
  KEY_0,
  KEY_1,
  KEY_2,
  KEY_3,
  KEY_4,
  KEY_5,
  KEY_6,
  KEY_7,
  KEY_8,
  KEY_9,
  KEY_A,
  KEY_B,
  KEY_C,
  KEY_D,
  KEY_E,
  KEY_F,
  KEY_G,
  KEY_H,
  KEY_I,
  KEY_J,
  KEY_K,
  KEY_L,
  KEY_M,
  KEY_N,
  KEY_O,
  KEY_P,
  KEY_Q,
  KEY_R,
  KEY_S,
  KEY_T,
  KEY_U,
  KEY_V,
  KEY_W,
  KEY_X,
  KEY_Y,
  KEY_Z,
  KEY_LOWERCASE_A,
  KEY_LOWERCASE_B,
  KEY_LOWERCASE_C,
  KEY_LOWERCASE_D,
  KEY_LOWERCASE_E,
  KEY_LOWERCASE_F,
  KEY_LOWERCASE_G,
  KEY_LOWERCASE_H,
  KEY_LOWERCASE_I,
  KEY_LOWERCASE_J,
  KEY_LOWERCASE_K,
  KEY_LOWERCASE_L,
  KEY_LOWERCASE_M,
  KEY_LOWERCASE_N,
  KEY_LOWERCASE_O,
  KEY_LOWERCASE_P,
  KEY_LOWERCASE_Q,
  KEY_LOWERCASE_R,
  KEY_LOWERCASE_S,
  KEY_LOWERCASE_T,
  KEY_LOWERCASE_U,
  KEY_LOWERCASE_V,
  KEY_LOWERCASE_W,
  KEY_LOWERCASE_X,
  KEY_LOWERCASE_Y,
  KEY_LOWERCASE_Z,
  KEY_UPPERCASE_A,
  KEY_UPPERCASE_B,
  KEY_UPPERCASE_C,
  KEY_UPPERCASE_D,
  KEY_UPPERCASE_E,
  KEY_UPPERCASE_F,
  KEY_UPPERCASE_G,
  KEY_UPPERCASE_H,
  KEY_UPPERCASE_I,
  KEY_UPPERCASE_J,
  KEY_UPPERCASE_K,
  KEY_UPPERCASE_L,
  KEY_UPPERCASE_M,
  KEY_UPPERCASE_N,
  KEY_UPPERCASE_O,
  KEY_UPPERCASE_P,
  KEY_UPPERCASE_Q,
  KEY_UPPERCASE_R,
  KEY_UPPERCASE_S,
  KEY_UPPERCASE_T,
  KEY_UPPERCASE_U,
  KEY_UPPERCASE_V,
  KEY_UPPERCASE_W,
  KEY_UPPERCASE_X,
  KEY_UPPERCASE_Y,
  KEY_UPPERCASE_Z,
  KEY_EXCLAMATION_POINT,
  KEY_AT,
  KEY_POUND,
  KEY_DOLLAR,
  KEY_PERCENT,
  KEY_CARET,
  KEY_AMPERSAND,
  KEY_APOSTROPHE,
  KEY_OPEN_BRACKET,
  KEY_CLOSE_BRACKET,
  KEY_DASH,
  KEY_PLUS,
  KEY_TAB

};

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

// The main class controlling input
class Input : public Module<Input_driver>
{
public:
  // Constructor
  Input(void);

  // Destructor
  ~Input(void);

  // Get the key pressed
  key_identifier getkey(void);

  // Wait for a key to be pressed
  void waitkey(void);

private:
  // Input driver
  Input_driver *driver;
};

enum key_position
{
  RIGHT,
  LEFT,
  MIDDLE
};

#endif
