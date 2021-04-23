//By Tsuki Superior
#pragma once

#include <generic/sound_quark.hpp>

class VEXPRESS_A15_SOUND_quark : public Sound_quark
{
public:
  VEXPRESS_A15_SOUND_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  void playtone(uint32_t tone) final;
  void killsound(void) final;
};
