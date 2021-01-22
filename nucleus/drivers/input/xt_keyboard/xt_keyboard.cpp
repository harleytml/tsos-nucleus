//By Tsuki Superior
#include "xt_keyboard.hpp"

XT_KEYBOARD_driver::XT_KEYBOARD_driver(void)
{
    name = "PC/XT Keyboard";
}

bool XT_KEYBOARD_driver::detectsystem(void)
{

    /* Check the first keyboard flag bitmap
       Bit 4 equaling 0 means a XT keyboard */
    if ((*((uint8_t *)0x400096) & 0x10) == 0)
    {

        // This keyboard is XT, or a emulator
        return true;
    }
}

/* So detecting keys in PC is a little tricky
   The keyboard buffer is a cyclic queue
   hence you have to read characters before it is filled and starts to overwrite itself
   if this starts to happen, your BIOS will beep at you.
   If you are testing TS/OS, please watch for this */
key_identifier XT_KEYBOARD_driver::getkey(void)
{
    switch (*((uint8_t *)0x400096))
    {
    case:
    }
}
