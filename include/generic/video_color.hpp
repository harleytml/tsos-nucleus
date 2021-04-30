/* By Tsuki Superior
 * Video Color
 *
 * The color definations for TS/OS video
 *
 * This is a class to help make color more multiplatform, at the cost of speed
 *
 */

#pragma once

#include <generic/types.hpp>

// Describes the character color for text mode video
class Color
{
  public:
    // Default constructor
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

    // Blue
    uint8_t blue;
};
