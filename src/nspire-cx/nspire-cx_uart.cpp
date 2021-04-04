//By Tsuki Superior
#include "nspire-cx/nspire-cx_uart.hpp"

NSPIRE_CX_UART_quark::NSPIRE_CX_UART_quark(void)
{
  name = "Texas Instruments Nspire Universal Asynchronous Receiver-Transmitter";
}

bool NSPIRE_CX_UART_quark::detectsystem(void)
{
  return true;
}

void NSPIRE_CX_UART_quark::reset(void)
{
}

bool NSPIRE_CX_UART_quark::isdevicethere(void)
{
  return false;
}

uint8_t NSPIRE_CX_UART_quark::exchangebyte(uint8_t b)
{
  return 0;
}
