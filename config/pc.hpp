#define MACHINE PERSONAL_COMPUTER
#define VIDEO_DRIVERS                                          \
    {                                                          \
        MDA_driver(), CGA_driver(), EGA_driver(), VGA_driver() \
    }
#define INPUT_DRIVERS                              \
    {                                              \
        XT_KEYBOARD_driver(), AT_KEYBOARD_driver() \
    }
#define DISK_DRIVERS \
    {                \
        CD_driver()  \
    }
#define SERIAL_DRIVERS \
    {                  \
        RS232_driver() \
    }
#define BOOT_DRIVERS   \
    {                  \
        GRUB2_driver() \
    }
#define FILESYSTEM_DRIVERS                                            \
    {                                                                 \
        FAT12_driver(), FAT16_driver(), FAT32_driver(), CDFS_driver() \
    }
#define SOUND_DRIVERS \
    {                 \
    }
#define PROCESS_DRIVERS \
    {                   \
        ELF_driver()    \
    }
#define VIDEO_DRIVER_COUNT 4
#define INPUT_DRIVER_COUNT 2
#define DISK_DRIVER_COUNT 1
#define SERIAL_DRIVER_COUNT 1
#define BOOT_DRIVER_COUNT 1
#define FILESYSTEM_DRIVER_COUNT 4
#define SOUND_DRIVER_COUNT 0
#define PROCESS_DRIVER_COUNT 2