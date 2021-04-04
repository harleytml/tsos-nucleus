//By Tsuki Superior
#include "nspire/nspire-cx_screen.hpp"

NSPIRE_CX_SCREEN_quark::NSPIRE_CX_SCREEN_quark(void)
{
  name = "Texas Instruments Nspire CX Screen";
  font = Font();
}

NSPIRE_CX_SCREEN_quark::~NSPIRE_CX_SCREEN_quark()
{
}

bool NSPIRE_CX_SCREEN_quark::detectsystem(void)
{
  return true;
}

void NSPIRE_CX_SCREEN_quark::reset(void)
{
}

void NSPIRE_CX_SCREEN_quark::drawpx(uint16_t pos_x, uint16_t pos_y, const Color &c)
{
}

void NSPIRE_CX_SCREEN_quark::putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc)
{
}

uint16_t NSPIRE_CX_SCREEN_quark::getscreenwidth(void)
{
  return 0;
}

uint16_t NSPIRE_CX_SCREEN_quark::getscreenheight(void)
{
  return 0;
}

void NSPIRE_CX_SCREEN_quark::setfont(Font f)
{
  switch (mode)
  {
  case TEXT:
    return;
  case GRAPHIC:
    font = f;
  }
}
