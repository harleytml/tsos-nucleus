//By Tsuki Superior
#include "core.hpp"

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

#ifdef PERSONAL_COMPUTER

    //First attach video stuff
    VGA_driver vga_driver = VGA_driver();
    EGA_driver ega_driver = EGA_driver();
    CGA_driver cga_driver = CGA_driver();
    MDA_driver mda_driver = MDA_driver();
    AT_KEYBOARD_driver at_keyboard_driver = AT_KEYBOARD_driver();
    XT_KEYBOARD_driver xt_keyboard_driver = XT_KEYBOARD_driver();
    FAT12_driver fat12_driver = FAT12_driver();
    FAT16_driver fat16_driver = FAT16_driver();
    FAT32_driver fat32_driver = FAT32_driver();
    SFS_driver sfs_driver = SFS_driver();
    UDF_driver udf_driver = UDF_driver();
    ELF_driver elf_driver = ELF_driver();
    RS232_driver rs232_driver = RS232_driver();
    CD_driver cd_driver = CD_driver();
    GRUB2_driver grub2_driver = GRUB2_driver();

    //Video first
    video.attachdriver(vga_driver);
    video.attachdriver(ega_driver);
    video.attachdriver(cga_driver);
    video.attachdriver(mda_driver);

    //Then to input
    input.attachdriver(at_keyboard_driver);
    input.attachdriver(xt_keyboard_driver);

    // Now the filesystem
    filesystem.attachdriver(fat32_driver);
    filesystem.attachdriver(fat16_driver);
    filesystem.attachdriver(fat12_driver);
    filesystem.attachdriver(sfs_driver);
    filesystem.attachdriver(udf_driver);

    //Process stuff
    process.attachdriver(elf_driver);

    //Serial stuff
    serial.attachdriver(rs232_driver);

    //No sound stuff

    //Disk stuff
    disk.attachdriver(cd_driver);

    //Boot stuff
    boot.attachdriver(grub2_driver);

#endif

#ifdef GAMEBOY_ADVANCED

    //First attach video stuff
    GBA_SCREEN_driver gba_screen_driver = GBA_SCREEN_driver();
    GBA_GAMEPAD_driver gba_gamepad_driver = GBA_GAMEPAD_driver();
    FAT12_driver fat12_driver = FAT12_driver();
    FAT16_driver fat16_driver = FAT16_driver();
    FAT32_driver fat32_driver = FAT32_driver();
    SFS_driver sfs_driver = SFS_driver();
    UDF_driver udf_driver = UDF_driver();
    ELF_driver elf_driver = ELF_driver();
    GBA_IO_PORT_driver gba_io_port_driver = GBA_IO_PORT_driver();
    GBA_CARTRIDGE_driver gba_cartridge_driver = GBA_CARTRIDGE_driver();
    GBA_BOOT_driver gba_boot_driver = GBA_BOOT_driver();

    //Video first
    video.attachdriver(gba_screen_driver);

    //Then to input
    input.attachdriver(gba_gamepad_driver);

    // Now the filesystem
    filesystem.attachdriver(fat32_driver);
    filesystem.attachdriver(fat16_driver);
    filesystem.attachdriver(fat12_driver);
    filesystem.attachdriver(sfs_driver);
    filesystem.attachdriver(udf_driver);

    //Process stuff
    process.attachdriver(elf_driver);

    //Serial stuff
    serial.attachdriver(gba_io_port_driver);

    //No sound stuff

    //Disk stuff
    disk.attachdriver(gba_cartridge_driver);

    //Boot stuff
    boot.attachdriver(gba_boot_driver);

#endif
}

Tsos::~Tsos()
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
        tsos.video.putstring("Welcome to TS/OS\n");
    }
}