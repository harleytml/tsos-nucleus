//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_VIDEO_DRIVER__
#define __TSOS_NUCLEUS_VIDEO_DRIVER__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"
#include "../../core/types.hpp"
#include "../../core/core.hpp"

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