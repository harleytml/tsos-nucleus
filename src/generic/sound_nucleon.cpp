//By Tsuki Superior
#include <generic/sound_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

Sound::Sound(void)
{
#ifdef __PERSONAL_COMPUTER__
  static PC_SPEAKER_quark pc_speaker_quark = PC_SPEAKER_quark();

  attachquark(pc_speaker_quark);
#endif

#ifdef __RASPBERRY_PI_3__
  static RPI3_SOUND_quark rpi3_sound_quark = RPI3_SOUND_quark();

  attachquark(rpi3_sound_quark);
#endif

#ifdef __NSPIRE__
  static NSPIRE_CM_SOUND_quark nspire_cm_sound_quark = NSPIRE_CM_SOUND_quark();
  static NSPIRE_CX_SOUND_quark nspire_cx_sound_quark = NSPIRE_CX_SOUND_quark();

  if (attachquark(nspire_cm_sound_quark) ||
      attachquark(nspire_cx_sound_quark))
  {
    return;
  }

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
