//By Tsuki Superior
#include <canon-a1100/canon-a1100_screen.hpp>

CANON_A1100_SCREEN_quark::CANON_A1100_SCREEN_quark(void)
{
  name = "Canon Powershot A1100 IS Screen";
  font = Font();
}

CANON_A1100_SCREEN_quark::~CANON_A1100_SCREEN_quark()
{
}

bool CANON_A1100_SCREEN_quark::detectsystem(void)
{
  return true;
}

void CANON_A1100_SCREEN_quark::reset(void)
{
  screen_buffer = (char *)(*(uint32_t *)0x6adc);
}

void CANON_A1100_SCREEN_quark::drawpx(uint16_t pos_x, uint16_t pos_y, const Color &c)
{
}

void CANON_A1100_SCREEN_quark::putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc)
{
}

uint16_t CANON_A1100_SCREEN_quark::getscreenwidth(void)
{
  return 0;
}

uint16_t CANON_A1100_SCREEN_quark::getscreenheight(void)
{
  return 0;
}

void CANON_A1100_SCREEN_quark::setfont(Font f)
{
  switch (mode)
  {
  case TEXT:
    return;
  case GRAPHIC:
    font = f;
  }
}
