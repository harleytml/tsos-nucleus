//By Tsuki Superior
#include "rpi3/rpi3_keyboard.hpp"

RPI3_KEYBOARD_driver::RPI3_KEYBOARD_driver(void)
{
  name = "Raspberry Pi 3 Keyboard";
}

RPI3_KEYBOARD_driver::~RPI3_KEYBOARD_driver()
{
}

bool RPI3_KEYBOARD_driver::detectsystem(void)
{
  return true;
}

void RPI3_KEYBOARD_driver::reset(void)
{
}

key_identifier RPI3_KEYBOARD_driver::getkey(void)
{
  return KEY_NULL;
}

void RPI3_KEYBOARD_driver::waitkey(void)
{
}

// Is shift pressed
bool RPI3_KEYBOARD_driver::isshiftpressed(void)
{
  return false;
}

// Is alt pressed
bool RPI3_KEYBOARD_driver::isaltpressed(void)
{
  return false;
}

// Is ctrl pressed
bool RPI3_KEYBOARD_driver::isctrlpressed(void)
{
  return false;
}
