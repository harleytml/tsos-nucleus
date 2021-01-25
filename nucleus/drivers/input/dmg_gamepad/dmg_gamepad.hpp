//By Tsuki Superior
#ifndef __TSOS_DMG_GAMEPAD_DRIVER__
#define __TSOS_DMG_GAMEPAD_DRIVER__

#include "../../../subsystems/input.hpp"

class DMG_GAMEPAD_driver : public Input_driver
{
public:
    // Constructor
    DMG_GAMEPAD_driver(void);

    // Detects if the module should be used
    bool detectsystem(void);

    // Get the key currently pressed
    key_identifier getkey(void);

private:
};

#endif
