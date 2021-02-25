//By Tsuki Superior
#ifndef __TSOS_VGA_DRIVER__
#define __TSOS_VGA_DRIVER__

#include "video_driver.hpp"
#include "video_modes.hpp"

class VGA_driver : public Video_driver
{
public:
  VGA_driver(void);
  bool detectsystem(void);
  void reset(void);
  void putchar(char c, const Color &bc, const Color &fc);
  void drawpx(uint16_t pos_x, uint16_t pos_y, Color c);
  uint16_t gettextcursor(void);
  void seektextcursor(uint16_t pos);
  char *gettextbuffer(void);
  uint16_t gettextbufferlength(void);
  uint16_t getscreenwidth(void);
  uint16_t getscreenheight(void);
  void setfont(Font f);

private:
  // The text cursor
  uint16_t text_cursor;

  // The length of the text buffer
  uint16_t text_buffer_length;

  // The text buffer
  char *text_buffer;

  // Screen resolution width
  uint16_t screen_width;

  // Screen resolution height
  uint16_t screen_height;

  video_mode mode;

  Font font;
};

#endif
