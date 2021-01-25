//By Tsuki Superior
#ifndef __TSOS_DMG_SOUND_DRIVER__
#define __TSOS_DMG_SOUND_DRIVER__

#include "../../../subsystems/sound.hpp"

class DMG_SOUND_driver : public Sound_driver
{
public:
    DMG_SOUND_driver(void);
    bool detectsystem(void);
    void playtone(Tone tone);
};

#endif