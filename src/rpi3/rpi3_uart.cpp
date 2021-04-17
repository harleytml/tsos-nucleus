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
  return (mmio_read((uint32_t)registers::AUX_MU_LSR_REG) & (1 << 4)) == 1;
}

bool RPI3_UART_quark::isdevicereadytoreceive(void)
{
  return (mmio_read((uint32_t)registers::AUX_MU_LSR_REG) & (1 << 5)) == 1;
}

void RPI3_UART_quark::sendbyte(uint8_t byte)
{
  mmio_write((uint32_t)registers::AUX_MU_IO_REG, byte);
}

uint8_t RPI3_UART_quark::getbyte(void)
{
  return mmio_read(((uint32_t)registers::AUX_MU_IO_REG) & 0xFF);
}