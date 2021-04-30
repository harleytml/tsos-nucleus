// By Tsuki Superior

#include <generic/boot_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

Boot::Boot(void)
{
#ifdef __PERSONAL_COMPUTER__

    static MULTIBOOT_quark multiboot_quark;

    attachquark(multiboot_quark);

#endif

#ifdef __RASPBERRY_PI_3__

    static RPI3_BOOT_quark rpi3_boot_quark;

    attachquark(rpi3_boot_quark);

#endif

#ifdef __NSPIRE__

    static NSPIRE_CM_BOOT_quark nspire_cm_boot_quark;
    static NSPIRE_CX_BOOT_quark nspire_cx_boot_quark;

    if (attachquark(nspire_cm_boot_quark) || attachquark(nspire_cx_boot_quark)) {
        return;
    }

#endif

#ifdef __CANON_A1100__
    static CANON_A1100_BOOT_quark canon_a1100_boot_quark;

    attachquark(canon_a1100_boot_quark);
#endif

#ifdef __VEXPRESS_A15__

    static VEXPRESS_A15_BOOT_quark vexpress_a15_boot_quark;

    attachquark(vexpress_a15_boot_quark);

#endif
}

Boot::~Boot() { }

void Boot::reboot(void) const { quark->reboot(); }

void Boot::shutdown(void) const
{
    tsos->video.settextbackgroundcolor(0xff, 0x00, 0x00);
    tsos->video.settextforegroundcolor(0xff, 0xff, 0xff);
    tsos->video.reset();
    tsos->video.clear();
    tsos->video.putstring(0, tsos->video.scroll++, "Shutting down... \n");
    tsos->video.putstring(0, tsos->video.scroll++,
        "Do not touch the power button.\n");
    tsos->process.killall();
    tsos->disk.commitall();
    tsos->video.putstring(0, tsos->video.scroll++,
        "You may now touch the power button.\n");

    // Destroy tsos, to trigger the kernel destruction
    quark->shutdown();
}

void Boot::fission(const char* errormsg) const
{
    tsos->video.settextbackgroundcolor(0xff, 0x00, 0x00);
    tsos->video.reset();
    tsos->video.clear();
    tsos->video.putstring(0, tsos->video.scroll++, "NUCLEUS FISSION!");
    tsos->video.putstring(0, tsos->video.scroll++, errormsg);
    tsos->video.putstring(0, tsos->video.scroll++, "PLEASE REBOOT");
}