//By Tsuki Superior
#ifndef __TSOS_AT_KEYBOARD_DRIVER__
#define __TSOS_AT_KEYBOARD_DRIVER__

#include "input_driver.hpp"

class AT_KEYBOARD_driver : public Input_driver
{
public:
    // Constructor
    AT_KEYBOARD_driver(void);

    ~AT_KEYBOARD_driver();

    // Detects if the module should be used
    bool detectsystem(void) override;

    // Get the key currently pressed
    key_identifier getkey(void) override;

    // Is shift pressed
    bool isshiftpressed(void) override;

    // Is alt pressed
    bool isaltpressed(void) override;

    // Is ctrl pressed
    bool isctrlpressed(void) override;

private:
};

#endif
