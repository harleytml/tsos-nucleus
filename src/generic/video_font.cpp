// By Tsuki Superior
#include <generic/video_font.hpp>

Font::Font(void)
{
    data = (uint8_t *)nullptr;
}

Font::Font(uint8_t *d, uint8_t char_width, uint8_t char_height)
{
    data = d;
    width = char_width;
    height = char_height;
}

Font::~Font(void)
{
}