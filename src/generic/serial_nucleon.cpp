//By Tsuki Superior
#include "generic/serial_nucleon.hpp"
#include "generic/nucleus_instance.hpp"

Serial::Serial(void)
{
#ifdef __PERSONAL_COMPUTER__
  static RS232_quark rs232_quark = RS232_quark();

  attachquark(rs232_quark);
#endif

#ifdef __RASPBERRY_PI_3__
  static RPI3_UART_quark rpi3_uart_quark = RPI3_UART_quark();

  attachquark(rpi3_uart_quark);
#endif
}

Serial::~Serial()
{
}

void Serial::sendbyte(uint8_t b)
{
  if (isdevicethere())
  {
    quark->sendbyte(b);
  }
}

uint8_t Serial::getbyte(void)
{
  if (isdevicethere())
  {
    return quark->getbyte();
  }
  return 0;
}

bool Serial::isdevicethere(void)
{
  return quark->isdevicethere();
}