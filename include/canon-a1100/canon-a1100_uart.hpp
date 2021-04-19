//By Tsuki Superior
#ifndef __TSOS_CANON_A1100_UART_QUARK__
#define __TSOS_CANON_A1100_UART_QUARK__

#include <generic/serial_quark.hpp>

#define CANON_A1100_TX (0xc0800000)
#define CANON_A1100_RX (0xc0800004)
#define CANON_A1100_UART_STATUS (0xc0800014)

class CANON_A1100_UART_quark : public Serial_quark
{
public:
  CANON_A1100_UART_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  bool isdevicereadytotransmit(void) final;
  bool isdevicereadytoreceive(void) final;
  void inbyte(uint8_t byte) final;
  uint8_t outbyte(void) final;
};

#endif
