//By Tsuki Superior
#ifndef __TSOS_RPI3_UART_DRIVER__
#define __TSOS_RPI3_UART_DRIVER__

#include "serial_driver.hpp"

class RPI3_UART_driver : public Serial_driver
{
public:
  RPI3_UART_driver(void);
  bool detectsystem(void) override;
  void reset(void) override;
  bool isdevicethere(void) override;
  uint8_t exchangebyte(uint8_t b) override;
};

#endif
