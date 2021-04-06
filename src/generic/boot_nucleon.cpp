//By Tsuki Superior

#include <generic/boot_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

Boot::Boot(void)
{
#ifdef __PERSONAL_COMPUTER__
  static GRUB2_quark grub2_quark = GRUB2_quark();

  attachquark(grub2_quark);
#endif

#ifdef __RASPBERRY_PI_3__
  static RPI3_BOOT_quark rpi3_boot_quark = RPI3_BOOT_quark();

  attachquark(rpi3_boot_quark);
#endif
}

Boot::~Boot()
{
}

void Boot::reboot(void) const
{
  quark->reboot();
}

void Boot::shutdown(void) const
{
  tsos->video.settextbackgroundcolor(0xff, 0x00, 0x00);
  tsos->video.settextforegroundcolor(0xff, 0xff, 0xff);
  tsos->video.reset();
  tsos->video.clear();
  tsos->video.putstring(0, tsos->video.scroll++, "Shutting down... \n");
  tsos->video.putstring(0, tsos->video.scroll++, "Do not touch the power button.\n");
  tsos->process.killall();
  tsos->disk.commitall();
  tsos->boot.reboot();
  tsos->video.putstring(0, tsos->video.scroll++, "You may now touch the power button.\n");

  // Destroy tsos, to trigger the kernel destruction
  quark->shutdown();
}

void Boot::fission(const char *errormsg) const
{
  tsos->video.settextbackgroundcolor(0xff, 0x00, 0x00);
  tsos->video.reset();
  tsos->video.clear();
  tsos->video.putstring(0, tsos->video.scroll++, "NUCLEUS FISSION!");
  tsos->video.putstring(0, tsos->video.scroll++, errormsg);
  tsos->video.putstring(0, tsos->video.scroll++, "PLEASE REBOOT");
}