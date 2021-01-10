//By Tsuki Superior
#ifndef __TSOS_AT_KEYBOARD_DRIVER__
#define __TSOS_AT_KEYBOARD_DRIVER__

#include "input.hpp"

class AT_KEYBOARD_driver : public Input_driver
{
public:
    //Constructor
    AT_KEYBOARD_driver(void);

    //Detects if the module should be used
    BOOLEAN detectsystem(void);

    //Get te key currently pressed
    key_identifier getkey(void);

private:
};

#endif