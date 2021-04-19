// Quark by Tsuki Superior
// Reference for serial is https://github.com/Sayan505/MuffinOS/tree/master/kernel/sys/devices/serial
#include <pc/pc_uart.hpp>
#include <generic/nucleus_instance.hpp>

PC_UART_quark::PC_UART_quark(void)
{
  name = "Personal Computer Universal Asynchronous Receiver-Transmitter";
}

bool PC_UART_quark::detectsystem(void)
{
  return true;
}

void PC_UART_quark::reset(void)
{
  tsos->io.out8(COM1 + 1, 0x00);
  tsos->io.out8(COM1 + 3, 0x80);

  set_baud(COM1, BAUD_115200); // set baud rate to 115200

  tsos->io.out8(COM1 + 3, 0x03);
  tsos->io.out8(COM1 + 2, 0xC7);
  tsos->io.out8(COM1 + 4, 0x0B);
}

bool PC_UART_quark::isdevicereadytotransmit(void)
{
  return (tsos->io.in8(COM1 + 5) & 1) != 0;
}

bool PC_UART_quark::isdevicereadytoreceive(void)
{
  return (tsos->io.in8(COM1 + 5) & 0x20) != 0;
}

void PC_UART_quark::inbyte(uint8_t byte)
{
  tsos->io.out8(COM1, byte);
}

uint8_t PC_UART_quark::outbyte(void)
{
  return tsos->io.in8(COM1);
}

void PC_UART_quark::set_baud(uint16_t port, uint8_t baud_rate)
{
}
