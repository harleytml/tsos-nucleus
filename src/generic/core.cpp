// By Tsuki Superior
#include <generic/core.hpp>

Tsos *tsos;

Tsos::Tsos(void) : release(0.0), code_name("Neutronium"), short_code_name("n"), version(0)
{
    static Font font = get_default_font();
    if (nucleuslock)
    {
        boot.fission("NUCLEUS LOCK VIOLATED");
    }
    else
    {
        nucleuslock = true;
    }
    video.setfont(font);
}

Tsos::~Tsos()
{
    video.settextbackgroundcolor(0xff, 0x00, 0x00);
    video.settextforegroundcolor(0xff, 0xff, 0xff);
    video.reset();
    video.clear();
    video.putstring(0, video.scroll++, "Shutting down... \n");
    video.putstring(0, video.scroll++, "Do not touch the power button.\n");
    process.killall();
    disk.commitall();
    boot.shutdown();
}
