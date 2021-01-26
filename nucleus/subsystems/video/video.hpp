//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_VIDEO__
#define __TSOS_NUCLEUS_VIDEO__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"

extern Tsos tsos;

enum video_mode
{
  TEXT,
  GRAPHIC
};

// Describes the character color for text mode video
class Color
{
public:
  // Constructors
  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a, uint8_t i);
  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  Color(uint8_t r, uint8_t g, uint8_t b);

  // Destructor
  ~Color();

  // To copy a color
  Color(const Color &color);

  // Red
  uint8_t red;

  // Green
  uint8_t green;

  //Blue
  uint8_t blue;

  //Alpha
  uint8_t alpha;

  // Intensity part
  uint8_t intensity;
};

// The class defining fonts
class Font
{
public:
  // Constructor
  Font(uint8_t *d[][]);

  // Destructor
  ~Font(void);

  // The character width
  uint8_t width;

  // The character height
  uint8_t height;

private:
  // The actual data for the font
  uint8_t *data[][];
};

class Video_driver : public Driver
{
public:
  // Constructor
  Video_driver(void);

  //Default constructor
  ~Video_driver();

  // A very long way to describe the way to draw a character
  virtual void putchar(char c, Color bc, Color fc) = 0;

  // Get the text cursor
  virtual uint16_t gettextcursor(void) = 0;

  // Set the text cursor
  virtual void seektextcursor(uint16_t pos) = 0;

  // Get the text buffer
  virtual char *gettextbuffer(void) = 0;

  // Get the length of the text buffer
  virtual uint16_t gettextbufferlength(void) = 0;

  // Get the width of the screen
  virtual uint16_t getscreenwidth(void) = 0;

  // Get the height of the screen
  virtual uint16_t getscreenheight(void) = 0;

  // Reset the system
  virtual void reset(void) = 0;
};
// The main class controlling video
class Video : public Module
{
public:
  // Constructor
  Video(void);

  // Destructor
  ~Video(void);

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
