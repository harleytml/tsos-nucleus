/*
 * By Tsuki Superior
 * 
 * This is a calculator, so idk if this will be used at all
 */

#ifndef __TSOS_NSPIRE_CM_SOUND_QUARK__
#define __TSOS_NSPIRE_CM_SOUND_QUARK__

#include <generic/sound_quark.hpp>

class NSPIRE_CM_SOUND_quark : public Sound_quark
{
public:
  NSPIRE_CM_SOUND_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  void playtone(uint32_t tone) final;
  void killsound(void) final;
};

#endif