//By Tsuki Superior
#include "sound_module.hpp"
#include "nucleus_instance.hpp"

Sound::Sound(void)
{
#ifdef __GAMEBOY_ADVANCED__
    static GBA_SOUND_driver gba_sound_driver = GBA_SOUND_driver();

    attachdriver(gba_sound_driver);

#endif

#ifdef __PLAYSTATION_X__
    static PSX_SOUND_driver psx_sound_driver = PSX_SOUND_driver();

    attachdriver(psx_sound_driver);
#endif
}

Sound::~Sound(void)
{
}