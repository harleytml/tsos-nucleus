//By Tsuki Superior
#include "video_module.hpp"
#include "nucleus_instance.hpp"

Video::Video(void) : backgroundcolor(Color(0x00, 0x00, 0x00)), foregroundcolor(Color(0xff, 0xff, 0xff))
{
  scroll = 0;

#ifdef __PERSONAL_COMPUTER__
  static EGA_driver ega_driver = EGA_driver();
  static VGA_driver vga_driver = VGA_driver();
  static CGA_driver cga_driver = CGA_driver();
  static MDA_driver mda_driver = MDA_driver();

  if (attachdriver(vga_driver) ||
      attachdriver(ega_driver) ||
      attachdriver(cga_driver) ||
      attachdriver(mda_driver))
  {
    return;
  }
#endif

#ifdef __GAMEBOY_ADVANCED__
  static GBA_SCREEN_driver gba_screen_driver = GBA_SCREEN_driver();

  attachdriver(gba_screen_driver);
#endif
}

Video::~Video()
{
}

void Video::reset(void) const
{
  driver->reset();
}

void Video::putchar(uint16_t posx, uint16_t posy, char c) const
{
  driver->putchar(posx, posy, c, backgroundcolor, foregroundcolor);
}

void Video::drawpx(uint16_t posx, uint16_t posy) const
{
  driver->drawpx(posx, posy, foregroundcolor);
}

void Video::putstring(uint16_t posx, uint16_t posy, const char *str) const
{
  uint16_t pos = 0;
  uint16_t x = posx;
  uint16_t y = posy;
  while (str[pos] != NULL)
  {
    char c = str[pos];
    switch (c)
    {
    case '\n':
      y++;
      break;
    case '\b':
      x--;
      break;

      //Just a normal character
    default:
      putchar(x, y, str[pos]);
      x++;
      break;
    }
    pos++;
  }
}

uint16_t Video::getscreenwidth(void) const
{
  return driver->getscreenwidth();
}

uint16_t Video::getscreenheight(void) const
{
  return driver->getscreenheight();
}

void Video::setfont(Font f)
{
}

void Video::clear(void) const
{
  for (uint16_t x = 0, lenx = getscreenwidth(); x < lenx; x++)
  {
    for (uint16_t y = 0, leny = getscreenheight(); y < leny; y++)
    {
      putchar(x, y, ' ');
    }
  }
  reset();
}

void Video::settextbackgroundcolor(uint8_t red, uint8_t green, uint8_t blue)
{
  backgroundcolor = Color(red, green, blue);
}

void Video::settextforegroundcolor(uint8_t red, uint8_t green, uint8_t blue)
{
  foregroundcolor = Color(red, green, blue);
}
