//By Tsuki Superior
#include "canon-a1100/canon-a1100_keypad.hpp"

CANON_A1100_KEYPAD_quark::CANON_A1100_KEYPAD_quark(void)
{
  name = "Canon Powershot A1100 IS Keypad";
}

CANON_A1100_KEYPAD_quark::~CANON_A1100_KEYPAD_quark()
{
}

bool CANON_A1100_KEYPAD_quark::detectsystem(void)
{
  return true;
}

void CANON_A1100_KEYPAD_quark::reset(void)
{
}

key_identifier CANON_A1100_KEYPAD_quark::getkey(void)
{
  return KEY_NULL;
}

void CANON_A1100_KEYPAD_quark::waitkey(void)
{
}

// Is shift pressed
bool CANON_A1100_KEYPAD_quark::isshiftpressed(void)
{
  return false;
}

// Is alt pressed
bool CANON_A1100_KEYPAD_quark::isaltpressed(void)
{
  return false;
}

// Is ctrl pressed
bool CANON_A1100_KEYPAD_quark::isctrlpressed(void)
{
  return false;
}
