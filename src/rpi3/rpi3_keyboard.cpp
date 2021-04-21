//By Tsuki Superior
#include <rpi3/rpi3_keyboard.hpp>

RPI3_KEYBOARD_quark::RPI3_KEYBOARD_quark(void)
{
  name = "Raspberry Pi 3 Keyboard";
}

RPI3_KEYBOARD_quark::~RPI3_KEYBOARD_quark()
{
}

bool RPI3_KEYBOARD_quark::detectsystem(void)
{
  return true;
}

void RPI3_KEYBOARD_quark::reset(void)
{
}

key_identifier RPI3_KEYBOARD_quark::getkey(void)
{
  return key_identifier::KEY_NULL;
}

void RPI3_KEYBOARD_quark::waitkey(void)
{
}

// Is shift pressed
bool RPI3_KEYBOARD_quark::isshiftpressed(void)
{
  return false;
}

// Is alt pressed
bool RPI3_KEYBOARD_quark::isaltpressed(void)
{
  return false;
}

// Is ctrl pressed
bool RPI3_KEYBOARD_quark::isctrlpressed(void)
{
  return false;
}
