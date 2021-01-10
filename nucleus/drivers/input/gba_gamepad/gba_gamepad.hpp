//By Tsuki Superior
#ifndef __TSOS_GBA_GAMEPAD_DRIVER__
#define __TSOS_GBA_GAMEPAD_DRIVER__

#include "input.hpp"

class GBA_GAMEPAD_driver: public Input_driver
{
 public:

  //Constructor
  GBA_GAMEPAD_driver(void);   

  //Detects if the module should be used
  BOOLEAN detectsystem(void);

  //Get te key currently pressed
  Key getkey(void);

 private:  
};

#endif