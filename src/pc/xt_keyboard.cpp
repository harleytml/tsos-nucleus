//By Tsuki Superior
#include "pc/xt_keyboard.hpp"

XT_KEYBOARD_driver::XT_KEYBOARD_driver(void)
{
  name = "PC/XT Keyboard";
}

XT_KEYBOARD_driver::~XT_KEYBOARD_driver()
{
}

bool XT_KEYBOARD_driver::detectsystem(void)
{

  // Check the first keyboard flag bitmap
  //Bit 4 equaling 0 means a XT keyboard
  //Address is 0040:0096
  return (*((uint8_t *)0x496) & 0x10) == 0;
}

void XT_KEYBOARD_driver::reset(void)
{
}

/*
   So detecting keys in PC is a little tricky
   The keyboard buffer is a cyclic queue
   hence you have to read characters before it is filled and starts to overwrite itself
   if this starts to happen, your BIOS will beep at you.
   If you are testing TS/OS, please watch for this
    */
key_identifier XT_KEYBOARD_driver::getkey(void)
{
  //Address is 0040:0096

  switch (*((uint8_t *)0x496))
  {
  default:
    return KEY_NULL;
  }
}

void XT_KEYBOARD_driver::waitkey(void)
{
}

bool XT_KEYBOARD_driver::isshiftpressed(void)
{
  return false;
}

bool XT_KEYBOARD_driver::isaltpressed(void)
{
  return false;
}

bool XT_KEYBOARD_driver::isctrlpressed(void)
{
  return false;
}
