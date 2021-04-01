/* By Tsuki Superior
 * Gameboy Advanced Sound Driver
 */

#ifndef __TSOS_GBA_SOUND_QUARK__
#define __TSOS_GBA_SOUND_QUARK__

#include "generic/sound_driver.hpp"

class GBA_SOUND_driver : public Sound_driver
{
public:
  GBA_SOUND_driver(void);
  bool detectsystem(void) final;
  void reset(void) final;
  void playtone(uint32_t tone) final;
  void killsound(void) final;
};

#endif