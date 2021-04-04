// Quark by Tsuki Superior
// Reference for serial is https://github.com/Sayan505/MuffinOS/tree/master/kernel/sys/devices/serial
#include "pc/rs232.hpp"
#include "generic/nucleus_instance.hpp"

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
  tsos->io.out8(COM1 + 1, 0x00);
  tsos->io.out8(COM1 + 3, 0x80);

  set_baud(COM1, BAUD_115200); // set baud rate to 115200

  tsos->io.out8(COM1 + 3, 0x03);
  tsos->io.out8(COM1 + 2, 0xC7);
  tsos->io.out8(COM1 + 4, 0x0B);
}

bool RS232_quark::isdevicethere(void)
{
  return true;
}

void RS232_quark::sendbyte(uint8_t byte)
{
}

uint8_t RS232_quark::getbyte(void)
{
  return 0;
}

void RS232_quark::set_baud(uint16_t port, uint8_t baud_rate)
{
}
