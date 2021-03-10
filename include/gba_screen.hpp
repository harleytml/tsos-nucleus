//By Tsuki Superior
#ifndef __TSOS_GBA_SCREEN_DRIVER__
#define __TSOS_GBA_SCREEN_DRIVER__

#include "video_driver.hpp"
#include "video_modes.hpp"

class GBA_SCREEN_driver : public Video_driver
{
public:
  GBA_SCREEN_driver(void);
  ~GBA_SCREEN_driver();
  bool detectsystem(void) override;
  void reset(void) override;
  void putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc) override;
  void drawpx(uint16_t pos_x, uint16_t pos_y, Color c) override;
  uint16_t getscreenwidth(void) override;
  uint16_t getscreenheight(void) override;
  void setfont(Font f);

private:
  // The text buffer
  char *text_buffer;

  video_mode mode;

  Font font;
};

#endif
