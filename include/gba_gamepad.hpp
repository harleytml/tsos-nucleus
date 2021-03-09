//By Tsuki Superior
#ifndef __TSOS_GBA_GAMEPAD_DRIVER__
#define __TSOS_GBA_GAMEPAD_DRIVER__

#include "input_driver.hpp"

class GBA_GAMEPAD_driver : public Input_driver
{
public:
    // Constructor
    GBA_GAMEPAD_driver(void);

    ~GBA_GAMEPAD_driver();

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
