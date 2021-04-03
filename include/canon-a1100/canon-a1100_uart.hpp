//By Tsuki Superior
#ifndef __TSOS_CANON_A1100_UART_QUARK__
#define __TSOS_CANON_A1100_UART_QUARK__

#include "generic/serial_quark.hpp"

class CANON_A1100_UART_quark : public Serial_quark
{
public:
  CANON_A1100_UART_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  bool isdevicethere(void) final;
  uint8_t exchangebyte(uint8_t b) final;
};

#endif
