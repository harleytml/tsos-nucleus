//By Tsuki Superior
#include "generic/serial_nucleon.hpp"
#include "generic/nucleus_instance.hpp"

Serial::Serial(void)
{
#ifdef __PERSONAL_COMPUTER__
  static PC_UART_quark pc_uart_quark = PC_UART_quark();

  attachquark(pc_uart_quark);
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
  while (!isdevicereadytoreceive())
  {
  }
  quark->sendbyte(b);
}

uint8_t Serial::getbyte(void)
{
  while (!isdevicereadytotransmit())
  {
  }
  return quark->getbyte();
}

bool Serial::isdevicereadytoreceive(void)
{
  return quark->isdevicereadytoreceive();
}

bool Serial::isdevicereadytotransmit(void)
{
  return quark->isdevicereadytotransmit();
}