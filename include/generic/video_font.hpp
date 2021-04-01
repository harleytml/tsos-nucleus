/* By Tsuki Superior
 * Video Font
 * 
 * This is very difficult to make multiplatform, within the current 
 * simplicity of TS/OS, because pretty much every system has
 * its own font format
 */

#ifndef __TSOS_NUCLEUS_VIDEO_FONT__
#define __TSOS_NUCLEUS_VIDEO_FONT__

#include "generic/types.hpp"

// The class defining fonts
class Font
{
public:
  //Default constructor for font
  Font(void);

  // Constructor
  Font(uint8_t *d);

  // Destructor
  ~Font();

  // The character width
  uint8_t width;

  // The character height
  uint8_t height;

  // The actual data for the font
  uint8_t *data;
};

#endif