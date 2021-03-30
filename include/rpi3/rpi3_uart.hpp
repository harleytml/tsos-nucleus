//By Tsuki Superior
#ifndef __TSOS_RPI3_UART_DRIVER__
#define __TSOS_RPI3_UART_DRIVER__

#include "serial_driver.hpp"

class RPI3_UART_driver : public Serial_driver
{
public:
  RPI3_UART_driver(void);
  bool detectsystem(void) final;
  void reset(void) final;
  bool isdevicethere(void) final;
  uint8_t exchangebyte(uint8_t b) final;
};

#endif
