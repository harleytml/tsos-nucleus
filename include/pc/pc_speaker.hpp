//By Tsuki Superior
#ifndef __TSOS_PC_SPEAKER_QUARK__
#define __TSOS_PC_SPEAKER_QUARK__

#include <generic/sound_quark.hpp>
#include <generic/types.hpp>

class PC_SPEAKER_quark : public Sound_quark
{
public:
  PC_SPEAKER_quark(void);
  void reset(void) final;
  bool detectsystem(void) final;
  void playtone(uint32_t tone) final;
  void killsound(void) final;
};

#endif