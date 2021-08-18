// By Tsuki Superior
#include <generic/input_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

Input::Input(void)
{
#ifdef __PERSONAL_COMPUTER__
    static AT_KEYBOARD_quark at_keyboard_quark = AT_KEYBOARD_quark();
    static XT_KEYBOARD_quark xt_keyboard_quark = XT_KEYBOARD_quark();

    if (attachquark(at_keyboard_quark) || attachquark(xt_keyboard_quark))
    {
        return;
    }
#endif

#ifdef __RASPBERRY_PI_3__
    static RPI3_KEYBOARD_quark rpi3_keyboard_quark = RPI3_KEYBOARD_quark();

    attachquark(rpi3_keyboard_quark);
#endif

#ifdef __NSPIRE__

    static NSPIRE_CM_KEYBOARD_quark nspire_cm_keyboard_quark = NSPIRE_CM_KEYBOARD_quark();
    static NSPIRE_CX_KEYBOARD_quark nspire_cx_keyboard_quark = NSPIRE_CX_KEYBOARD_quark();

    if (attachquark(nspire_cm_keyboard_quark) || attachquark(nspire_cx_keyboard_quark))
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
    return quark->getkey();
}

void Input::waitkey(void)
{
}
