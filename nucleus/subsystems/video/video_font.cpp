// By Tsuki Superior
#include "./video_font.hpp"

Font::Font(uint8_t *d)
{
    data = d;
}

Font::~Font(void)
{
    delete data;
}