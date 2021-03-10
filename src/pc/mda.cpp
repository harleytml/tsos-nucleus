//By Tsuki Superior
#include "mda.hpp"

MDA_driver::MDA_driver(void)
{
    name = "Monochrome Display Adapter";
    font = Font();
}

bool MDA_driver::detectsystem(void)
{

    // Check to make sure EGA and VGA is not installed
    //Address is 0040:0087

    if (*((uint8_t *)0x487) == 0)
    {

        // Check if display is monochrome
        //Address is 0040:0080
        if ((*((uint8_t *)0x480) & 0x30) == 0x30)
        {

            // Display is MDA, or a card in MDA emulation mode
            return true;
        }
    }
    return false;
}

void MDA_driver::reset(void)
{
}

void MDA_driver::drawpx(uint16_t pos_x, uint16_t pos_y, Color c)
{
}

// This feels pointless considering that MDA is monochrome
void MDA_driver::putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc)
{
    uint16_t screenwidth = getscreenwidth();
    uint16_t intendedposition = (posy * screenwidth) + posx;
    text_buffer[intendedposition] = c;
}

// Also pointless, considering MDA has only one mode, but I'll read from a BIOS field anyway
uint16_t MDA_driver::getscreenwidth(void)
{

    // Read the width from a BIOS field
    // Address is 0040:44a
    return *((uint16_t *)0x84a);
}

uint16_t MDA_driver::getscreenheight(void)
{
    // The height of the screen, text mode, is always 25
    return 25;
}

// You have to manipulate the hardware to change the font on MDA
void MDA_driver::setfont(Font font)
{
    return;
}
