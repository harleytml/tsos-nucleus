//By Tsuki Superior
#include "input_module.hpp"
#include "nucleus_instance.hpp"

Input::Input(void)
{
#ifdef __PERSONAL_COMPUTER__
    static AT_KEYBOARD_driver at_keyboard_driver = AT_KEYBOARD_driver();
    static XT_KEYBOARD_driver xt_keyboard_driver = XT_KEYBOARD_driver();

    if (attachdriver(at_keyboard_driver) ||
        attachdriver(xt_keyboard_driver))
    {
        return;
    }

#endif

#ifdef __GAMEBOY_ADVANCED__
    static GBA_GAMEPAD_driver gba_gamepad_driver = GBA_GAMEPAD_driver();

    if (attachdriver(gba_gamepad_driver))
    {
        return;
    }
#endif

#ifdef __PLAYSTATION_X__
    static PSX_GAMEPAD_driver psx_gamepad_driver = PSX_GAMEPAD_driver();

    if (attachdriver(psx_gamepad_driver))
    {
        return;
    }
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