//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_SOUND_TONE__
#define __TSOS_NUCLEUS_SOUND_TONE__

#include "../../core/types.hpp"

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

#endif