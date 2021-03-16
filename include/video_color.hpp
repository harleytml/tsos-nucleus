//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_VIDEO_COLOR__
#define __TSOS_NUCLEUS_VIDEO_COLOR__

#include "types.hpp"

// Describes the character color for text mode video
class Color
{
public:
  //Default constructor
  Color();

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
};

#endif
