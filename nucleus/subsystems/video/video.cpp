//By Tsuki Superior
#include "video.hpp"

Video::Video(void)
{
  backgroundcolor = Color(0x00, 0x00, 0x00);
  foregroundcolor = Color(0xff, 0xff, 0xff);
  clear();
}

Video::~Video(void)
{
  delete &font;
  delete &backgroundcolor;
  delete &foregroundcolor;
}

void Video::reset(void)
{
  driver->reset();
}

void Video::putchar(char c)
{
  driver->putchar(c, backgroundcolor, foregroundcolor);
}

void Video::putstring(char *str)
{
  int x;
  char c;
  while (str[x] != 0)
  {
    c = str[x];
    switch (c)
    {
    case '\n':
      rseektextcursor(getscreenwidth());
      break;
    case '\b':
      rseektextcursor(-1);
      break;
    case '\t':
      for (int y = 0; y < 4; y++)
      {
        putchar(' ');
        rseektextcursor(1);
      }
      break;
    default:
      putchar(str[x++]);
      rseektextcursor(1);
      break;
    }
  }
}

uint16_t Video::gettextcursor(void)
{
  return driver->gettextcursor();
}

void Video::seektextcursor(uint16_t pos)
{
  while (gettextcursor() > gettextbufferlength())
  {
    scroll(1);
  }
  driver->seektextcursor(pos);
}

void Video::rseektextcursor(int16_t pos)
{
  seektextcursor(gettextcursor() + pos);
}

char *Video::gettextbuffer(void)
{
  return driver->gettextbuffer();
}

uint16_t Video::gettextbufferlength(void)
{
  return driver->gettextbufferlength();
}

uint16_t Video::getscreenwidth(void)
{
  return driver->getscreenwidth();
}

uint16_t Video::getscreenheight(void)
{
  return driver->getscreenheight();
}

void Video::setfont(Font f)
{
}

void Video::clear(void)
{
  uint32_t len = getscreenheight() * getscreenwidth();
  for (uint32_t x = 0; x < len; x++)
  {
    putchar(' ');
  }
}

void Video::scroll(uint8_t lines)
{
  int16_t len = getscreenwidth();
  rseektextcursor(len * -1);
}

void Video::settextbackgroundcolor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
  delete &backgroundcolor;
  backgroundcolor = Color(red, green, blue, alpha);
}

void Video::settextforegroundcolor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
  delete &foregroundcolor;
  foregroundcolor = Color(red, green, blue, alpha);
}

Font(uint8_t *d[][])
{
  data = d;
}

~Font(void)
{
  delete data;
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a, uint8_t i)
{
  red = r;
  green = g;
  blue = b;
  alpha = a;
  intensity = i;
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
  red = r;
  green = g;
  blue = b;
  alpha = a;
  intensity = 0xff;
}

Color::Color(uint8_t r, uint8_t g, uint8_t b)
{
  red = r;
  green = g;
  blue = b;
  alpha = 0x00;
  intensity = 0xff;
}

~Color(void)
{
}