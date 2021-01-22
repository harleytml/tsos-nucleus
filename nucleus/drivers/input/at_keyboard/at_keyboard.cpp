//By Tsuki Superior
#include "at_keyboard.hpp"

AT_KEYBOARD_driver::AT_KEYBOARD_driver(void)
{
    name = "PC/AT Keyboard";
}

bool AT_KEYBOARD_driver::detectsystem(void)
{

    /* Check the first keyboard flag bitmap
    Bit 4 equaling 1 means a AT keyboard */
    if ((*((uint8_t *)0x400096) & 0x10) == 1)
    {

        //This keyboard is AT, or a emulator
        return true;
    }
}

/* So detecting keys in PC is a little sketchy.
  The keyboard buffer is a cyclic queue
  hence you have to read characters before it is filled and starts to overwrite itself
  and this starts to happen, your BIOS will beep at you
  If you are testing TS/OS, please watch for this */

key_identifier AT_KEYBOARD_driver::getkey(void)
{
    switch (*((uint8_t *)0x400096))
    {
    case:
    }
}
