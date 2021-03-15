//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_SOUND_TONE__
#define __TSOS_NUCLEUS_SOUND_TONE__

#include "types.hpp"

class Tone
{
public:
  // Constructor
  Tone(uint32_t f, uint16_t l);

  // Constructor to copy a tone
  Tone(const Tone &tone);

  ~Tone();

  // The frequency of the tone
  uint32_t frequency;

  // The length of the tone
  uint16_t length;
};

#endif