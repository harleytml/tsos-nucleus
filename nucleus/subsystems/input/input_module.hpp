//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_INPUT__
#define __TSOS_NUCLEUS_INPUT__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"
#include "../../core/types.hpp"
#include "../../core/core.hpp"
#include "./input_driver.hpp"
#include "./input_key_identifier.hpp"

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
