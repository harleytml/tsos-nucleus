//By Tsuki Superior
#include "sound_module.hpp"
#include "nucleus_instance.hpp"

Sound::Sound(void)
{
#ifdef __PERSONAL_COMPUTER__
  static PC_SPEAKER_driver pc_speaker_driver = PC_SPEAKER_driver();

  attachdriver(pc_speaker_driver);
#endif

#ifdef __GAMEBOY_ADVANCED__
  static GBA_SOUND_driver gba_sound_driver = GBA_SOUND_driver();

  attachdriver(gba_sound_driver);

#endif
}

Sound::~Sound(void)
{
}

void Sound::playtone(uint32_t tone)
{
  driver->playtone(tone);
}

void Sound::killsound(void)
{
  driver->killsound();
}
