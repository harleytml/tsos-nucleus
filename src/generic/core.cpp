//By Tsuki Superior
#include "core.hpp"
#include "nucleus_instance.hpp"

Tsos::Tsos(void) : version(0.0), code_name("Neutronium"), short_code_name("n")
{
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

// Start the kernel
extern "C"
{
  void kernel_main(void)
  {
    char *init_file_path = "/bin/init";
    static Tsos os_instance = Tsos();
    tsos = &os_instance;

    //A memory allocation test that doesn't work rn
    //char *test = new char(10);

#ifdef __PERSONAL_COMPUTER__
    GlobalDescriptorTable gdt;
#endif

    tsos->video.settextforegroundcolor(0xff, 0xff, 0xff);
    tsos->video.settextbackgroundcolor(0x00, 0x00, 0x00);
    tsos->video.reset();
    tsos->video.clear();
    tsos->video.putstring(0, tsos->video.scroll++, "Tsuki Superior/Operating System\n");
    tsos->video.putstring(0, tsos->video.scroll++, "TS/OS Copyright (C) 2021 TSDEV Team\n");
    tsos->video.putstring(0, tsos->video.scroll++, "This program comes with ABSOLUTELY NO WARRANTY;\n");
    tsos->video.putstring(0, tsos->video.scroll++, "This is free software, and you are welcome to redistribute it\n");
    tsos->video.putstring(0, tsos->video.scroll++, "under certain conditions;\n");
    tsos->video.putstring(0, tsos->video.scroll++, "This OS wouldn't be possible without the help of the many that worked on it.\n");
    tsos->video.scroll++;
    tsos->video.putstring(0, tsos->video.scroll++, tsos->boot.name);
    tsos->video.putstring(0, tsos->video.scroll++, tsos->disk.name);
    tsos->video.putstring(0, tsos->video.scroll++, tsos->filesystem.name);
    tsos->video.putstring(0, tsos->video.scroll++, tsos->input.name);
    tsos->video.putstring(0, tsos->video.scroll++, tsos->process.name);
    tsos->video.putstring(0, tsos->video.scroll++, tsos->serial.name);
    tsos->video.putstring(0, tsos->video.scroll++, tsos->sound.name);
    tsos->video.putstring(0, tsos->video.scroll++, tsos->video.name);
    tsos->sound.playtone(100);
    tsos->video.drawpx(0, 0);

    /*
    if (!tsos->filesystem.exists(init_file_path))
    {
      tsos->video.settextbackgroundcolor(0xff, 0x00, 0x00);
      tsos->boot.fission("INIT EXECUTABLE NOT FOUND\n");
      tsos->video.putstring(0, tsos->video.scroll++, tsos->video.name);
    }
    */

    File init_executable = tsos->filesystem.open(init_file_path);

    while (true)
    {
    }
  }
}