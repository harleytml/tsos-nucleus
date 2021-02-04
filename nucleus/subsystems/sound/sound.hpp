//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_SOUND__
#define __TSOS_NUCLEUS_SOUND__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"
#include "../../core/types.hpp"
#include "../../core/core.hpp"

class Tone
{
public:
  // Constructor
  Tone(uint16_t f, uint16_t l);

  // Constructor to copy a tone
  Tone(const Tone &tone);

  // The frequency of the tone
  uint16_t frequency;

  // The length of the tone
  uint16_t length;
};

class Sound_driver : public Driver
{
public:
  // Constructor
  Sound_driver(void);

  // Play a tone
  virtual void playtone(Tone tone) = 0;
};

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
