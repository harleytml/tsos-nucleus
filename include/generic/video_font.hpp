/* By Tsuki Superior
 * Video Font
 * 
 * This is very difficult to make multiplatform, within the current 
 * simplicity of TS/OS, because pretty much every system has
 * its own font format
 */

#pragma once

#include <generic/types.hpp>

// The class defining fonts
class Font {
public:
    //Default constructor for font
    Font(void);

    // Constructor
    Font(uint8_t* d, uint8_t char_width, uint8_t char_height);

    // Destructor
    ~Font();

    // The character width
    uint8_t width;

    // The character height
    uint8_t height;

    // The actual data for the font
    uint8_t* data;
};
