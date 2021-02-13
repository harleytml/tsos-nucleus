//By Tsuki Superior
#ifndef __TSOS_GBA_GAMEPAD_DRIVER__
#define __TSOS_GBA_GAMEPAD_DRIVER__

#include "../../../subsystems/input/input_module.hpp"
#include "../../../subsystems/input/input_driver.hpp"

class GBA_GAMEPAD_driver : public Input_driver
{
public:
    // Constructor
    GBA_GAMEPAD_driver(void);

    // Detects if the module should be used
    bool detectsystem(void);

    // Get the key currently pressed
    key_identifier getkey(void);

private:
};

#endif
