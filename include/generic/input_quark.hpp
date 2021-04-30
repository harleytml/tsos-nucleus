/* By Tsuki Superior
 * Abstract Input Quark
 *
 * To make a new Input quark, simply have it inherit from this class
 */

#pragma once

#include <generic/input_key_identifier.hpp>
#include <generic/quark.hpp>
#include <generic/types.hpp>

class Input_quark : public Quark
{
  public:
    // Constructor
    Input_quark(void);

    // Deconstructor
    ~Input_quark();

    // Read a key, and convert its scancode
    virtual key_identifier getkey(void) = 0;

    // Is shift pressed
    virtual bool isshiftpressed(void) = 0;

    // Wait key
    virtual void waitkey(void) = 0;

    // Is alt pressed
    virtual bool isaltpressed(void) = 0;

    // Is ctrl pressed
    virtual bool isctrlpressed(void) = 0;
};
