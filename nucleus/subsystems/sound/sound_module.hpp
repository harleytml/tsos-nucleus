//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_SOUND_MODULE__
#define __TSOS_NUCLEUS_SOUND_MODULE__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"
#include "../../core/types.hpp"
#include "./sound_driver.hpp"
#include "./sound_tone.hpp"

//The main class controlling sound
class Sound : public Module<Sound_driver>
{
public:
  // Constructor
  Sound(void);

  // Destructor
  ~Sound();

  // Play a tone
  void playtone(Tone tone);

private:
  // Sound driver
  Sound_driver *driver;
};

#endif
