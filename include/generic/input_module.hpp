//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_INPUT_MODULE__
#define __TSOS_NUCLEUS_INPUT_MODULE__

#include "driver.hpp"
#include "module.hpp"
#include "types.hpp"
#include "input_driver.hpp"
#include "input_key_identifier.hpp"
#include "current_config.hpp"

// The main class controlling input
class Input : public Module<Input_driver>
{
public:
  // Constructor
  Input(void);

  // Destructor
  ~Input();

  // Get the key pressed
  key_identifier getkey(void);

  // Wait for a key to be pressed
  void waitkey(void);
};

enum key_position
{
  RIGHT,
  LEFT,
  MIDDLE
};

#endif
