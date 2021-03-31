//By Tsuki Superior
#include "generic/serial_module.hpp"
#include "generic/nucleus_instance.hpp"

Serial::Serial(void)
{
#ifdef __PERSONAL_COMPUTER__
  static RS232_driver rs232_driver = RS232_driver();

  attachdriver(rs232_driver);
#endif

#ifdef __GAMEBOY_ADVANCED__
  static GBA_IO_PORT_driver gba_io_port_driver = GBA_IO_PORT_driver();

  attachdriver(gba_io_port_driver);
#endif

#ifdef __RASPBERRY_PI_3__
  static RPI3_UART_driver rpi3_uart_driver = RPI3_UART_driver();

  attachdriver(rpi3_uart_driver);
#endif
}

Serial::~Serial()
{
}

uint8_t Serial::exchangebyte(uint8_t b)
{
  return isdevicethere() ? driver->exchangebyte(b) : 0x00;
}

bool Serial::isdevicethere(void)
{
  return driver->isdevicethere();
}