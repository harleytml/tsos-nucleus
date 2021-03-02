//By Tsuki Superior
#include "core.hpp"

Tsos::Tsos(void)
{
    // The version and related information of the OS
    version = 0.0;
    code_name = "Neutronium";
    short_code_name = "n";
}

Tsos::~Tsos()
{
    video.settextbackgroundcolor(0x00, 0xff, 0x00);
    video.settextforegroundcolor(0xff, 0xff, 0xff);
    video.clear();
    video.putstring("Shutting down... \n");
    video.putstring("Do not touch the power button.\n");
    process.killall();
    disk.commitall();
}

// Start the kernel

extern "C"
{
    [[noreturn]] void kernel_main(void)
    {
        static Tsos tmp = Tsos();
        tsos = tmp;
        tsos.video.reset();
        tsos.video.settextbackgroundcolor(0x00, 0x00, 0x00);
        tsos.video.putstring("Welcome to TS/OS\n");
        tsos.video.putstring("Build Date: ");
        tsos.video.putstring(__DATE__);
        tsos.video.putstring("\n");
        tsos.video.putstring("Built with GCC version: ");
        tsos.video.putstring(__VERSION__);
        tsos.video.putstring("\n");
        tsos.boot.reboot();
    }
}