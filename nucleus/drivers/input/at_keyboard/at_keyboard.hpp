//By Tsuki Superior
#ifndef __TSOS_AT_KEYBOARD_DRIVER__
#define __TSOS_AT_KEYBOARD_DRIVER__

#include "../../../subsystems/input/input_module.hpp"
#include "../../../subsystems/input/input_driver.hpp"

class AT_KEYBOARD_driver : public Input_driver
{
public:
    // Constructor
    AT_KEYBOARD_driver(void);

    // Detects if the module should be used
    bool detectsystem(void);

    // Get the key currently pressed
    key_identifier getkey(void);

private:
};

#endif
