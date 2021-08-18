/* By Tsuki Superior
 * Nucleus Core
 *
 * This is the main file of the TS/OS source code, and its purpose is to
 * collect all the API into one class.
 *
 * All the nucleons are instaited as members of the Tsos class.
 *
 * There may only be ONE instance of the TS/OS class.
 */

#pragma once

#include <generic/boot_nucleon.hpp>
#include <generic/disk_nucleon.hpp>
#include <generic/filesystem_nucleon.hpp>
#include <generic/input_nucleon.hpp>
#include <generic/interrupt_nucleon.hpp>
#include <generic/io_nucleon.hpp>
#include <generic/memory_nucleon.hpp>
#include <generic/process_nucleon.hpp>
#include <generic/serial_nucleon.hpp>
#include <generic/sound_nucleon.hpp>
#include <generic/time_nucleon.hpp>
#include <generic/types.hpp>
#include <generic/video_nucleon.hpp>

// The main class collecting the TS/OS nucleus api
class Tsos
{
  public:
    // Constructor
    Tsos(void);

    // Destructor
    ~Tsos();

    // The nucleon being used to control io
    IO io;

    // The nucleon being used to control memory
    Memory memory;

    // The nucleon being used to control interrupt
    Interrupt interrupt;

    // The nucleon being used to control video
    Video video;

    // The nucleon being used to control disks
    Disk disk;

    // The nucleon being used to process input
    Input input;

    // The nucleon being used to control the filesystem
    Filesystem filesystem;

    // The nucleon being used to control boot
    Boot boot;

    // The nucleon being used to control serial
    Serial serial;

    // The nucleon being used to control process
    Process process;

    // The nucleon being used to control sound
    Sound sound;

    // The nucleon being used to control time
    Time time;

    // The release of TS/OS being used here
    const float release;

    // The code name to TS/OS being used here
    const char *code_name;

    // The 1-2 letter code name of TS/OS being used here
    const char *short_code_name;

    // The version of TS/OS being used here
    const uint8_t version;
};

static bool nucleuslock = false;
