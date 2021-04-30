//By Tsuki Superior
#pragma once

#include <generic/current_config.hpp>
#include <generic/io_quark.hpp>
#include <generic/nucleon.hpp>
#include <generic/quark.hpp>
#include <generic/types.hpp>

// The main class controlling video
class IO : public Nucleon<IO_quark> {
public:
    // Constructor
    IO(void);

    // Destructor
    ~IO();

    // Initialize the video system
    void reset(void) const;

    // Get a uint8_t from the io ports
    uint8_t in8(size_t port);

    // Send a uint8_t through the io ports
    void out8(size_t port, uint8_t value);

    // Get a uint16_t from the io ports
    uint8_t in16(size_t port);

    // Send a uint16_t through the io ports
    void out16(size_t port, uint16_t value);

    // Get a uint32_t from the io ports
    uint8_t in32(size_t port);

    // Send a uint32_t through the io ports
    void out32(size_t port, uint32_t value);
};
