/* By Tsuki Superior
 * Sound Module
 * 
 * The wrapper module for the sound drivers
 */

#ifndef __TSOS_NUCLEUS_SOUND_NUCLEON__
#define __TSOS_NUCLEUS_SOUND_NUCLEON__

#include "generic/driver.hpp"
#include "generic/module.hpp"
#include "generic/types.hpp"
#include "generic/sound_driver.hpp"
#include "generic/current_config.hpp"

//The main class controlling sound
class Sound : public Module<Sound_driver>
{
public:
  // Constructor
  Sound(void);

  // Destructor
  ~Sound();

  // Play a tone
  void playtone(uint32_t tone);

  void killsound(void);
};

#endif
