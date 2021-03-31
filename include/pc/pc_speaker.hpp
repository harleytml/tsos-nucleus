//By Tsuki Superior
#ifndef __TSOS_PC_SPEAKER_DRIVER__
#define __TSOS_PC_SPEAKER_DRIVER__

#include "generic/sound_driver.hpp"
#include "generic/types.hpp"

class PC_SPEAKER_driver : public Sound_driver
{
public:
  PC_SPEAKER_driver(void);
  void reset(void) final;
  bool detectsystem(void) final;
  void playtone(uint32_t tone) final;
  void killsound(void) final;
};

#endif