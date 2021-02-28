//By Tsuki Superior
#include "core.hpp"

Tsos::Tsos(void)
{

#ifdef __PERSONAL_COMPUTER__

    grub2_driver = GRUB2_driver();
    cd_driver = CD_driver();
    fat12_driver = FAT12_driver();
    fat16_driver = FAT16_driver();
    fat32_driver = FAT32_driver();
    sfs_driver = SFS_driver();
    udf_driver = UDF_driver();
    at_keyboard_driver = AT_KEYBOARD_driver();
    xt_keyboard_driver = XT_KEYBOARD_driver();
    elf_driver = ELF_driver();
    vga_driver = VGA_driver();
    ega_driver = EGA_driver();
    cga_driver = CGA_driver();
    mda_driver = MDA_driver();

#endif

#ifdef __GAMEBOY_ADVANCED__

    gba_boot_driver = GBA_BOOT_driver();
    gba_cartridge_driver = GBA_CARTRIDGE_driver();
    fat12_driver = FAT12_driver();
    fat16_driver = FAT16_driver();
    fat32_driver = FAT32_driver();
    sfs_driver = SFS_driver();
    udf_driver = UDF_driver();
    gba_gamepad_driver = GBA_GAMEPAD_driver();
    elf_driver = ELF_driver();
    gba_screen_driver = GBA_SCREEN_driver();

#endif

    input = Input();
    filesystem = Filesystem();
    boot = Boot();
    serial = Serial();
    process = Process();
    disk = Disk();
    sound = Sound();
    video = Video();

    // The version and related information of the OS
    version = 0.0;
    code_name = "Neutronium";
    short_code_name = "n";
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
    [[noreturn]] void kernel_main(void)
    {
        tsos = Tsos();
        tsos.video.reset();
        tsos.video.putstring("Welcome to TS/OS\n");
        tsos.video.putstring("Build Date: ");
        tsos.video.putstring(__DATE__);
        tsos.video.putstring("\n");
        tsos.boot.reboot();
    }
}