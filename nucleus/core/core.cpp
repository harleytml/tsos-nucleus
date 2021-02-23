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

#if MACHINE PERSONAL_COMPUTER

    //First attach video stuff
    video.attachdriver(VGA_driver());
    video.attachdriver(EGA_driver());
    video.attachdriver(CGA_driver());
    video.attachdriver(MDA_driver());

    //Then to input
    input.attachdriver(AT_KEYBOARD_driver());
    input.attachdriver(XT_KEYBOARD_driver());

    // Now the filesystem
    Sfilesystem.attachdriver(FAT32_driver);
    filesystem.attachdriver(FAT16_driver);
    filesystem.attachdriver(FAT12_driver);
    filesystem.attachdriver(_driver);
    hdriver(FAT32_driver);

    //Boot

#endif // Is a GBA
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