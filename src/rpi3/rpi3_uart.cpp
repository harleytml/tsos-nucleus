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
  return mmio_read((uint32_t)registers::UART0_FR) & (1 << 4);
}

bool RPI3_UART_quark::isdevicereadytoreceive(void)
{
  return mmio_read((uint32_t)registers::UART0_FR) & (1 << 5);
}

void RPI3_UART_quark::outbyte(uint8_t byte)
{
	mmio_write((uint32_t)registers::UART0_DR, byte);
}

uint8_t RPI3_UART_quark::inbyte(void)
{
    return mmio_read((uint32_t)registers::UART0_DR);
}

void RPI3_UART_quark::mmio_write(uint32_t reg, uint32_t data)
{
	*(volatile uint32_t *)((uintptr_t)registers::MMIO_BASE + reg) = data;
}

uint32_t RPI3_UART_quark::mmio_read(uint32_t reg)
{
	return *(volatile uint32_t*)((uintptr_t)registers::MMIO_BASE + reg);
}