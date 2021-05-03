// By Tsuki Superior
#include <pc/cga.hpp>

CGA_quark::CGA_quark(void)
{
    name = "Color Graphics Array";
    font = Font();
}

bool CGA_quark::detectsystem(void)
{

    // Check to make sure EGA and VGA is not installed
    // Address is 0040:0087

    if (*((uint8_t *)0x487) == 0)
    {

        // Check if display is monochrome, or MDA
        // Address is 0040:0080
        if ((*((uint8_t *)0x480) & 0x30) != 0x30)
        {

            // Display is probably CGA, or a card in CGA emulation mode
            return true;
        }
    }
    return false;
}

void CGA_quark::reset(void)
{
    switch (*((uint16_t *)0x410) & 0x30)
    {
    case 0x20:
        screen_buffer = (char *)(*((uint16_t *)0x44e) + 0xb8000);
        return;
    default:
        screen_buffer = (char *)0xb0000;
        return;
    }
}

void CGA_quark::drawpx(uint16_t pos_x, uint16_t pos_y, const Color &c)
{
}

void CGA_quark::putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc)
{
    uint8_t a = 0;
    uint16_t screenwidth = getscreenwidth();
    uint16_t intendedposition = (posy * screenwidth) + posx;
    switch (mode)
    {
    case TEXT:

        // Lets check if the video system has made it in a mode different than when
        // the quark was initialized We are checking the video controller 6845 port
        // number for the color type
        switch (*((uint16_t *)0x410) & 0x30)
        {

        // Monochrome
        case 0x30:
            screen_buffer[intendedposition] = c;
            return;

        // Color
        case 0x20:
            /*
      This is a early quark
      Each attribute has 1 bit per color, plus intensity
      Basically, if a color is higher than 0x80, it is considered active
      The result is a rather messy algorithem
      But it uses bit logic, so it hopefully will be fast
      */

            // Set the background red
            a |= ((bc.red >= 0x80) << 6);

            // Set the background blue
            a |= ((bc.green >= 0x80) << 5);

            // Set the background green
            a |= ((bc.blue >= 0x80) << 4);

            // Set the background intensity
            a |= ((a & 0xE0) != 0) << 7;

            // Set the foreground red
            a |= ((fc.red >= 0x80) << 2);

            // Set the foreground green
            a |= ((fc.green >= 0x80) << 1);

            // Set the foreground blue
            a |= ((fc.blue >= 0x80) << 0);

            // Set the foreground intensity
            a |= ((a & 0xE) != 0) << 3;

            // Put the character byte
            screen_buffer[intendedposition] = c;

            // Put the attribute byte
            screen_buffer[intendedposition + 1] = (char)a;
            return;
        }
        return;
    case GRAPHIC:

        // Doesn't work right now
        /*
    //Lets draw a glyph
    uint16_t cx, cy;
    uint16_t mask[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    uint8_t *glyph = font.data + (uint8_t)c * 16;
    uint8_t fgcolor;
    uint8_t bgcolor;
    for (cy = 0; cy < 16; cy++)
    {
      for (cx = 0; cx < 8; cx++)
      {
        drawpx((glyph[cy] & mask[cx]) ? fgcolor : bgcolor, x + cx, y + cy - 12);
      }
    }
    */
        return;
    default:
        return;
    }
}

uint16_t CGA_quark::getscreenwidth(void)
{

    // Read the width from a BIOS field
    // Address is 0040:44a
    return *((uint16_t *)0x44a);
}

uint16_t CGA_quark::getscreenheight(void)
{
    switch (mode)
    {
    case TEXT:

        // The height of text modes is always 25
        return 25;
    case GRAPHIC:
        return 0;
    default:
        return 0;
    }
}

void CGA_quark::setfont(Font f)
{
    switch (mode)
    {
    case TEXT:
        // You have to manipulate the hardware to change the font on CGA in text
        // mode
        return;
    case GRAPHIC:
        font = f;
    }
}
