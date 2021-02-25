//By Tsuki Superior
#include "ega.hpp"

EGA_driver::EGA_driver(void)
{
  name = "Enhanced Graphics Adapter";
  reset();
}

bool EGA_driver::detectsystem(void)
{
  // Check to see if VGA or EGA is installed
  // WARNING: This also passes for VGA

  return *((uint8_t *)0x400087) != 0;
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

void EGA_driver::putchar(char c, Color bc, Color fc)
{
  switch (mode)
  {
  case TEXT:

    // Lets check if the video system has made it in a mode different than when the driver was initialized
    // We are checking the video controller 6845 port for the color type
    switch (*((uint16_t *)0x400463))
    {

    // Monochrome
    case 0x3b4:
      text_buffer[text_cursor] = c;
      return;

    // Color
    case 0x3d4:
      uint8_t a = 0;
      uint8_t o = text_buffer[text_cursor + 2];

      /* This is a early driver
        Each attribute has 1 bit per color, plus intensity
        Basically, if a color is higher than 0, it is considered active
        Also, it ORs it with its old value if the alpha is high enough
        The result is a rather messy algorithem
        But it uses bit logic, so it hopefully will be fast */

      // Set the background intensity
      a |= ((bc.intensity >= 0x80) << 7) | ((o & 0x80) & ((bc.alpha >= 0x80) << 7));

      // Set the background red
      a |= ((bc.red >= 0x80) << 6) | ((o & 0x40) & ((bc.alpha >= 0x80) << 6));

      // Set the background blue
      a |= ((bc.blue >= 0x80) << 5) | ((o & 0x20) & ((bc.alpha >= 0x80) << 5));

      // Set the background green
      a |= ((bc.green >= 0x80) << 4) | ((o & 0x10) & ((bc.alpha >= 0x80) << 4));

      // Set the foreground intensity
      a |= ((fc.intensity >= 0x80) << 3) | ((o & 0x8) & ((bc.alpha >= 0x80) << 3));

      // Set the foreground red
      a |= ((fc.red >= 0x80) << 2) | ((o & 0x4) & ((bc.alpha >= 0x80) << 2));

      // Set the foreground green
      a |= ((fc.green >= 0x80) << 1) | ((o & 0x2) & ((bc.alpha >= 0x80) << 1));

      // Set the foreground blue
      a |= ((fc.blue >= 0x80) << 0) | ((o & 0x1) & ((bc.alpha >= 0x80) << 0));

      // Put the character byte
      text_buffer[text_cursor] = c;

      // Move that cursor forward a little
      seektextcursor(gettextcursor() + 1);

      // Put the attribute byte
      text_buffer[text_cursor] = (char)a;
      return;
    }
  case GRAPHIC:
    return;

  default:
    return;
  }
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

uint16_t EGA_driver::getscreenwidth(void)
{

  // Read the width from a BIOS field
  return *((uint16_t *)0x40044a);
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
  }
}

char *EGA_driver::gettextbuffer(void)
{

  // Read the offset of the current video page from the BIOS
  return (char *)(*((uint16_t *)0x40044e));
}

uint16_t EGA_driver::gettextbufferlength(void)
{
  // Read the length from the BIOS
  return (*((uint16_t *)0x40044c));
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
