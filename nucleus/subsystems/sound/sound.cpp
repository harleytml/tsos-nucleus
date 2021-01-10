//By Tsuki Superior
#include "sound.hpp"

Sound::Sound(void)
{
}

Sound::~Sound(void)
{
}

Tone::Tone(uint16_t f, uint16_t l)
{
    frequency = f;
    length = l;
}

Tone::Tone(const Tone& tone)
{
    frequency = tone.frequency;
    length = tone.length;
}