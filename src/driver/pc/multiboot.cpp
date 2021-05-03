// By Tsuki Superior
#include <generic/nucleus_instance.hpp>
#include <pc/multiboot.hpp>

MULTIBOOT_quark::MULTIBOOT_quark(void)
{
    name = "Multiboot";
}

MULTIBOOT_quark::~MULTIBOOT_quark()
{
}

bool MULTIBOOT_quark::detectsystem(void)
{
    return true;
}

void MULTIBOOT_quark::reset(void)
{
}

void MULTIBOOT_quark::reboot(void)
{
    // 8042 reset
    uint8_t good = 0x02;
    while (good & 0x02)
    {
        good = tsos->io.in8(0x64);
    }
    tsos->io.out8(0x64, 0xfe);
    __asm__ volatile("hlt");
}

void MULTIBOOT_quark::shutdown(void)
{
    // Bochs, and older versions of QEMU(than 2.0)
    tsos->io.out16(0xB004, 0x2000);

    // Newer versions of QEMU
    tsos->io.out16(0x604, 0x2000);

    // Virtualbox
    tsos->io.out16(0x4004, 0x3400);
}
