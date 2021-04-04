//By Tsuki Superior
#ifndef __TSOS_RS232_QUARK__
#define __TSOS_RS232_QUARK__

#include "generic/serial_quark.hpp"

#define BAUD_115200 (0x01)
#define COM1 (0x3F8)

class RS232_quark : public Serial_quark
{
public:
  RS232_quark(void);
  void reset(void) final;
  bool detectsystem(void) final;
  bool isdevicethere(void) final;
  void sendbyte(uint8_t byte) final;
  uint8_t getbyte(void) final;

private:
  void set_baud(uint16_t port, uint8_t baud_rate);
};

#endif