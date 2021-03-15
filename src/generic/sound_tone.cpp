// By Tsuki Superior
#include "sound_tone.hpp"

Tone::Tone(uint32_t f, uint16_t l) : frequency(f), length(l)
{
}

Tone::Tone(const Tone &tone) : frequency(tone.frequency), length(tone.length)
{
}

Tone::~Tone()
{
}