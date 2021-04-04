//By Tsuki Superior
#include "canon-a1100/canon-a1100_uart.hpp"

CANON_A1100_UART_quark::CANON_A1100_UART_quark(void)
{
  name = "Canon Powershot A1100 IS Universal Asynchronous Receiver-Transmitter";
}

bool CANON_A1100_UART_quark::detectsystem(void)
{
  return true;
}

void CANON_A1100_UART_quark::reset(void)
{
}

bool CANON_A1100_UART_quark::isdevicethere(void)
{
  return false;
}

void CANON_A1100_UART_quark::sendbyte(uint8_t byte)
{
}

uint8_t CANON_A1100_UART_quark::getbyte(void)
{
  return 0;
}