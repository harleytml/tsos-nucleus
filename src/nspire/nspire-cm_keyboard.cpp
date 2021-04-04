//By Tsuki Superior
#include "nspire/nspire-cm_keyboard.hpp"

NSPIRE_CM_KEYBOARD_quark::NSPIRE_CM_KEYBOARD_quark(void)
{
  name = "Texas Instruments Nspire CM Keyboard";
}

NSPIRE_CM_KEYBOARD_quark::~NSPIRE_CM_KEYBOARD_quark()
{
}

bool NSPIRE_CM_KEYBOARD_quark::detectsystem(void)
{
  return true;
}

void NSPIRE_CM_KEYBOARD_quark::reset(void)
{
}

key_identifier NSPIRE_CM_KEYBOARD_quark::getkey(void)
{
  return KEY_NULL;
}

void NSPIRE_CM_KEYBOARD_quark::waitkey(void)
{
}

// Is shift pressed
bool NSPIRE_CM_KEYBOARD_quark::isshiftpressed(void)
{
  return false;
}

// Is alt pressed
bool NSPIRE_CM_KEYBOARD_quark::isaltpressed(void)
{
  return false;
}

// Is ctrl pressed
bool NSPIRE_CM_KEYBOARD_quark::isctrlpressed(void)
{
  return false;
}
