// By Tsuki Superior
#include <generic/nucleus_instance.hpp>
#include <pc/pc_speaker.hpp>

PC_SPEAKER_quark::PC_SPEAKER_quark(void)
{
    name = "PC Speaker";
}

bool PC_SPEAKER_quark::detectsystem(void)
{
    return true;
}

void PC_SPEAKER_quark::reset(void)
{
}

void PC_SPEAKER_quark::playtone(uint32_t tone)
{
    uint32_t div;
    uint8_t tmp;

    // Set the PIT to the desired frequency
    div = 1193180 / tone;
    tsos->io.out8(0x43, 0xb6);
    tsos->io.out8(0x42, (uint8_t)(div));
    tsos->io.out8(0x42, (uint8_t)(div >> 8));

    // And play the sound using the PC speaker
    tmp = tsos->io.in8(0x61);
    if (tmp != (tmp | 3))
    {
        tsos->io.out8(0x61, tmp | 3);
    }
}

void PC_SPEAKER_quark::killsound(void)
{
    uint8_t tmp = tsos->io.in8(0x61) & 0xfc;
    tsos->io.out8(0x61, tmp);
}