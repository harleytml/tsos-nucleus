// By Tsuki Superior
#pragma once

#include <generic/serial_quark.hpp>

class VEXPRESS_A15_UART_quark : public Serial_quark
{
  public:
    VEXPRESS_A15_UART_quark(void);
    bool detectsystem(void) final;
    void reset(void) final;
    bool isdevicereadytotransmit(void) final;
    bool isdevicereadytoreceive(void) final;
    void outbyte(uint8_t byte) final;
    uint8_t inbyte(void) final;

  private:
    enum class registers : uint32_t
    {
        UART0DR = 0x101f1000
    };
};
