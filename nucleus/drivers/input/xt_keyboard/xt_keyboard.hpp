//By Tsuki Superior
#ifndef __TSOS_XT_KEYBOARD_DRIVER__
#define __TSOS_XT_KEYBOARD_DRIVER__

#include "../../../subsystems/input/input.hpp"

class XT_KEYBOARD_driver : public Input_driver
{
public:
    // Constructor
    XT_KEYBOARD_driver(void);

    // Detects if the module should be used
    bool detectsystem(void);

    // Get the key currently pressed
    key_identifier getkey(void);

private:
};

#endif
