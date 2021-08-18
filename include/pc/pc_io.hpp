#pragma once

#include <generic/io_quark.hpp>
#include <generic/types.hpp>

class PC_IO_quark : public IO_quark
{
  public:
    PC_IO_quark(void);

    ~PC_IO_quark();

    bool detectsystem(void) final;

    void reset(void) final;

    // Get a uint8_t from the io ports
    uint8_t in8(size_t port) final;

    // Send a uint8_t through the io ports
    void out8(size_t port, uint8_t value) final;

    // Get a uint16_t from the io ports
    uint16_t in16(size_t port) final;

    // Send a uint16_t through the io ports
    void out16(size_t port, uint16_t value) final;

    // Get a uint32_t from the io ports
    uint32_t in32(size_t port) final;

    // Send a uint32_t through the io ports
    void out32(size_t port, uint32_t value) final;
};
