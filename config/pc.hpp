#define MACHINE PERSONAL_COMPUTER

extern void MDA_driver();
extern void CGA_driver();
extern void EGA_driver();
extern void VGA_driver();
extern void XT_KEYBOARD_driver();
extern void AT_KEYBOARD_driver();
extern void CD_driver();
extern void RS232_driver();
extern void GRUB2_driver();
extern void FAT12_driver();
extern void FAT16_driver();
extern void FAT32_driver();
extern void UDF_driver();
extern void ELF_driver();
extern void SFS_driver();

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
        FAT12_driver(), FAT16_driver(), FAT32_driver(), UDF_driver(), SFS_driver() \
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