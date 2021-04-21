//By Tsuki Superior
#include <rpi3/rpi3_uart.hpp>
#include <generic/nucleus_instance.hpp>

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
	// Disable UART0.
	tsos->io.out32(static_cast<uint32_t>(registers::UART0_CR), 0x00000000);

	// Setup the GPIO pin 14 && 15.

	// Disable pull up/down for all GPIO pins & delay for 150 cycles.
	tsos->io.out32(static_cast<uint32_t>(registers::GPPUD), 0x00000000);
	delay(150);

	// Disable pull up/down for pin 14,15 & delay for 150 cycles.
	tsos->io.out32(static_cast<uint32_t>(registers::GPPUDCLK0), (1 << 14) | (1 << 15));
	delay(150);

	// Write 0 to GPPUDCLK0 to make it take effect.
	tsos->io.out32(static_cast<uint32_t>(registers::GPPUDCLK0), 0x00000000);

	// Clear pending interrupts.
	tsos->io.out32(static_cast<uint32_t>(registers::UART0_ICR), 0x7FF);

	// Set integer & fractional part of baud rate.
	// Divider = UART_CLOCK/(16 * Baud)
	// Fraction part register = (Fractional part * 64) + 0.5
	// Baud = 115200.

	// For Raspi3 and 4 the UART_CLOCK is system-clock dependent by default.
	// Set it to 3Mhz so that we can consistently set the baud rate
	// UART_CLOCK = 30000000;
	uint32_t r = ((*(uint32_t *)(&mbox) & ~0xF) | 8);

	// wait until we can talk to the VC
	while (tsos->io.in32(static_cast<uint32_t>(registers::MBOX_STATUS)) & 0x80000000)
	{
	}
	// send our message to property channel and wait for the response
	mmio_write((uint32_t)registers::MBOX_WRITE, r);
	while ((tsos->io.in32(static_cast<uint32_t>(registers::MBOX_STATUS)) & 0x40000000) || mmio_read((uint32_t)registers::MBOX_READ) != r)
	{
	}

	// Divider = 3000000 / (16 * 115200) = 1.627 = ~1.
	mmio_write((uint32_t)registers::UART0_IBRD, 1);
	// Fractional part register = (.627 * 64) + 0.5 = 40.6 = ~40.
	mmio_write((uint32_t)registers::UART0_FBRD, 40);

	// Enable FIFO & 8 bit data transmission (1 stop bit, no parity).
	mmio_write((uint32_t)registers::UART0_LCRH, (1 << 4) | (1 << 5) | (1 << 6));

	// Mask all interrupts.
	mmio_write((uint32_t)registers::UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
																									(1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));

	// Enable UART0, receive & transfer part of UART.
	mmio_write((uint32_t)registers::UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));
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
}

uint32_t RPI3_UART_quark::mmio_read(uint32_t reg)
{
	return 0;
}