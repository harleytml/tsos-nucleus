/* By Tsuki Superior
 * Nucleus Core
 *
 * This is the main file of the TS/OS source code, and its purpose is to
 * collect all the API into one class.
 * 
 * All the modules are instaited as members of the Tsos class.
 * 
 * There may only be ONE instance of the TS/OS class. Future updates will have a lock
 * to make sure this rule is enforced.
 */

#ifndef __TSOS_NUCLEUS_CORE__
#define __TSOS_NUCLEUS_CORE__

#include "generic/boot_module.hpp"
#include "generic/disk_module.hpp"
#include "generic/filesystem_module.hpp"
#include "generic/input_module.hpp"
#include "generic/process_module.hpp"
#include "generic/serial_module.hpp"
#include "generic/sound_module.hpp"
#include "generic/video_module.hpp"
#include "generic/io_module.hpp"
#include "generic/types.hpp"

// The main class collecting the TS/OS nucleus api
class Tsos
{
public:
  // Constructor
  Tsos(void);

  // Destructor
  ~Tsos();

  // The module being used to control io
  IO io;

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

#endif
