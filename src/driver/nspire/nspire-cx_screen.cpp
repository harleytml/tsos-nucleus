// By Tsuki Superior
#include <nspire/nspire-cx_screen.hpp>

NSPIRE_CX_SCREEN_quark::NSPIRE_CX_SCREEN_quark(void)
{
    name = "Texas Instruments Nspire CX Screen";
    font = Font();
}

NSPIRE_CX_SCREEN_quark::~NSPIRE_CX_SCREEN_quark()
{
}

bool NSPIRE_CX_SCREEN_quark::detectsystem(void)
{
    return true;
}

void NSPIRE_CX_SCREEN_quark::reset(void)
{
}

void NSPIRE_CX_SCREEN_quark::drawpx(uint16_t pos_x, uint16_t pos_y, const Color &c)
{
    volatile uint16_t *buff = nullptr;
    if ((pos_x < 320) && (pos_y < 240))
    {
        if (HARDWARE_REVISION_W)
        {
            buff[pos_x * 240 + pos_y] = rgbto565(c);
            return;
        }
        else
        {
            buff[pos_x * 320 + pos_y] = rgbto565(c);
            return;
        }
    }
}

void NSPIRE_CX_SCREEN_quark::putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc)
{
}

uint16_t NSPIRE_CX_SCREEN_quark::getscreenwidth(void)
{
    return 320;
}

uint16_t NSPIRE_CX_SCREEN_quark::getscreenheight(void)
{
    return 240;
}

void NSPIRE_CX_SCREEN_quark::setfont(Font f)
{
    switch (mode)
    {
    case TEXT:
        return;
    case GRAPHIC:
        font = f;
    }
}

uint16_t NSPIRE_CX_SCREEN_quark::rgbto565(const Color &c)
{
    if (!(c.red > 255 || c.green > 255 || c.blue > 255))
    {
        return ((c.red & 0b11111000) << 8) | ((c.green & 0b11111100) << 3) | (c.blue >> 3);
    }
    return 0;
}
