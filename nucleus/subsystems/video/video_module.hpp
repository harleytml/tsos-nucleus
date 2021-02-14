//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_VIDEO__
#define __TSOS_NUCLEUS_VIDEO__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"
#include "../../core/types.hpp"
#include "../../core/core.hpp"
#include "./video_driver.hpp"
#include "./video_color.hpp"
#include "./video_font.hpp"

enum video_mode
{
  TEXT,
  GRAPHIC
};

// The main class controlling video
class Video : public Module<Video_driver>
{
public:
  // Constructor
  Video(void);

  // Destructor
  ~Video();

  // Initialize the video system
  void reset(void);

  // Put a character
  void putchar(char c);

  // Put a string on the screen
  void putstring(char *str);

  // Get the current location of the text cursor
  uint16_t gettextcursor(void);

  // Seek the text cursor
  void seektextcursor(uint16_t pos);

  // Seek the text cursor relatively
  void rseektextcursor(int16_t pos);

  // Get a reference to the text buffer
  char *gettextbuffer(void);

  // Get the length of the text buffer
  uint16_t gettextbufferlength(void);

  // Get the width of the screen
  uint16_t getscreenwidth(void);

  // Get the current height of the screen
  uint16_t getscreenheight(void);

  // Set the font to be used in the screen
  void setfont(Font f);

  // Clear the screen
  void clear(void);

  // Scroll the screen
  void scroll(uint8_t lines);

  // Set text background color
  void settextbackgroundcolor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

  // Set text foreground color
  void settextforegroundcolor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

private:
  // Video driver
  Video_driver *driver;

  // Current font
  Font font;

  // The current text background color
  Color backgroundcolor;

  // The current text foreground color
  Color foregroundcolor;
};

#endif
