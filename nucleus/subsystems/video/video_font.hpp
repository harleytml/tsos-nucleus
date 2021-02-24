//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_VIDEO_FONT__
#define __TSOS_NUCLEUS_VIDEO_FONT__

#include "../../core/types.hpp"

// The class defining fonts
class Font
{
public:
    // Constructor
    Font(uint8_t *d[]);

    // Destructor
    ~Font();

    // The character width
    uint8_t width;

    // The character height
    uint8_t height;

    // The actual data for the font
    uint8_t *data[FONT_WIDTH * FONT_HEIGHT];
};

#endif