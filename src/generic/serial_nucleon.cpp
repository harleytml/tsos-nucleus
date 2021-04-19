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

#ifdef __NSPIRE__
  static NSPIRE_CM_UART_quark nspire_cm_uart_quark = NSPIRE_CM_UART_quark();
  static NSPIRE_CX_UART_quark nspire_cx_uart_quark = NSPIRE_CX_UART_quark();

  if (attachquark(nspire_cm_uart_quark) ||
      attachquark(nspire_cx_uart_quark))
  {
    return;
  }

#endif
}

Serial::~Serial()
{
}

void Serial::reset(void)
{
  quark->reset();
}

void Serial::outbyte(uint8_t b) const
{
  while (!isdevicereadytoreceive())
  {
  }
  quark->outbyte(b);
}

uint8_t Serial::inbyte(void) const
{
  while (!isdevicereadytotransmit())
  {
  }
  return quark->inbyte();
}

void Serial::sendbytearray(Array<uint8_t> array) const
{
  uint_fast16_t array_len = array.len();
  uint_fast16_t x = 0;
  for (x = 0; x < array_len; x++)
  {
    outbyte(array[x]);
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