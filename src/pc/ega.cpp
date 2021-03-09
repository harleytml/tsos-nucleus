//By Tsuki Superior
#include "ega.hpp"

EGA_driver::EGA_driver(void)
{
  name = "Enhanced Graphics Adapter";
  font = Font();
}

bool EGA_driver::detectsystem(void)
{
  // Check to see if VGA or EGA is installed
  // WARNING: This also passes for VGA
  // Address is 0040:0087

  return *((uint8_t *)0x487) != 0;
}

void EGA_driver::reset(void)
{
  text_cursor = 0;
  text_buffer_length = gettextbufferlength();
  text_buffer = gettextbuffer();
}

void EGA_driver::drawpx(uint16_t pos_x, uint16_t pos_y, Color c)
{
}

void EGA_driver::putchar(char c, const Color &bc, const Color &fc)
{
  uint8_t a = 0;
  switch (mode)
  {
  case TEXT:

    // Lets check if the video system has made it in a mode different than when the driver was initialized
    // We are checking the video controller 6845 port number for the color type
    // Address is 0040:0463
    switch (*((uint16_t *)0x44e))
    {

    //Monochrome
    case 0xb0000:
      text_buffer[text_cursor] = c;
      return;

    //Color
    default:
      /* 
      This is a early driver
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
      a |= ((a & 0xe0) != 0) << 7;

      // Set the foreground red
      a |= ((fc.red >= 0x80) << 2);

      // Set the foreground green
      a |= ((fc.green >= 0x80) << 1);

      // Set the foreground blue
      a |= ((fc.blue >= 0x80) << 0);

      // Set the foreground intensity
      a |= ((a & 0xe) != 0) << 3;

      // Put the character byte
      text_buffer[text_cursor] = c;

      // Move that cursor forward a little
      seektextcursor(gettextcursor() + 1);

      // Put the attribute byte
      text_buffer[text_cursor] = (char)a;
      return;
    }
    return;
  case GRAPHIC:

    //Doesn't work right now
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

char *EGA_driver::gettextbuffer(void)
{

  // Read the offset of the current video page from the BIOS
  // address is 0040:044e
  return (char *)(*((uint16_t *)0x84e));
}

uint16_t EGA_driver::gettextcursor(void)
{
  return text_cursor;
}

void EGA_driver::seektextcursor(uint16_t pos)
{
  text_cursor = pos;
  while (text_cursor <= text_buffer_length)
  {
    text_cursor -= text_buffer_length;
  }
}

uint16_t EGA_driver::gettextbufferlength(void)
{
  // Read the length from the BIOS
  // Address is 0040:044c
  return (*((uint16_t *)0x84c));
}

uint16_t EGA_driver::getscreenwidth(void)
{

  // Read the width from a BIOS field
  // Address is 0040:44a
  // return *((uint8_t *)0x84a);
  return 80;
}

uint16_t EGA_driver::getscreenheight(void)
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

void EGA_driver::setfont(Font f)
{
  switch (mode)
  {
  case TEXT:

    // I believe you have to go into real mode to do this
    return;
  case GRAPHIC:
    font = f;
  }
}
