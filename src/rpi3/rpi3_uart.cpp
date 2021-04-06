//By Tsuki Superior
#include <rpi3/rpi3_uart.hpp>

RPI3_UART_quark::RPI3_UART_quark(void)
{
  name = "Raspberry Pi 3 Universal Asynchronous Receiver-Transmitter";
}

bool RPI3_UART_quark::detectsystem(void)
{
  return true;
}

void RPI3_UART_quark::reset(void)
{
}

bool RPI3_UART_quark::isdevicereadytotransmit(void)
{
  return false;
}

bool RPI3_UART_quark::isdevicereadytoreceive(void)
{
  return false;
}

void RPI3_UART_quark::sendbyte(uint8_t byte)
{
}

uint8_t RPI3_UART_quark::getbyte(void)
{
  return 0;
}