// By Tsuki Superior
#include "video_font.hpp"

Font::Font(void)
{
  data = (uint8_t *)"";
}

Font::Font(uint8_t *d)
{
  data = d;
}

Font::~Font(void)
{
}