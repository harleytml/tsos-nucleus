#include <generic/kernel_main.hpp>

void kernel_main(void)
{
  static Tsos os_instance = Tsos();
  uint_fast8_t pos = 0;
  tsos = &os_instance;
  char *init_file_path = "/bin/init";
  char *str = "Welcome to TS/OS";
  volatile uint64_t time;

#ifdef __PERSONAL_COMPUTER__
  GlobalDescriptorTable gdt;
#endif

#ifdef __RASPBERRY_PI_3__
  tsos->serial.reset();
#endif

  tsos->video.settextforegroundcolor(0xff, 0xff, 0xff);
  tsos->video.settextbackgroundcolor(0x00, 0x00, 0x00);
  tsos->video.reset();
  tsos->video.clear();
  tsos->video.scroll++;

  debug_msg("Tsuki Superior/Operating System\n");
  debug_msg("TS/OS Copyright (C) 2021 TSDEV Team\n");
  debug_msg("This OS wouldn't be possible without the help of the many that worked on it.\n");
  tsos->video.scroll++;
  debug_msg(tsos->boot.name);
  debug_msg(tsos->disk.name);
  debug_msg(tsos->filesystem.name);
  debug_msg(tsos->input.name);
  debug_msg(tsos->io.name);
  debug_msg(tsos->memory.name);
  debug_msg(tsos->process.name);
  debug_msg(tsos->serial.name);
  debug_msg(tsos->sound.name);
  debug_msg(tsos->video.name);
  debug_msg(tsos->time.name);

  // This is quite annoying, so I'll comment it out
  // tsos->sound.playtone(100);

  while (true)
  {
#ifdef __PERSONAL_COMPUTER__
    time = tsos->time.gettimestamp();
    char *timemessage = new char[20];
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

void debug_msg(char *str)
{
  uint_fast8_t pos = 0;

  uint8_t slen = strnlen(str, 100);
  while (pos < slen)
  {
    tsos->serial.outbyte(str[pos++]);
  }
  tsos->serial.outbyte('\n');
  tsos->video.putstring(0, tsos->video.scroll++, str);
}
