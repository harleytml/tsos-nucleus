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

// This file is generated by the Makefile
#include "../../build/current_config.hpp"

typedef __UINT8_TYPE__ uint8_t;
typedef __UINT16_TYPE__ uint16_t;
typedef __UINT32_TYPE__ uint32_t;
typedef __INT8_TYPE__ int8_t;
typedef __INT16_TYPE__ int16_t;
typedef __INT32_TYPE__ int32_t;

const uint8_t NULL = '\0';

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
  ~Tsos(void);

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

// The class for drivers

class Driver
{
public:
  // Constructor
  Driver(void);

  // Destructor
  ~Driver(void);

  // A function called to determine if a driver should be used.
  virtual bool detectsystem(void) = NULL;

  // The name of said module
  char *name;
};

// The base class of TS/OS modules
templete<class T> class Module
{
public:
  // Constructor
  Module(void);

  // Destructor
  ~Module(void);

  // The full name of the modules's target
  const char *name;

  // Attach a driver
  void attachdriver(T d);

private:
  T *driver;
};

static Tsos tsos;

#endif
