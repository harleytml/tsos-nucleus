//By Tsuki Superior
#include "gba/gba_io_port.hpp"

GBA_IO_PORT_quark::GBA_IO_PORT_quark(void)
{
  name = "Gameboy Advanced IO Port";
}

bool GBA_IO_PORT_quark::detectsystem(void)
{
  return true;
}

void GBA_IO_PORT_quark::reset(void)
{
}

bool GBA_IO_PORT_quark::isdevicethere(void)
{
  return false;
}

// Serial on the DMG is lovely and simple
uint8_t GBA_IO_PORT_quark::exchangebyte(uint8_t b)
{
  return 0;
}
