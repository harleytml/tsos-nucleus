//By Tsuki Superior
#ifndef __TSOS_MDA_DRIVER__
#define __TSOS_MDA_DRIVER__

#include "video_driver.hpp"
#include "video_modes.hpp"

class MDA_driver : public Video_driver
{
public:
  MDA_driver(void);
  bool detectsystem(void) override;
  void reset(void) override;
  void putchar(char c, const Color &bc, const Color &fc) override;
  void drawpx(uint16_t pos_x, uint16_t pos_y, Color c) override;
  uint16_t gettextcursor(void) override;
  void seektextcursor(uint16_t pos) override;
  char *gettextbuffer(void) override;
  uint16_t gettextbufferlength(void) override;
  uint16_t getscreenwidth(void) override;
  uint16_t getscreenheight(void) override;
  void setfont(Font f);

private:
  // The text cursor
  uint16_t text_cursor;

  // The length of the text buffer
  uint16_t text_buffer_length;

  // The text buffer
  char *text_buffer;

  video_mode mode;

  Font font;
};

#endif
