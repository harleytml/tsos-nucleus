//By Tsuki Superior
#include "gba_screen.hpp"

GBA_SCREEN_driver::GBA_SCREEN_driver(void)
{
  name = "Gameboy Advanced Screen";
  font = Font();
}

GBA_SCREEN_driver::~GBA_SCREEN_driver()
{
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
}

void GBA_SCREEN_driver::drawpx(uint16_t pos_x, uint16_t pos_y, Color c)
{
}

void GBA_SCREEN_driver::putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc)
{
}

uint16_t GBA_SCREEN_driver::getscreenwidth(void)
{
  return 30;
}

uint16_t GBA_SCREEN_driver::getscreenheight(void)
{
  return 20;
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
