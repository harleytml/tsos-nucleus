//By Tsuki Superior
#ifndef __TSOS_GBA_SOUND_DRIVER__
#define __TSOS_GBA_SOUND_DRIVER__

#include "sound_driver.hpp"

class PSX_SOUND_driver : public Sound_driver
{
public:
    PSX_SOUND_driver(void);
    void reset(void) override;
    bool detectsystem(void) override;
    void playtone(Tone tone) override;
};

#endif