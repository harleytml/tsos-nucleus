/* By Tsuki Superior
 * Abstract Sound Quark
 *
 * To make a new Sound quark, simply have it inherit from this class
 * 
 * The TS/OS sound api is pretty slim right now (as of version 0.0)
 */

#pragma once

#include <generic/quark.hpp>
#include <generic/types.hpp>

class Sound_quark : public Quark {
public:
    // Constructor
    Sound_quark(void);

    ~Sound_quark();

    // Play a tone
    virtual void playtone(uint32_t tone) = 0;

    virtual void killsound(void) = 0;
};
