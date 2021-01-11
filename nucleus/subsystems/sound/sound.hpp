//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_SOUND__
#define __TSOS_NUCLEUS_SOUND__

#include "core.hpp"

//Oh boy, this should be fun
//I know very little about audio in electronics
//Well, guess I better learn...

//The main class controlling sound
class Sound : public Module
{
public:
  //Constructor
  Sound(void);

  //Destructor
  ~Sound(void);

  //Play a tone
  void playtone(Tone tone);

private:
  //Sound driver
  Sound_driver *driver;
};

class Sound_driver : public Driver
{
public:
  //Constructor
  Sound_driver(void);

  //Play a tone
  void playtone(Tone tone);
};

class Tone
{
public:
  //Constructor
  Tone(uint16_t f, uint16_t l);

  //Constructor to copy a tone
  Tone(const Tone &tone);

  //The frequency of the tone
  uint16_t frequency;

  //The length of the tone
  uint16_t length;
};

#endif