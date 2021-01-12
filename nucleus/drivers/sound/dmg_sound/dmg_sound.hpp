//By Tsuki Superior
#ifndef __TSOS_DMG_SOUND_DRIVER__
#define __TSOS_DMG_SOUND_DRIVER__

#include "sound.hpp"

class DMG_SOUND_driver : public Sound_driver
{
public:
    DMG_SOUND_driver(void);
    BOOLEAN detectsystem(void);
    void playtone(Tone tone);
};

#endif