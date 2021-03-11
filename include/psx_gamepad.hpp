//By Tsuki Superior
#ifndef __TSOS_GBA_GAMEPAD_DRIVER__
#define __TSOS_GBA_GAMEPAD_DRIVER__

#include "input_driver.hpp"

class PSX_GAMEPAD_driver : public Input_driver
{
public:
    // Constructor
    PSX_GAMEPAD_driver(void);

    ~PSX_GAMEPAD_driver();

    // Detects if the module should be used
    bool detectsystem(void) override;

    // Get the key currently pressed
    key_identifier getkey(void) override;

    //Wait for a key
    void waitkey(void) override;

    // Is shift pressed
    bool isshiftpressed(void) override;

    // Is alt pressed
    bool isaltpressed(void) override;

    // Is ctrl pressed
    bool isctrlpressed(void) override;

private:
};

#endif
