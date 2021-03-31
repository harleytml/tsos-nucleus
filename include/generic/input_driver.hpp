/* By Tsuki Superior
 * Abstract Input Driver
 * 
 * This is the abstract driver for the input driver
 */

#ifndef __TSOS_NUCLEUS_INPUT_DRIVER__
#define __TSOS_NUCLEUS_INPUT_DRIVER__

#include "generic/driver.hpp"
#include "generic/types.hpp"
#include "generic/input_key_identifier.hpp"

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

  //Wait key
  virtual void waitkey(void) = 0;

  // Is alt pressed
  virtual bool isaltpressed(void) = 0;

  // Is ctrl pressed
  virtual bool isctrlpressed(void) = 0;
};

#endif
