//By Tsuki Superior
#include <nspire/nspire-cm_uart.hpp>

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

bool NSPIRE_CM_UART_quark::isdevicereadytotransmit(void)
{
  volatile uint32_t *line_status_reg = reinterpret_cast<volatile uint32_t *>(0x90020014);
  return static_cast<bool>(*line_status_reg & 0x1);
}

bool NSPIRE_CM_UART_quark::isdevicereadytoreceive(void)
{
  return false;
}

void NSPIRE_CM_UART_quark::inbyte(uint8_t byte)
{
}

uint8_t NSPIRE_CM_UART_quark::outbyte(void)
{
  return 0;
}
