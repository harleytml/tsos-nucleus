#define MACHINE GAMEBOY_ADVANCED
#define VIDEO_DRIVERS       \
    {                       \
        GBA_SCREEN_driver() \
    }
#define INPUT_DRIVERS        \
    {                        \
        GBA_GAMEPAD_driver() \
    }
#define DISK_DRIVERS           \
    {                          \
        GBA_CARTRIDGE_driver() \
    }
#define SERIAL_DRIVERS       \
    {                        \
        GBA_IO_PORT_driver() \
    }
#define BOOT_DRIVERS      \
    {                     \
        GBA_BOOT_driver() \
    }
#define FILESYSTEM_DRIVERS                                            \
    {                                                                 \
        FAT12_driver(), FAT16_driver(), FAT32_driver(), CDFS_driver() \
    }
#define SOUND_DRIVERS \
    {                 \
    }
#define PROCESS_DRIVERS             \
    {                               \
        ELF_driver()                \
    }
#define VIDEO_DRIVER_COUNT 1
#define INPUT_DRIVER_COUNT 1
#define DISK_DRIVER_COUNT 1
#define SERIAL_DRIVER_COUNT 1
#define BOOT_DRIVER_COUNT 1
#define FILESYSTEM_DRIVER_COUNT 4
#define SOUND_DRIVER_COUNT 0
