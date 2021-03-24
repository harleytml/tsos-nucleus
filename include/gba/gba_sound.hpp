//By Tsuki Superior
#ifndef __TSOS_GBA_SOUND_DRIVER__
#define __TSOS_GBA_SOUND_DRIVER__

#include "sound_driver.hpp"

class GBA_SOUND_driver : public Sound_driver
{
public:
  GBA_SOUND_driver(void);
  bool detectsystem(void) override;
  void reset(void) override;
  void playtone(uint32_t tone) override;
  void killsound(void) override;
};

#endif