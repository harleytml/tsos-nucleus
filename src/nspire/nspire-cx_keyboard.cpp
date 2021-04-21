//By Tsuki Superior
#include <nspire/nspire-cx_keyboard.hpp>

NSPIRE_CX_KEYBOARD_quark::NSPIRE_CX_KEYBOARD_quark(void)
{
  name = "Texas Instruments Nspire CX Keyboard";
}

NSPIRE_CX_KEYBOARD_quark::~NSPIRE_CX_KEYBOARD_quark()
{
}

bool NSPIRE_CX_KEYBOARD_quark::detectsystem(void)
{
  return true;
}

void NSPIRE_CX_KEYBOARD_quark::reset(void)
{
}

key_identifier NSPIRE_CX_KEYBOARD_quark::getkey(void)
{
  return key_identifier::KEY_NULL;
}

void NSPIRE_CX_KEYBOARD_quark::waitkey(void)
{
}

// Is shift pressed
bool NSPIRE_CX_KEYBOARD_quark::isshiftpressed(void)
{
  return false;
}

// Is alt pressed
bool NSPIRE_CX_KEYBOARD_quark::isaltpressed(void)
{
  return false;
}

// Is ctrl pressed
bool NSPIRE_CX_KEYBOARD_quark::isctrlpressed(void)
{
  return false;
}
