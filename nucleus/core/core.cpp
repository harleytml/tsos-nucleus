//By Tsuki Superior
#include "./core.hpp"

Tsos::Tsos(void)
{

    // The version and related information of the OS
    version = 0.0;
    code_name = "Neutronium";
    short_code_name = "n";

    // The Init system
    video = Video();
    input = Input();
    filesystem = Filesystem();
    boot = Boot();
    serial = Serial();
    process = Process();
    disk = Disk();

    //All these define based constants are in a generated header file (see core.hpp)
    Video_driver video_drivers[VIDEO_DRIVER_COUNT] = VIDEO_DRIVERS;
    Input_driver input_drivers[INPUT_DRIVER_COUNT] = INPUT_DRIVERS;
    Filesystem_driver filesystem_drivers[FILESYSTEM_DRIVER_COUNT] = FILESYSTEM_DRIVERS;
    Boot_driver boot_drivers[BOOT_DRIVER_COUNT] = BOOT_DRIVERS;
    Serial serial_drivers[SERIAL_DRIVER_COUNT] = SERIAL_DRIVERS;
    Process_driver process_drivers[PROCESS_DRIVER_COUNT] = PROCESS_DRIVERS;
    Disk_driver disk_drivers[DISK_DRIVER_COUNT] = DISK_DRIVERS;

    // Attaching video drivers
    for (uint8_t x = 0; x < VIDEO_DRIVER_COUNT; x++)
    {
        video.attachdriver(video_drivers[x]);
    }

    // Attach input drivers
    for (uint8_t x = 0; x < INPUT_DRIVER_COUNT; x++)
    {
        input.attachdriver(input_drivers[x]);
    }

    // Attach filesystem drivers
    for (uint8_t x = 0; x < FILESYSTEM_DRIVER_COUNT; x++)
    {
        filesystem.attachdriver(filesystem_drivers[x]);
    }

    // Attach boot drivers
    for (uint8_t x = 0; x < BOOT_DRIVER_COUNT; x++)
    {
        boot.attachdriver(boot_drivers[x]);
    }

    // Attach serial drivers
    for (uint8_t x = 0; x < SERIAL_DRIVER_COUNT; x++)
    {
        serial.attachdriver(serial_drivers[x]);
    }

    // Attach process drivers
    for (uint8_t x = 0; x < PROCESS_DRIVER_COUNT; x++)
    {
        process.attachdriver(process_drivers[x]);
    }

    // Attach disk drivers
    for (uint8_t x = 0; x < DISK_DRIVER_COUNT; x++)
    {
        disk.attachdriver(disk_drivers[x]);
    }
}

Tsos::~Tsos(void)
{
    video.settextbackgroundcolor(0x00, 0xff, 0x00, 0x00);
    video.settextforegroundcolor(0xff, 0xff, 0xff, 0x00);
    video.clear();
    video.putstring("Shutting down... \n");
    video.putstring("Do not touch the power button.\n");
    process.killall();
    disk.commitall();
}

// Start the kernel

extern "C"
{
    void kernel_main(void)
    {
        tsos = Tsos();
    }
}