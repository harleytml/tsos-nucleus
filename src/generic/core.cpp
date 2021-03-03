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
    video.settextbackgroundcolor(0xff, 0x00, 0x00);
    video.settextforegroundcolor(0xff, 0xff, 0xff);
    video.reset();
    video.clear();
    video.putstring("Shutting down... \n");
    video.putstring("Do not touch the power button.\n");
    process.killall();
    disk.commitall();
    boot.reboot();
}

// Start the kernel
extern "C"
{
    void kernel_main(void)
    {
        Tsos tmp = Tsos();
        tsos = tmp;

#ifdef __PERSONAL_COMPUTER__
        GlobalDescriptorTable gdt;
#endif

        tsos.video.settextforegroundcolor(0xff, 0xff, 0xff);
        tsos.video.settextbackgroundcolor(0x00, 0x00, 0x00);
        tsos.video.reset();
        tsos.video.clear();
        tsos.video.putstring("Welcome to TS/OS\n");
        tsos.video.putstring("Build Date: ");
        tsos.video.putstring(__DATE__);
        tsos.video.putstring("\n");
        tsos.video.putstring("Built with GCC version: ");
        tsos.video.putstring(__VERSION__);
        tsos.video.putstring("\n");
        tsos.video.settextbackgroundcolor(0xff, 0x00, 0x00);
        tsos.video.putstring("TS/OS Copyright (C) 2021 TSDEV Team\n");
        tsos.video.putstring("This program comes with ABSOLUTELY NO WARRANTY;\n");
        tsos.video.putstring("This is free software, and you are welcome to redistribute it\n");
        tsos.video.putstring("under certain conditions;\n");
        tsos.video.settextbackgroundcolor(0x00, 0x00, 0x00);
        tsos.video.putstring("This OS wouldn't be possible without the help of the many that worked on it.\n");

        //For now we will prevent destruction
        while (true)
        {
        }
    }
}
