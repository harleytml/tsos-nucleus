// By Tsuki Superior
#include <nspire/nspire-cx_sound.hpp>

NSPIRE_CX_SOUND_quark::NSPIRE_CX_SOUND_quark(void)
{
    name = "Texas Instruments Nspire CX Sound";
}

bool NSPIRE_CX_SOUND_quark::detectsystem(void) { return true; }

void NSPIRE_CX_SOUND_quark::reset(void) { }

void NSPIRE_CX_SOUND_quark::playtone(uint32_t tone) { }

void NSPIRE_CX_SOUND_quark::killsound(void) { }