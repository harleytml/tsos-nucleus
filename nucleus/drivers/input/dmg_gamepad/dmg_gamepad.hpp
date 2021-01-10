//By Tsuki Superior
#ifndef __TSOS_DMG_GAMEPAD_DRIVER__
#define __TSOS_DMG_GAMEPAD_DRIVER__

#include "input.hpp"

class DMG_GAMEPAD_driver : public Input_driver
{
public:
    //Constructor
    DMG_GAMEPAD_driver(void);

    //Detects if the module should be used
    BOOLEAN detectsystem(void);

    //Get te key currently pressed
    key_identifier getkey(void);

private:
};

#endif