//By Tsuki Superior
#ifndef __TSOS_NSPIRE_CX_UART_QUARK__
#define __TSOS_NSPIRE_CX_UART_QUARK__

#include <generic/serial_quark.hpp>

#define MMIO_BASE (0x90020000)

class NSPIRE_CX_UART_quark : public Serial_quark
{
public:
  NSPIRE_CX_UART_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  bool isdevicereadytotransmit(void) final;
  bool isdevicereadytoreceive(void) final;
  void inbyte(uint8_t byte) final;
  uint8_t outbyte(void) final;
};

#endif
