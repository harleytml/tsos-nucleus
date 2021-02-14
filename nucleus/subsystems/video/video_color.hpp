//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_VIDEO_COLOR__
#define __TSOS_NUCLEUS_VIDEO_COLOR__

#include "../../core/types.hpp"

// Describes the character color for text mode video
class Color
{
public:
    //Default constructor
    Color();

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

#endif
