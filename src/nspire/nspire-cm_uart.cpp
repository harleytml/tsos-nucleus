//By Tsuki Superior
#include "nspire/nspire-cm_uart.hpp"

NSPIRE_CM_UART_quark::NSPIRE_CM_UART_quark(void)
{
  name = "Texas Instruments Nspire CM Universal Asynchronous Receiver-Transmitter";
}

bool NSPIRE_CM_UART_quark::detectsystem(void)
{
  return true;
}

void NSPIRE_CM_UART_quark::reset(void)
{
}

bool NSPIRE_CM_UART_quark::isdevicethere(void)
{
  return false;
}

void NSPIRE_CM_UART_quark::sendbyte(uint8_t byte)
{
}

uint8_t NSPIRE_CM_UART_quark::getbyte(void)
{
  return 0;
}
