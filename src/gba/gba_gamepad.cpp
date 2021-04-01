//By Tsuki Superior
#include "gba/gba_gamepad.hpp"

GBA_GAMEPAD_quark::GBA_GAMEPAD_quark(void)
{
  name = "Gameboy Advanced Gamepad";
}

GBA_GAMEPAD_quark::~GBA_GAMEPAD_quark()
{
}

bool GBA_GAMEPAD_quark::detectsystem(void)
{
  return true;
}

void GBA_GAMEPAD_quark::reset(void)
{
}

key_identifier GBA_GAMEPAD_quark::getkey(void)
{
  return KEY_NULL;
}

void GBA_GAMEPAD_quark::waitkey(void)
{
}

// Is shift pressed
bool GBA_GAMEPAD_quark::isshiftpressed(void)
{
  return false;
}

// Is alt pressed
bool GBA_GAMEPAD_quark::isaltpressed(void)
{
  return false;
}

// Is ctrl pressed
bool GBA_GAMEPAD_quark::isctrlpressed(void)
{
  return false;
}
