//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_CORE__
#define __TSOS_NUCLEUS_CORE__

#include "boot_module.hpp"
#include "disk_module.hpp"
#include "filesystem_module.hpp"
#include "input_module.hpp"
#include "process_module.hpp"
#include "serial_module.hpp"
#include "sound_module.hpp"
#include "video_module.hpp"
#include "boot_driver.hpp"
#include "disk_driver.hpp"
#include "filesystem_driver.hpp"
#include "input_driver.hpp"
#include "process_driver.hpp"
#include "serial_driver.hpp"
#include "sound_driver.hpp"
#include "video_driver.hpp"
#include "driver.hpp"
#include "module.hpp"
#include "types.hpp"

// The main class collecting the TS/OS nucleus api
class Tsos
{
public:
  // Constructor
  Tsos(void);

  // Destructor
  ~Tsos();

  // The module being used to control video
  Video video;

  // The module being used to control disks
  Disk disk;

  // The module being used to process input
  Input input;

  // The module being used to control the filesystem
  Filesystem filesystem;

  // The module being used to control boot
  Boot boot;

  // The module being used to control serial
  Serial serial;

  // The module being used to control process
  Process process;

  // The module being used to control sound
  Sound sound;

  // The version of TS/OS being used here
  const float version;

  // The code name to TS/OS being used here
  const char *code_name;

  // The 1-2 letter code name of TS/OS being used here
  const char *short_code_name;
};

static Tsos tsos;

#endif
