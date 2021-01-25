//By Tsuki Superior
#ifndef __TSOS_GBA_SOUND_DRIVER__
#define __TSOS_GBA_SOUND_DRIVER__

#include "../../../subsystems/sound/sound.hpp"

class GBA_SOUND_driver : public Sound_driver
{
public:
    GBA_SOUND_driver(void);
    bool detectsystem(void);
    void playtone(Tone tone);
};

#endif