//By Tsuki Superior
#include "psx_screen.hpp"

PSX_SCREEN_driver::PSX_SCREEN_driver(void)
{
  name = "Playstation X Screen";
  font = Font();
}

PSX_SCREEN_driver::~PSX_SCREEN_driver()
{
}

bool PSX_SCREEN_driver::detectsystem(void)
{
  // There is no way that this GBA driver is running on anything but a GBA, so a true is forced here
  return true;
}

void PSX_SCREEN_driver::reset(void)
{
}

void PSX_SCREEN_driver::drawpx(uint16_t pos_x, uint16_t pos_y, Color c)
{
}

void PSX_SCREEN_driver::putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc)
{
}

uint16_t PSX_SCREEN_driver::getscreenwidth(void)
{
  return 0;
}

uint16_t PSX_SCREEN_driver::getscreenheight(void)
{
  return 0;
}

void PSX_SCREEN_driver::setfont(Font f)
{
  switch (mode)
  {
  case TEXT:
    return;
  case GRAPHIC:
    font = f;
  }
}
