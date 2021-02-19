#define MACHINE GAMEBOY_ADVANCED
#define VIDEO_DRIVERS       \
    {                       \
        new GBA_SCREEN_driver() \
    }
#define INPUT_DRIVERS        \
    {                        \
        new GBA_GAMEPAD_driver() \
    }
#define DISK_DRIVERS           \
    {                          \
        new GBA_CARTRIDGE_driver() \
    }
#define SERIAL_DRIVERS       \
    {                        \
        new GBA_IO_PORT_driver() \
    }
#define BOOT_DRIVERS      \
    {                     \
        new GBA_BOOT_driver() \
    }
#define FILESYSTEM_DRIVERS                                            \
    {                                                                 \
        new FAT12_driver(), new FAT16_driver(), new FAT32_driver(), new CDFS_driver() \
    }
#define SOUND_DRIVERS \
    {                 \
    }
#define PROCESS_DRIVERS \
    {                   \
        new ELF_driver()    \
    }
#define VIDEO_DRIVER_COUNT 1
#define INPUT_DRIVER_COUNT 1
#define DISK_DRIVER_COUNT 1
#define SERIAL_DRIVER_COUNT 1
#define BOOT_DRIVER_COUNT 1
#define FILESYSTEM_DRIVER_COUNT 4
#define SOUND_DRIVER_COUNT 0

#define FONT_WIDTH 8
#define FONT_HEIGHT 8
