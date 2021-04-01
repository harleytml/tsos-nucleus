//By Tsuki Superior
#ifndef __TSOS_RPI3_UART_QUARK__
#define __TSOS_RPI3_UART_QUARK__

#include "generic/serial_quark.hpp"

class RPI3_UART_quark : public Serial_quark
{
public:
  RPI3_UART_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  bool isdevicethere(void) final;
  uint8_t exchangebyte(uint8_t b) final;
};

#endif
