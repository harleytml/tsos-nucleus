//By Tsuki Superior
#include "input_module.hpp"

Input::Input(void)
{
#ifdef __PERSONAL_COMPUTER__

    attachdriver(at_keyboard_driver);
    attachdriver(xt_keyboard_driver);
#endif

#ifdef __GAMEBOY_ADVANCED__

    attachdriver(gba_gamepad_driver);
#endif
}

Input::~Input(void)
{
}

key_identifier Input::getkey(void)
{
    return driver->getkey();
}

void Input::waitkey(void)
{
}