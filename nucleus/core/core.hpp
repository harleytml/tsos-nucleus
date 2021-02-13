//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_CORE__
#define __TSOS_NUCLEUS_CORE__

#include "../subsystems/boot/boot_module.hpp"
#include "../subsystems/disk/disk_module.hpp"
#include "../subsystems/filesystem/filesystem_module.hpp"
#include "../subsystems/input/input_module.hpp"
#include "../subsystems/process/process_module.hpp"
#include "../subsystems/serial/serial_module.hpp"
#include "../subsystems/sound/sound_module.hpp"
#include "../subsystems/video/video_module.hpp"
#include "../subsystems/boot/boot_driver.hpp"
#include "../subsystems/disk/disk_driver.hpp"
#include "../subsystems/filesystem/filesystem_driver.hpp"
#include "../subsystems/input/input_driver.hpp"
#include "../subsystems/process/process_driver.hpp"
#include "../subsystems/serial/serial_driver.hpp"
#include "../subsystems/sound/sound_driver.hpp"
#include "../subsystems/video/video_driver.hpp"
#include "./driver.hpp"
#include "./module.hpp"
#include "./types.hpp"

// This file is customized by for the system
#include "../../build/current_config.hpp"

extern void kernel_main(void);

// The machine's type
enum machine_type
{
  PERSONAL_COMPUTER,
  DOT_MATRIX_GAME,
  GAMEBOY_ADVANCE,
  GENERIC,
  UNKNOWN
};

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

  // The module being used to control disks
  Disk disk;

  // The module being used to control sound
  Sound sound;

protected:
  // The version of TS/OS being used here
  float version;

  // The code name to TS/OS being used here
  char *code_name;

  // The 1-2 letter code name of TS/OS being used here
  char *short_code_name;

  // The type of machine being run here
  machine_type machine = MACHINE;
};

Tsos tsos;

#endif
