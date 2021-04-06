//By Tsuki Superior
#include <nspire/nspire-cx_uart.hpp>

NSPIRE_CX_UART_quark::NSPIRE_CX_UART_quark(void)
{
  name = "Texas Instruments Nspire CX Universal Asynchronous Receiver-Transmitter";
}

bool NSPIRE_CX_UART_quark::detectsystem(void)
{
  return true;
}

void NSPIRE_CX_UART_quark::reset(void)
{
}

bool NSPIRE_CX_UART_quark::isdevicereadytotransmit(void)
{
  return false;
}

bool NSPIRE_CX_UART_quark::isdevicereadytoreceive(void)
{
  return false;
}

void NSPIRE_CX_UART_quark::sendbyte(uint8_t byte)
{
}

uint8_t NSPIRE_CX_UART_quark::getbyte(void)
{
  return 0;
}
