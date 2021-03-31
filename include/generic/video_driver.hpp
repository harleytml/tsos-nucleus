/* By Tsuki Superior
 * Abstract Video Driver
 * 
 */

#ifndef __TSOS_NUCLEUS_VIDEO_DRIVER__
#define __TSOS_NUCLEUS_VIDEO_DRIVER__

#include "generic/driver.hpp"
#include "generic/types.hpp"
#include "generic/video_font.hpp"
#include "generic/video_color.hpp"

class Video_driver : public Driver
{
public:
  // Constructor
  Video_driver(void);

  //Default constructor
  ~Video_driver();

  // A very long way to describe the way to draw a character
  virtual void putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc) = 0;

  // Draw pixel
  virtual void drawpx(uint16_t pos_x, uint16_t pos_y, const Color &c) = 0;

  // Get the width of the screen
  virtual uint16_t getscreenwidth(void) = 0;

  // Get the height of the screen
  virtual uint16_t getscreenheight(void) = 0;
};

#endif