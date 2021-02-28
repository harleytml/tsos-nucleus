//By Tsuki Superior
#include "core.hpp"

Tsos::Tsos(void) : input(Input()), filesystem(Filesystem()), boot(Boot()), serial(Serial()), process(Process()), disk(Disk()), sound(Sound()), video(Video())
{
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
        tsos.video.reset();
        tsos.video.putstring("Welcome to TS/OS\n");
        tsos.video.putstring("Build Date: ");
        tsos.video.putstring(__DATE__);
        tsos.video.putstring("\n");
        tsos.boot.reboot();
    }
}