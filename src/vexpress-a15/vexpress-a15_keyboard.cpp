//By Tsuki Superior
#include <vexpress-a15/vexpress-a15_keyboard.hpp>

VEXPRESS_A15_KEYBOARD_quark::VEXPRESS_A15_KEYBOARD_quark(void)
{
  name = "";
}

VEXPRESS_A15_KEYBOARD_quark::~VEXPRESS_A15_KEYBOARD_quark()
{
}

bool VEXPRESS_A15_KEYBOARD_quark::detectsystem(void)
{
  return true;
}

void VEXPRESS_A15_KEYBOARD_quark::reset(void)
{
}

key_identifier VEXPRESS_A15_KEYBOARD_quark::getkey(void)
{
  return key_identifier::KEY_NULL;
}

void VEXPRESS_A15_KEYBOARD_quark::waitkey(void)
{
}

// Is shift pressed
bool VEXPRESS_A15_KEYBOARD_quark::isshiftpressed(void)
{
  return false;
}

// Is alt pressed
bool VEXPRESS_A15_KEYBOARD_quark::isaltpressed(void)
{
  return false;
}

// Is ctrl pressed
bool VEXPRESS_A15_KEYBOARD_quark::isctrlpressed(void)
{
  return false;
}
