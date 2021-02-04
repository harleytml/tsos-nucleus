//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_CORE__
#define __TSOS_NUCLEUS_CORE__

#include "../subsystems/boot/boot.hpp"
#include "../subsystems/disk/disk.hpp"
#include "../subsystems/filesystem/filesystem.hpp"
#include "../subsystems/input/input.hpp"
#include "../subsystems/process/process.hpp"
#include "../subsystems/serial/serial.hpp"
#include "../subsystems/sound/sound.hpp"
#include "../subsystems/video/video.hpp"
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
