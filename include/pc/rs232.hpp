//By Tsuki Superior
#ifndef __TSOS_RS232_QUARK__
#define __TSOS_RS232_QUARK__

#include "generic/serial_quark.hpp"

class RS232_quark : public Serial_quark
{
public:
  RS232_quark(void);
  void reset(void) final;
  bool detectsystem(void) final;
  bool isdevicethere(void) final;
  uint8_t exchangebyte(uint8_t b) final;
};

#endif