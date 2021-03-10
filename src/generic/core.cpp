//By Tsuki Superior
#include "core.hpp"

Tsos::Tsos(void) : version(0.0), code_name("Neutronium"), short_code_name("n")
{
}

Tsos::~Tsos()
{
    uint16_t scroll = 0;
    video.settextbackgroundcolor(0xff, 0x00, 0x00);
    video.settextforegroundcolor(0xff, 0xff, 0xff);
    video.reset();
    video.clear();
    video.putstring(0, scroll++, "Shutting down... \n");
    video.putstring(0, scroll++, "Do not touch the power button.\n");
    process.killall();
    disk.commitall();
    boot.reboot();
    video.putstring(0, scroll++, "You may now touch the power button.\n");
}

// Start the kernel
extern "C"
{
    void kernel_main(void)
    {
        char *init_file_path = "/bin/init";
        uint16_t scroll = 0;
        Tsos tsos = Tsos();

#ifdef __PERSONAL_COMPUTER__
        GlobalDescriptorTable gdt;
#endif

        tsos.video.settextforegroundcolor(0xff, 0xff, 0xff);
        tsos.video.settextbackgroundcolor(0x00, 0x00, 0x00);
        tsos.video.reset();
        tsos.video.clear();
        tsos.video.putstring(0, scroll++, "Welcome to TS/OS\n");
        tsos.video.putstring(0, scroll++, "TS/OS Copyright (C) 2021 TSDEV Team\n");
        tsos.video.putstring(0, scroll++, "This program comes with ABSOLUTELY NO WARRANTY;\n");
        tsos.video.putstring(0, scroll++, "This is free software, and you are welcome to redistribute it\n");
        tsos.video.putstring(0, scroll++, "under certain conditions;\n");
        tsos.video.putstring(0, scroll++, "This OS wouldn't be possible without the help of the many that worked on it.\n");
        if (!tsos.filesystem.exists(init_file_path))
        {
            tsos.video.settextbackgroundcolor(0xff, 0x00, 0x00);
            tsos.video.putstring(0, scroll++, "The init file was not found\n");
            tsos.boot.fission("INIT EXECUTABLE NOT FOUND\n");
        }

        File init_executable = tsos.filesystem.open("/bin/init");

        //For now we will prevent destruction
        while (true)
        {
        }
    }
}
