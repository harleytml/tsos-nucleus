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

void RS232_quark::sendbyte(uint8_t byte)
{
}

uint8_t RS232_quark::getbyte(void)
{
  return 0;
}
