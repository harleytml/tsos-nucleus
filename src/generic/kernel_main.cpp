#include <generic/kernel_main.hpp>

void kernel_main(void)
{
  static Tsos os_instance = Tsos();
  uint_fast8_t pos = 0;
  tsos = &os_instance;
  char *init_file_path = "/bin/init";
  char *serialmessage = "Welcome to TS/OS";
  char *timemessage = new char[20];
  volatile uint64_t time;

#ifdef __PERSONAL_COMPUTER__
  GlobalDescriptorTable gdt;
#endif

  tsos->video.settextforegroundcolor(0xff, 0xff, 0xff);
  tsos->video.settextbackgroundcolor(0x00, 0x00, 0x00);
  tsos->video.reset();
  tsos->video.clear();
  tsos->video.putstring(0, tsos->video.scroll++, "Tsuki Superior/Operating System\n");
  tsos->video.putstring(0, tsos->video.scroll++, "TS/OS Copyright (C) 2021 TSDEV Team\n");
  tsos->video.putstring(0, tsos->video.scroll++, "This OS wouldn't be possible without the help of the many that worked on it.\n");
  tsos->video.scroll++;
  tsos->video.putstring(0, tsos->video.scroll++, tsos->boot.name);
  tsos->video.putstring(0, tsos->video.scroll++, tsos->disk.name);
  tsos->video.putstring(0, tsos->video.scroll++, tsos->filesystem.name);
  tsos->video.putstring(0, tsos->video.scroll++, tsos->input.name);
  tsos->video.putstring(0, tsos->video.scroll++, tsos->io.name);
  tsos->video.putstring(0, tsos->video.scroll++, tsos->memory.name);
  tsos->video.putstring(0, tsos->video.scroll++, tsos->process.name);
  tsos->video.putstring(0, tsos->video.scroll++, tsos->serial.name);
  tsos->video.putstring(0, tsos->video.scroll++, tsos->sound.name);
  tsos->video.putstring(0, tsos->video.scroll++, tsos->video.name);
  tsos->video.putstring(0, tsos->video.scroll++, tsos->time.name);

  // This is quite annoying, so I'll comment it out
  // tsos->sound.playtone(100);

  tsos->video.drawpx(0, 0);
  uint8_t slen = strnlen(serialmessage, 100);
  while (pos < slen)
  {
    tsos->serial.outbyte(serialmessage[pos++]);
  }
  tsos->serial.outbyte('\n');

  while (true)
  {
    time = tsos->time.gettimestamp();
#ifdef __i386__
    timemessage = itoa(time, timemessage, 10);
    tsos->video.putstring(0, tsos->video.scroll, timemessage);
#endif
  }

  if (!tsos->filesystem.exists(init_file_path))
  {
    tsos->boot.fission("INIT EXECUTABLE NOT FOUND");
  }
  else
  {
    File init_executable = tsos->filesystem.open(init_file_path);
    if (!init_executable.permissions.execute)
    {
      tsos->boot.fission("INIT EXECUTABLE INVALID");
    }
  }
}
