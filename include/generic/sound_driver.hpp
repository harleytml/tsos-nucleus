/* By Tsuki Superior
 * Abstract Sound Driver
 *
 * To make a new Sound driver, simply have it inherit from this class
 * 
 * The TS/OS sound api is pretty slim right now (as of version 0.0)
 */

#ifndef __TSOS_NUCLEUS_SOUND_DRIVER__
#define __TSOS_NUCLEUS_SOUND_DRIVER__

#include "generic/driver.hpp"
#include "generic/types.hpp"

class Sound_driver : public Driver
{
public:
  // Constructor
  Sound_driver(void);

  ~Sound_driver();

  // Play a tone
  virtual void playtone(uint32_t tone) = 0;

  virtual void killsound(void) = 0;
};

#endif
