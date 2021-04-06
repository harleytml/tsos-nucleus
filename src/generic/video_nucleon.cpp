//By Tsuki Superior
#include <generic/video_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

Video::Video(void) : backgroundcolor(Color(0x00, 0x00, 0x00)), foregroundcolor(Color(0xff, 0xff, 0xff))
{
  scroll = 0;

#ifdef __PERSONAL_COMPUTER__
  static EGA_quark ega_quark = EGA_quark();
  static VGA_quark vga_quark = VGA_quark();
  static CGA_quark cga_quark = CGA_quark();
  static MDA_quark mda_quark = MDA_quark();

  if (attachquark(vga_quark) ||
      attachquark(ega_quark) ||
      attachquark(cga_quark) ||
      attachquark(mda_quark))
  {
    return;
  }
#endif

#ifdef __RASPBERRY_PI_3__
  static RPI3_SCREEN_quark rpi3_screen_quark = RPI3_SCREEN_quark();

  attachquark(rpi3_screen_quark);
#endif
}

Video::~Video()
{
}

void Video::reset(void)
{
  quark->reset();
  scroll = 0;
}

void Video::putchar(uint16_t posx, uint16_t posy, char c) const
{
  quark->putchar(posx, posy, c, backgroundcolor, foregroundcolor);
}

void Video::drawpx(uint16_t posx, uint16_t posy) const
{
  quark->drawpx(posx, posy, foregroundcolor);
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
  return quark->getscreenwidth();
}

uint16_t Video::getscreenheight(void) const
{
  return quark->getscreenheight();
}

void Video::setfont(Font &f)
{
  font = f;
}

void Video::clear(void)
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
