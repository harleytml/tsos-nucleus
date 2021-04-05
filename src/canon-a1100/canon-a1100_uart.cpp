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
  uint32_t *uart_reg = (uint32_t *)CANON_A1100_UART_STATUS;
  *uart_reg = 0;
}

bool CANON_A1100_UART_quark::isdevicereadytotransmit(void)
{
  return false;
}

bool CANON_A1100_UART_quark::isdevicereadytoreceive(void)
{
  uint32_t *uart_reg = (uint32_t *)CANON_A1100_UART_STATUS;
  return (*uart_reg & 0xFFFFFFFE) != 0;
}

void CANON_A1100_UART_quark::sendbyte(uint8_t byte)
{
}

uint8_t CANON_A1100_UART_quark::getbyte(void)
{
  return 0;
}