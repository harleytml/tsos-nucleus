// By Tsuki Superior
#include "./video_color.hpp"

Color::Color() : red(0x00), green(0x00), blue(0x00), alpha(0x00), intensity(0xff)
{
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a, uint8_t i) : red(r), green(g), blue(b), alpha(a), intensity(i)
{
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : red(r), green(g), blue(b), alpha(a), intensity(0xff)
{
}

Color::Color(uint8_t r, uint8_t g, uint8_t b) : red(r), green(g), blue(b), alpha(0x00), intensity(0xff)
{
}

Color::~Color()
{
}