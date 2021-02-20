//By Tsuki Superior
#include "./gba_screen.hpp"

GBA_SCREEN_driver::GBA_SCREEN_driver(void)
{
  name = "Gameboy Advanced Screen";
  reset();
}

bool GBA_SCREEN_driver::detectsystem(void)
{
  // There is no way that this GBA driver is running on anything but a GBA, so a true is forced here
  return true;
}

void GBA_SCREEN_driver::reset(void)
{
  uint16_t *screen_control;

  // LCD screen mode register
  screen_control = (uint16_t *)0x4000010;

  // Only enable BG0, and set to mode 0. Disable sprites.
  *screen_control = 0x1000;

  // Background 0 Scroll X register
  screen_control = (uint16_t *)0x4000010;

  // Set the scroll value of SCX to 0
  *screen_control = 0;

  // Background 0 Scroll Y register
  screen_control = (uint16_t *)0x4000012;

  // Set the scroll value of SCY to 0
  *screen_control = 0;

  // Get the BG0 tile map control
  screen_control = (uint16_t *)0x4000008;

  text_cursor = 0;
  text_buffer_length = gettextbufferlength();
  text_buffer = gettextbuffer();
}

void GBA_SCREEN_driver::putchar(char c, Color bc, Color fc)
{
  text_buffer[text_cursor] = c;
}

uint16_t GBA_SCREEN_driver::gettextcursor(void)
{
  return text_cursor;
}

void GBA_SCREEN_driver::seektextcursor(uint16_t pos)
{
  text_cursor = pos;

  // Make sure it doesn't make it over that 20 tile width
  if ((text_cursor % 0x32) > 0x14)
  {
    text_cursor += 0x32 - (text_cursor % 0x32);
  }

  // Prevent the cursor from passing over that 18 tile height
  while (text_cursor >= 0x240)
  {
    text_cursor -= 0x240;
  }
}

uint16_t GBA_SCREEN_driver::getscreenwidth(void)
{
  return 30;
}

uint16_t GBA_SCREEN_driver::getscreenheight(void)
{
  return 20;
}

char *GBA_SCREEN_driver::gettextbuffer(void)
{
}

uint16_t GBA_SCREEN_driver::gettextbufferlength(void)
{
  return 0x258;
}

void GBA_SCREEN_driver::setfont(Font f)
{
  switch (mode)
  {
  case TEXT:
    return;
  case GRAPHIC:
    font = f;
  }
}
