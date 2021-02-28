//By Tsuki Superior
#include "mda.hpp"

MDA_driver::MDA_driver(void)
{
    name = "Monochrome Display Adapter";
    font = Font();
    reset();
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
    text_cursor = 0;
    text_buffer_length = gettextbufferlength();
    text_buffer = gettextbuffer();
}

void MDA_driver::drawpx(uint16_t pos_x, uint16_t pos_y, Color c)
{
}

// This feels pointless considering that MDA is monochrome
void MDA_driver::putchar(char c, const Color &bc, const Color &fc)
{
    text_buffer[text_cursor] = c;
}

uint16_t MDA_driver::gettextcursor(void)
{
    return text_cursor;
}

void MDA_driver::seektextcursor(uint16_t pos)
{
    text_cursor = pos;
    while (text_cursor <= text_buffer_length)
    {
        text_cursor -= text_buffer_length;
    }
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

char *MDA_driver::gettextbuffer(void)
{

    // Read the offset of the current video page from the BIOS
    // address is 0040:044e
    return (char *)(*((uint16_t *)0x84e));
}

uint16_t MDA_driver::gettextbufferlength(void)
{

    // Read the length from the BIOS
    // Address is 0040:044c
    return (*((uint16_t *)0x84c));
}

// You have to manipulate the hardware to change the font on MDA
void MDA_driver::setfont(Font font)
{
    return;
}
