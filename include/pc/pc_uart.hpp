//By Tsuki Superior
#pragma once

#include <generic/serial_quark.hpp>

#define BAUD_115200 (0x01)
#define COM1 (0x3F8)
#define COM2 (0x2F8)
#define COM3 (0x3E8)
#define COM4 (0x2E8)

class PC_UART_quark : public Serial_quark {
public:
    PC_UART_quark(void);
    void reset(void) final;
    bool detectsystem(void) final;
    bool isdevicereadytotransmit(void) final;
    bool isdevicereadytoreceive(void) final;
    void outbyte(uint8_t byte) final;
    uint8_t inbyte(void) final;

private:
    void set_baud(uint16_t port, uint8_t baud_rate);
};
