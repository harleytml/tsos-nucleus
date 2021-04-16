// By Tsuki Superior
#include <generic/video_color.hpp>

Color::Color() : red(0x00),
                 green(0x00),
                 blue(0x00)
{
}

Color::Color(uint8_t r, uint8_t g, uint8_t b) : red(r),
                                                green(g),
                                                blue(b)
{
}

Color::~Color()
{
}