//By Tsuki Superior
#include "video_module.hpp"

Video::Video(void) : backgroundcolor(Color(0x00, 0x00, 0x00)), foregroundcolor(Color(0xff, 0xff, 0xff))
{
#ifdef __PERSONAL_COMPUTER__
  static EGA_driver ega_driver = EGA_driver();
  static VGA_driver vga_driver = VGA_driver();
  static CGA_driver cga_driver = CGA_driver();
  static MDA_driver mda_driver = MDA_driver();

  attachdriver(ega_driver);
  attachdriver(vga_driver);
  attachdriver(cga_driver);
  attachdriver(mda_driver);

#endif

#ifdef __GAMEBOY_ADVANCED__
  static GBA_SCREEN_driver gba_screen_driver = GBA_SCREEN_driver();

  attachdriver(gba_screen_driver);
#endif
}

Video::~Video()
{
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
  int x = 0;
  char c;
  while (str[x] != NULL)
  {
    c = str[x++];
    switch (c)
    {
    case '\n':

      //We will seek the text cursor to a new line
      rseektextcursor(getscreenwidth());
      break;
    case '\b':

      //The back symbol
      rseektextcursor(-1);
      break;
    case '\t':

      //The screen will render a tab as 2 spaces
      for (uint16_t y = 0; y < 2; y++)
      {
        putchar(' ');
        rseektextcursor(1);
      }
      break;

      //Just a normal character
    default:
      putchar(str[x]);
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
  for (uint32_t x = 0, len = getscreenheight() * getscreenwidth(); x < len; x++)
  {
    putchar(' ');
  }
  reset();
}

void Video::scroll(uint8_t lines)
{
  int16_t len = getscreenwidth();
  rseektextcursor(len * -1);
}

void Video::settextbackgroundcolor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
  backgroundcolor = Color(red, green, blue, alpha);
}

void Video::settextforegroundcolor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
  foregroundcolor = Color(red, green, blue, alpha);
}
