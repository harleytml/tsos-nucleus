//By Tsuki Superior
#include <generic/serial_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

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

void Serial::reset(void)
{
  quark->reset();
}

void Serial::inbyte(uint8_t b) const
{
  while (!isdevicereadytoreceive())
  {
  }
  quark->inbyte(b);
}

uint8_t Serial::outbyte(void) const
{
  while (!isdevicereadytotransmit())
  {
  }
  return quark->outbyte();
}

void Serial::sendbytearray(Array<uint8_t> array) const
{
  uint_fast16_t array_len = array.len();
  uint_fast16_t x = 0;
  for (x = 0; x < array_len; x++)
  {
    inbyte(array[x]);
  }
}

bool Serial::isdevicereadytoreceive(void) const
{
  return quark->isdevicereadytoreceive();
}

bool Serial::isdevicereadytotransmit(void) const
{
  return quark->isdevicereadytotransmit();
}