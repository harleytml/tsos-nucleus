//By Tsuki Superior
#include "rpi3_screen.hpp"

RPI3_SCREEN_driver::RPI3_SCREEN_driver(void)
{
  name = "Raspberry Pi 3 Screen";
  font = Font();
}

RPI3_SCREEN_driver::~RPI3_SCREEN_driver()
{
}

bool RPI3_SCREEN_driver::detectsystem(void)
{
  // There is no way that this GBA driver is running on anything but a GBA, so a true is forced here
  return true;
}

void RPI3_SCREEN_driver::reset(void)
{
}

void RPI3_SCREEN_driver::drawpx(uint16_t pos_x, uint16_t pos_y, const Color &c)
{
}

void RPI3_SCREEN_driver::putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc)
{
}

uint16_t RPI3_SCREEN_driver::getscreenwidth(void)
{
  return 0;
}

uint16_t RPI3_SCREEN_driver::getscreenheight(void)
{
  return 0;
}

void RPI3_SCREEN_driver::setfont(Font f)
{
  switch (mode)
  {
  case TEXT:
    return;
  case GRAPHIC:
    font = f;
  }
}
