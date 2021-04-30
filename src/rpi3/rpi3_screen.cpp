// By Tsuki Superior
#include <rpi3/rpi3_screen.hpp>

RPI3_SCREEN_quark::RPI3_SCREEN_quark(void)
{
    name = "Raspberry Pi 3 Screen";
    font = Font();
}

RPI3_SCREEN_quark::~RPI3_SCREEN_quark()
{
}

bool RPI3_SCREEN_quark::detectsystem(void)
{
    // There is no way that this GBA quark is running on anything but a GBA, so a
    // true is forced here
    return true;
}

void RPI3_SCREEN_quark::reset(void)
{
}

void RPI3_SCREEN_quark::drawpx(uint16_t pos_x, uint16_t pos_y, const Color &c)
{
}

void RPI3_SCREEN_quark::putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc)
{
}

uint16_t RPI3_SCREEN_quark::getscreenwidth(void)
{
    return 0;
}

uint16_t RPI3_SCREEN_quark::getscreenheight(void)
{
    return 0;
}

void RPI3_SCREEN_quark::setfont(Font f)
{
    switch (mode)
    {
    case TEXT:
        return;
    case GRAPHIC:
        font = f;
    }
}
