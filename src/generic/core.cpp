//By Tsuki Superior
#include "generic/core.hpp"

Tsos *tsos;

Tsos::Tsos(void) : version(0.0), code_name("Neutronium"), short_code_name("n")
{
  if (nucleuslock)
  {
    boot.fission("NUCLEUS LOCK VIOLATED");
  }
  else
  {
    nucleuslock = true;
  }
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
  boot.reboot();
  video.putstring(0, video.scroll++, "You may now touch the power button.\n");
}
