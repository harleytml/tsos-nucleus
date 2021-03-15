//By Tsuki Superior
#ifndef __TSOS_PC_SPEAKER_DRIVER__
#define __TSOS_PC_SPEAKER_DRIVER__

#include "sound_driver.hpp"
#include "io.hpp"
#include "types.hpp"

class PC_SPEAKER_driver : public Sound_driver
{
public:
  PC_SPEAKER_driver(void);
  void reset(void) override;
  bool detectsystem(void) override;
  void playtone(uint32_t tone) override;
  void killsound(void) override;
};

#endif