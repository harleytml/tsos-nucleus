// By Tsuki Superior
#include <nspire/nspire-cm_sound.hpp>

NSPIRE_CM_SOUND_quark::NSPIRE_CM_SOUND_quark(void)
{
    name = "Texas Instruments Nspire CM Sound";
}

bool NSPIRE_CM_SOUND_quark::detectsystem(void) { return true; }

void NSPIRE_CM_SOUND_quark::reset(void) { }

void NSPIRE_CM_SOUND_quark::playtone(uint32_t tone) { }

void NSPIRE_CM_SOUND_quark::killsound(void) { }