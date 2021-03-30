//By Tsuki Superior
#ifndef __TSOS_EGA_DRIVER__
#define __TSOS_EGA_DRIVER__

#include "video_driver.hpp"
#include "video_modes.hpp"

class EGA_driver : public Video_driver
{
public:
  EGA_driver(void);
  bool detectsystem(void) final;
  void reset(void) final;
  void drawpx(uint16_t pos_x, uint16_t pos_y, const Color &c) final;
  void putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc) final;
  uint16_t getscreenwidth(void) final;
  uint16_t getscreenheight(void) final;
  void setfont(Font f);

private:
  // The text buffer
  char *text_buffer;

  video_mode mode;

  Font font;
};

#endif
