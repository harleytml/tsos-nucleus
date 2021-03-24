//By Tsuki Superior
#include "rpi3_uart.hpp"

RPI3_UART_driver::RPI3_UART_driver(void)
{
  name = "Raspberry Pi 3 Universal Asynchronous Receiver-Transmitter";
}

bool RPI3_UART_driver::detectsystem(void)
{
  return true;
}

void RPI3_UART_driver::reset(void)
{
}

bool RPI3_UART_driver::isdevicethere(void)
{
  return false;
}

uint8_t RPI3_UART_driver::exchangebyte(uint8_t b)
{
  return 0;
}
