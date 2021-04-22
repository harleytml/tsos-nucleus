//By Tsuki Superior
#include <pc/vga.hpp>

VGA_quark::VGA_quark(void)
{
  name = "Video Graphics Array";
  font = Font();
}

bool VGA_quark::detectsystem(void)
{

  // Check to see if VGA or EGA is installed
  //Address is 0040:0087
  if (*((uint8_t *)0x487) != 0)
  {

    // WARNING: This also passes for EGA
    return true;
  }
  return false;
}

void VGA_quark::reset(void)
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

void VGA_quark::putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc)
{
  uint8_t a = 0;
  uint16_t screenwidth = getscreenwidth();
  uint16_t intendedposition = ((posy * screenwidth) + posx) * 2;
  uint16_t cx;
  uint16_t cy;
  uint8_t mask[8] = {1, 2, 4, 8, 16, 32, 64, 128};
  uint8_t *glyph = font.data + (int)c * font.width;

  switch (mode)
  {
  case TEXT:

    // Lets check if the video system has made it in a mode different than when the quark was initialized
    // We are checking the video controller 6845 port number for the color type
    switch (*((uint16_t *)0x410) & 0x30)
    {

    //Monochrome
    case 0x30:
      screen_buffer[intendedposition] = c;
      return;

    //Color
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
      a |= ((a & 0xe) != 0) << 3;

      // Put the character byte
      screen_buffer[intendedposition] = c;

      // Put the attribute byte
      screen_buffer[intendedposition + 1] = (char)a;
      return;
    }
    return;
  case GRAPHIC:

    for (cy = 0; cy < font.height; cy++)
    {
      for (cx = 0; cx < font.width; cx++)
      {
        drawpx(posx + cx, posy + cy - 12, glyph[cy] & mask[cx] ? fc : bc);
      }
    }

    return;
  default:
    return;
  }
}

void VGA_quark::drawpx(uint16_t pos_x, uint16_t pos_y, const Color &c)
{
  uint16_t color = 0;
  volatile uint8_t *location = (uint8_t *)0xa0000 + getscreenwidth() * pos_y + pos_x;

  color |= (c.blue & 0x1f) << 10;
  color |= (c.green & 0x1f) << 5;
  color |= (c.red & 0x1f);

  *location = color;
}

uint16_t VGA_quark::getscreenwidth(void)
{

  // Read the width from a BIOS field
  // Address is 0040:44a
  return *((uint16_t *)0x44a);
}

uint16_t VGA_quark::getscreenheight(void)
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

void VGA_quark::setfont(Font f)
{
  switch (mode)
  {
  case TEXT:

    // I believe you have to go into real mode to do this
    // The PC edition of TS/OS is intended for protected mode
    return;
  case GRAPHIC:
    font = f;

  default:
    return;
  }
}
