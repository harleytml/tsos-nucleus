// By Tsuki Superior
#include <pc/mda.hpp>

MDA_quark::MDA_quark(void)
{
    name = "Monochrome Display Adapter";
    font = Font();
}

bool MDA_quark::detectsystem(void)
{

    // Check to make sure EGA and VGA is not installed
    // Address is 0040:0087

    if (*((uint8_t*)0x487) == 0) {

        // Check if display is monochrome
        // Address is 0040:0080
        if ((*((uint8_t*)0x480) & 0x30) == 0x30) {

            // Display is MDA, or a card in MDA emulation mode
            return true;
        }
    }
    return false;
}

void MDA_quark::reset(void) { screen_buffer = (char*)0xb0000; }

void MDA_quark::drawpx(uint16_t pos_x, uint16_t pos_y, const Color& c)
{
    // Well the MDA is simply not capable of drawing pixels...
}

// This feels pointless considering that MDA is monochrome
void MDA_quark::putchar(uint16_t posx, uint16_t posy, char c, const Color& bc,
    const Color& fc)
{
    uint16_t screenwidth = getscreenwidth();
    uint16_t intendedposition = (posy * screenwidth) + posx;
    screen_buffer[intendedposition] = c;
}

// Also pointless, considering MDA has only one mode, but I'll read from a BIOS
// field anyway
uint16_t MDA_quark::getscreenwidth(void)
{

    // Read the width from a BIOS field
    return *((uint16_t*)0x44a);
}

uint16_t MDA_quark::getscreenheight(void)
{
    // The height of the screen, text mode, is always 25
    return 25;
}

// You have to manipulate the hardware to change the font on MDA
void MDA_quark::setfont(Font font) { return; }
