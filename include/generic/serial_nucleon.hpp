/* By Tsuki Superior
 * Serial Nucleon
 * 
 * The wrapper nucleon for the serial quarks
 */

#pragma once

#include <generic/array.hpp>
#include <generic/current_config.hpp>
#include <generic/nucleon.hpp>
#include <generic/quark.hpp>
#include <generic/serial_quark.hpp>
#include <generic/types.hpp>

// The main class controlling serial
class Serial : public Nucleon<Serial_quark> {
public:
    // Constructor
    Serial(void);

    // Destructor
    ~Serial();

    void reset(void);

    // Send a byte
    void outbyte(uint8_t byte) const;

    // Get a byte
    uint8_t inbyte(void) const;

    // Is device ready to take a byte
    bool isdevicereadytoreceive(void) const;

    // Is device ready to send a byte
    bool isdevicereadytotransmit(void) const;

    // Send a array of bytes
    void sendbytearray(Array<uint8_t> array) const;
};
