//By Tsuki Superior
#include "cga.hpp"

CGA_driver::CGA_driver(void)
{
  name = "Color Graphics Array";
  font = Font();
}

bool CGA_driver::detectsystem(void)
{

  // Check to make sure EGA and VGA is not installed
  //Address is 0040:0087

  if (*((uint8_t *)0x487) == 0)
  {

    // Check if display is monochrome, or MDA
    //Address is 0040:0080
    if ((*((uint8_t *)0x480) & 0x30) != 0x30)
    {

      // Display is probably CGA, or a card in CGA emulation mode
      return true;
    }
  }
  return false;
}

void CGA_driver::reset(void)
{
  text_cursor = 0;
  text_buffer_length = gettextbufferlength();
  text_buffer = gettextbuffer();
}

void CGA_driver::drawpx(uint16_t pos_x, uint16_t pos_y, Color c)
{
}

void CGA_driver::putchar(char c, const Color &bc, const Color &fc)
{
  uint8_t a = 0;
  uint8_t o;
  switch (mode)
  {
  case TEXT:

    o = text_buffer[text_cursor + 2];

    /* 
    This is a early driver.
    Each attribute has 1 bit per color, plus intensity
    Basically, if a color is higher than 0, it is considered active
    Also, it compares it with its old value if the alpha is high enough
    The result is a rather messy algorithem
     */

    // Set the background intensity
    a |= 0x1 << 7;

    // Set the background red
    a |= ((bc.red >= 0x80) << 6);

    // Set the background blue
    a |= ((bc.green >= 0x80) << 5);

    // Set the background green
    a |= ((bc.blue >= 0x80) << 4);

    // Set the foreground intensity
    a |= 0x1 << 3;

    // Set the foreground red
    a |= ((fc.red >= 0x80) << 2);

    // Set the foreground green
    a |= ((fc.green >= 0x80) << 1);

    // Set the foreground blue
    a |= ((fc.blue >= 0x80) << 0);

    // Put the character byte
    text_buffer[text_cursor] = c;

    // Move that cursor forward little
    seektextcursor(gettextcursor() + 1);

    // Put the attribute byte
    text_buffer[text_cursor] = (char)a;
    return;
  case GRAPHIC:
    return;
  default:
    return;
  }
}

uint16_t CGA_driver::gettextcursor(void)
{
  return text_cursor;
}

void CGA_driver::seektextcursor(uint16_t pos)
{
  text_cursor = pos;
  while (text_cursor <= text_buffer_length)
  {
    text_cursor -= text_buffer_length;
  }
}

uint16_t CGA_driver::getscreenwidth(void)
{

  // Read the width from a BIOS field
  return *((uint16_t *)0x84a);
}

uint16_t CGA_driver::getscreenheight(void)
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

char *CGA_driver::gettextbuffer(void)
{

  // Read the offset of the current video page from the BIOS
  // address is 0040:044e
  return (char *)(*((uint16_t *)0x84e));
}

uint16_t CGA_driver::gettextbufferlength(void)
{

  // Read the length from the BIOS
  // Address is 0040:044c
  return (*((uint16_t *)0x84c));
}

void CGA_driver::setfont(Font f)
{
  switch (mode)
  {
  case TEXT:
    // You have to manipulate the hardware to change the font on CGA in text mode
    return;
  case GRAPHIC:
    font = f;
  }
}
