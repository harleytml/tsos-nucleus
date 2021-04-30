/* By Tsuki Superior
 * Input Nucleon
 * 
 * The wrapper nucleon for the input quarks
 */

#pragma once

#include <generic/current_config.hpp>
#include <generic/input_key_identifier.hpp>
#include <generic/input_quark.hpp>
#include <generic/nucleon.hpp>
#include <generic/quark.hpp>
#include <generic/types.hpp>

// The main class controlling input
class Input : public Nucleon<Input_quark> {
public:
    // Constructor
    Input(void);

    // Destructor
    ~Input();

    // Get the key pressed
    key_identifier getkey(void);

    // Wait for a key to be pressed
    void waitkey(void);
};

enum key_position {
    RIGHT,
    LEFT,
    MIDDLE
};
