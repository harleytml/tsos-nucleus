//By Tsuki Superior
#include "gba/gba_screen.hpp"

GBA_SCREEN_quark::GBA_SCREEN_quark(void)
{
  name = "Gameboy Advanced Screen";
  font = Font();
}

GBA_SCREEN_quark::~GBA_SCREEN_quark()
{
}

bool GBA_SCREEN_quark::detectsystem(void)
{
  // There is no way that this GBA quark is running on anything but a GBA, so a true is forced here
  return true;
}

void GBA_SCREEN_quark::reset(void)
{
  /* the display control pointer points to the gba graphics register */
  volatile uint32_t *display_control = (volatile uint32_t *)0x4000000;

  /* we set the mode to mode 3 with background 2 on */
  *display_control = MODE3 | BG2;
}

void GBA_SCREEN_quark::drawpx(uint16_t pos_x, uint16_t pos_y, const Color &c)
{
  volatile uint16_t *screen = (volatile uint16_t *)0x6000000;
  uint16_t color = 0;
  color |= (c.blue & 0x1f) << 10;
  color |= (c.green & 0x1f) << 5;
  color |= (c.red & 0x1f);
  screen[pos_y * getscreenwidth() + pos_x] = color;
}

void GBA_SCREEN_quark::putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc)
{
}

uint16_t GBA_SCREEN_quark::getscreenwidth(void)
{
  return 30;
}

uint16_t GBA_SCREEN_quark::getscreenheight(void)
{
  return 20;
}

void GBA_SCREEN_quark::setfont(Font f)
{
  switch (mode)
  {
  case TEXT:
    return;
  case GRAPHIC:
    font = f;
  }
}
