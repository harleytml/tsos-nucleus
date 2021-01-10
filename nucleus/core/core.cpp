//By Tsuki Superior
#include "api.hpp"

Tsos::Tsos(void)
{

    //Set the versioning info of this OS
    version = 1.0;
    code_name = "Hydrogen";
    short_code_name = "H";

    //This may be the dumbest init system known to man...
    //But how else do I do this?
    video = new Tsos_video();
    input = new Tsos_input();
    filesystem = new Tsos_filesystem();
    boot = new Tsos_boot();
    serial = new Tsos_serial();
    process = new Tsos_process();
    disk = new Tsos_disk();

    //All these define based constants are in a generated header file (see core.hpp)
    Driver video_drivers[] = VIDEO_DRIVERS;
    Driver input_drivers[] = INPUT_DRIVERS;
    Driver filesystem_drivers[] = FILESYSTEM_DRIVERS;
    Driver boot_drivers[] = BOOT_DRIVERS;
    Driver serial_drivers[] = SERIAL_DRIVERS;
    Driver process_drivers[] = PROCESS_DRIVERS;
    Driver disk_drivers[] = DISK_DRIVERS;

    //Attach video drivers
    for (uint8_t x = 0; x < VIDEO_DRIVER_COUNT; x++)
    {
        video.attachdriver(video_drivers[x]);
    }

    //Attach input drivers
    for (x = 0; x < INPUT_DRIVER_COUNT; x++)
    {
        input.attachdriver(input_drivers[x]);
    }

    //Attach filesystem drivers
    for (x = 0; x < FILESYSTEM_DRIVER_COUNT; x++)
    {
        filesystem.attachdriver(filesystem_drivers[x]);
    }

    //Attach boot drivers
    for (x = 0; x < BOOT_DRIVER_COUNT; x++)
    {
        boot.attachdriver(boot_drivers[x]);
    }

    //Attach serial drivers
    for (x = 0; x < SERIAL_DRIVER_COUNT; x++)
    {
        serial.attachdriver(serial_drivers[x]);
    }

    //Attach process drivers
    for (x = 0; x < PROCESS_DRIVER_COUNT; x++)
    {
        process.attachdriver(process_drivers[x]);
    }

    //Attach disk drivers
    for (x = 0; x < DISK_DRIVER_COUNT; x++)
    {
        disk.attachdriver(disk_drivers[x]);
    }
}

Tsos::~Tsos(void)
{

    //Deconstruct the subclasses
    delete video;
    delete input;
    delete filesystem;
    delete serial;
    delete process;
    delete disk;
    delete sound;

    //The boot module will destroy tsos itself, and who knows what would happen if it was destroyed
    //I mean, probably nothing, but who knows
    //delete boot;
}

Driver::Driver(void)
{
}

Driver::~Driver(void)
{
}
Module::Module(void)
{
}

Module::~Module(void)
{
    delete name;
}

BOOLEAN Module::attachdriver(Driver d) const
{

    //The driver has to be the right machine and run on that machines configuration
    if (driver.detectsystem())
    {
        driver = &d;
    }
    else
    {

        //Lets not overfill the heap
        delete d;
    }
}

//Boolean type
typedef uint8_t BOOLEAN;

//True
BOOLEAN TRUE = 1;

//False
BOOLEAN FALSE = 0;

Tsos tsos;