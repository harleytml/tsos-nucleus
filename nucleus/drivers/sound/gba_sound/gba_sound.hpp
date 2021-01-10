//By Tsuki Superior
#ifndef __TSOS_GBA_SOUND_DRIVER__
#define __TSOS_GBA_SOUND_DRIVER__

#include "sound.hpp"

class GBA_SOUND_driver: public Sound_driver
{
 DMG_SOUND_driver(void);
 BOOLEAN detectsystem(void);
 void playtone(Tone tone);
};

#endif