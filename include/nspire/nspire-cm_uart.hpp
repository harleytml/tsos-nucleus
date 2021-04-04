//By Tsuki Superior
#ifndef __TSOS_NSPIRE_CM_UART_QUARK__
#define __TSOS_NSPIRE_CM_UART_QUARK__

#include "generic/serial_quark.hpp"

class NSPIRE_CM_UART_quark : public Serial_quark
{
public:
  NSPIRE_CM_UART_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  bool isdevicethere(void) final;
  uint8_t exchangebyte(uint8_t b) final;
};

#endif
