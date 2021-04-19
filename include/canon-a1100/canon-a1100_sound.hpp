//By Tsuki Superior
#pragma once

#include <generic/sound_quark.hpp>

class CANON_A1100_SOUND_quark : public Sound_quark
{
public:
  CANON_A1100_SOUND_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  void playtone(uint32_t tone) final;
  void killsound(void) final;
};
