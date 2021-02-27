//By Tsuki Superior
#include "core.hpp"

Tsos::Tsos(void)
{
    // The module being used to control video
    video = Video();

    // The module being used to process input
    input = Input();

    // The module being used to control the filesystem
    filesystem = Filesystem();

    // The module being used to control boot
    boot = Boot();

    // The module being used to control serial
    serial = Serial();

    // The module being used to control process
    process = Process();

    // The module being used to control disks
    disk = Disk();

    // The module being used to control sound
    sound = Sound();

    // The version and related information of the OS
    version = 0.0;
    code_name = "Neutronium";
    short_code_name = "n";
}

Tsos::~Tsos()
{
    video.settextbackgroundcolor(0x00, 0xff, 0x00, 0x00);
    video.settextforegroundcolor(0xff, 0xff, 0xff, 0x00);
    video.clear();
    video.putstring("Shutting down... \n");
    video.putstring("Do not touch the power button.\n");
    process.killall();
    disk.commitall();
}

// Start the kernel

extern "C"
{
    void kernel_main(void)
    {
        tsos = Tsos();
        tsos.video.putstring("Welcome to TS/OS\n");
        tsos.video.putstring("Build Date: ");
        tsos.video.putstring(__DATE__);
        tsos.video.putstring("\n");
        tsos.boot.reboot();
    }
}