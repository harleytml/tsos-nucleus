/* By Tsuki Superior
 * Sound Nucleon
 * 
 * The wrapper nucleon for the sound quarks
 */

#pragma once

#include <generic/current_config.hpp>
#include <generic/nucleon.hpp>
#include <generic/quark.hpp>
#include <generic/sound_quark.hpp>
#include <generic/types.hpp>

//The main class controlling sound
class Sound : public Nucleon<Sound_quark> {
public:
    // Constructor
    Sound(void);

    // Destructor
    ~Sound();

    // Play a tone
    void playtone(uint32_t tone);

    void killsound(void);
};
