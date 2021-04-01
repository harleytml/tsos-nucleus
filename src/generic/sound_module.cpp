//By Tsuki Superior
#include "generic/sound_nucleon.hpp"
#include "generic/nucleus_instance.hpp"

Sound::Sound(void)
{
#ifdef __PERSONAL_COMPUTER__
  static PC_SPEAKER_quark pc_speaker_quark = PC_SPEAKER_quark();

  attachquark(pc_speaker_quark);
#endif

#ifdef __GAMEBOY_ADVANCED__
  static GBA_SOUND_quark gba_sound_quark = GBA_SOUND_quark();

  attachquark(gba_sound_quark);

#endif

#ifdef __RASPBERRY_PI_3__
  static RPI3_SOUND_quark rpi3_sound_quark = RPI3_SOUND_quark();

  attachquark(rpi3_sound_quark);
#endif
}

Sound::~Sound(void)
{
}

void Sound::playtone(uint32_t tone)
{
  quark->playtone(tone);
}

void Sound::killsound(void)
{
  quark->killsound();
}
