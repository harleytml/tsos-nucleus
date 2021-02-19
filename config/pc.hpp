#define MACHINE PERSONAL_COMPUTER
#define VIDEO_DRIVERS                                          \
    {                                                          \
        new MDA_driver(), new CGA_driver(), new EGA_driver(), new VGA_driver() \
    }
#define INPUT_DRIVERS                              \
    {                                              \
        new XT_KEYBOARD_driver(), new AT_KEYBOARD_driver() \
    }
#define DISK_DRIVERS \
    {                \
        new CD_driver()  \
    }
#define SERIAL_DRIVERS \
    {                  \
        new RS232_driver() \
    }
#define BOOT_DRIVERS   \
    {                  \
        new GRUB2_driver() \
    }
#define FILESYSTEM_DRIVERS                                                         \
    {                                                                              \
        new FAT12_driver(), new FAT16_driver(), new FAT32_driver(), new UDF_driver(), new SFS_driver() \
    }
#define SOUND_DRIVERS \
    {                 \
    }
#define PROCESS_DRIVERS \
    {                   \
        new ELF_driver()    \
    }
#define VIDEO_DRIVER_COUNT 4
#define INPUT_DRIVER_COUNT 2
#define DISK_DRIVER_COUNT 1
#define SERIAL_DRIVER_COUNT 1
#define BOOT_DRIVER_COUNT 1
#define FILESYSTEM_DRIVER_COUNT 4
#define SOUND_DRIVER_COUNT 0
#define PROCESS_DRIVER_COUNT 2

#define FONT_WIDTH 8
#define FONT_HEIGHT 8
