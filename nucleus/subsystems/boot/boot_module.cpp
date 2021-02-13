//By Tsuki Superior
#include "./boot_module.hpp"

Boot::Boot(void)
{
}

Boot::~Boot(void)
{
}

void Boot::reboot(void)
{
    tsos.video.settextbackgroundcolor(0x00, 0xff, 0x00, 0x00);
    tsos.video.settextforegroundcolor(0xff, 0xff, 0xff, 0x00);
    tsos.video.clear();
    tsos.video.putstring("Rebooting... \n");
    tsos.video.putstring("Do not touch the power button.\n");
    tsos.process.killall();
    tsos.disk.commitall();
    driver->reboot();
}

void Boot::shutdown(void)
{
    tsos.video.settextbackgroundcolor(0x00, 0xff, 0x00, 0x00);
    tsos.video.settextforegroundcolor(0xff, 0xff, 0xff, 0x00);
    tsos.video.clear();
    tsos.video.putstring("Shutting down... \n");
    tsos.video.putstring("Do not touch the power button.\n");
    tsos.process.killall();
    tsos.disk.commitall();

    // Destroy tsos, to trigger the kernel destruction
    delete &tsos;
    driver->shutdown();
}

void Boot::fission(char *errormsg)
{
    tsos.video.settextbackgroundcolor(0xff, 0x00, 0x00, 0x00);
    tsos.video.settextforegroundcolor(0xff, 0xff, 0xff, 0x00);
    tsos.video.clear();
    tsos.video.putstring("Nucleus Fission!\n");
    tsos.video.putstring("TS/OS's Nucleus has detected a fatal error.\n");
    tsos.video.putstring("Error message:\n");
    tsos.video.putstring(errormsg);
    tsos.video.putstring("\n");
    tsos.video.putstring("Please report this incident to your TS/OS dealer.\n");
    tsos.video.putstring("Press any key to continue\n");

    tsos.input.waitkey();
    reboot();
}