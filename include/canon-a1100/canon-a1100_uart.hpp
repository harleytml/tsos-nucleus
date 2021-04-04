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
  bool isdevicereadytotransmit(void) final;
  bool isdevicereadytoreceive(void) final;
  void sendbyte(uint8_t byte) final;
  uint8_t getbyte(void) final;
};

#endif
