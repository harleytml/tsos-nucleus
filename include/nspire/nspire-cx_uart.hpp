//By Tsuki Superior
#pragma once

#include <generic/serial_quark.hpp>

#define MMIO_BASE (0x90020000)

class NSPIRE_CX_UART_quark : public Serial_quark {
public:
    NSPIRE_CX_UART_quark(void);
    bool detectsystem(void) final;
    void reset(void) final;
    bool isdevicereadytotransmit(void) final;
    bool isdevicereadytoreceive(void) final;
    void outbyte(uint8_t byte) final;
    uint8_t inbyte(void) final;
};
