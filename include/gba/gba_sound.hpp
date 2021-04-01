/* By Tsuki Superior
 * Gameboy Advanced Sound Quark
 */

#ifndef __TSOS_GBA_SOUND_QUARK__
#define __TSOS_GBA_SOUND_QUARK__

#include "generic/sound_quark.hpp"

class GBA_SOUND_quark : public Sound_quark
{
public:
  GBA_SOUND_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  void playtone(uint32_t tone) final;
  void killsound(void) final;
};

#endif