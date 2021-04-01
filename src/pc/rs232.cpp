//Quark by Tsuki Superior
#include "pc/rs232.hpp"

RS232_quark::RS232_quark(void)
{
  name = "Recommended Standard 232";
}

bool RS232_quark::detectsystem(void)
{
  return true;
}

void RS232_quark::reset(void)
{
}

bool RS232_quark::isdevicethere(void)
{
  return false;
}

uint8_t RS232_quark::exchangebyte(uint8_t b)
{
  return 0;
}
