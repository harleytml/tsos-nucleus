//By Tsuki Superior
#include <vexpress-a15/vexpress-a15_uart.hpp>

VEXPRESS_A15_UART_quark::VEXPRESS_A15_UART_quark(void)
{
  name = "";
}

bool VEXPRESS_A15_UART_quark::detectsystem(void)
{
  return true;
}

void VEXPRESS_A15_UART_quark::reset(void)
{
}

bool VEXPRESS_A15_UART_quark::isdevicereadytotransmit(void)
{
  return true;
}

bool VEXPRESS_A15_UART_quark::isdevicereadytoreceive(void)
{
  return true;
}

void VEXPRESS_A15_UART_quark::outbyte(uint8_t byte)
{
  *(volatile uint32_t *)(UART0_BASE) = byte;
}

uint8_t VEXPRESS_A15_UART_quark::inbyte(void)
{
  return 0;
}