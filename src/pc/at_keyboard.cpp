//By Tsuki Superior
#include "pc/at_keyboard.hpp"

AT_KEYBOARD_quark::AT_KEYBOARD_quark(void)
{
  name = "PC/AT Keyboard";
}

AT_KEYBOARD_quark::~AT_KEYBOARD_quark(void)
{
}

bool AT_KEYBOARD_quark::detectsystem(void)
{

  /* Check the first keyboard flag bitmap
    Bit 4 equaling 1 means a AT keyboard */
  return (*((uint8_t *)0x496) & 0x10) == 0x10;
}

void AT_KEYBOARD_quark::reset(void)
{
}

/*
So detecting keys in PC is a little sketchy.
The keyboard buffer is a cyclic queue
hence you have to read characters before it is filled and starts to overwrite itself
and this starts to happen, your BIOS will beep at you
If you are testing TS/OS, please watch for this 
*/

key_identifier AT_KEYBOARD_quark::getkey(void)
{
  //Address 0040:0096
  switch (*((uint8_t *)0x496))
  {
  default:
    return KEY_NULL;
  }
}

void AT_KEYBOARD_quark::waitkey(void)
{
}

bool AT_KEYBOARD_quark::isshiftpressed(void)
{
  return false;
}

bool AT_KEYBOARD_quark::isaltpressed(void)
{
  return false;
}

bool AT_KEYBOARD_quark::isctrlpressed(void)
{
  return false;
}
