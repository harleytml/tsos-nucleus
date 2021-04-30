// By Tsuki Superior
#include <vexpress-a15/vexpress-a15_screen.hpp>

VEXPRESS_A15_SCREEN_quark::VEXPRESS_A15_SCREEN_quark(void)
{
    name = "Versatile Express A15";
    font = Font();
}

VEXPRESS_A15_SCREEN_quark::~VEXPRESS_A15_SCREEN_quark() { }

bool VEXPRESS_A15_SCREEN_quark::detectsystem(void) { return true; }

void VEXPRESS_A15_SCREEN_quark::reset(void) { }

void VEXPRESS_A15_SCREEN_quark::drawpx(uint16_t pos_x, uint16_t pos_y,
    const Color& c) { }

void VEXPRESS_A15_SCREEN_quark::putchar(uint16_t posx, uint16_t posy, char c,
    const Color& bc, const Color& fc) { }

uint16_t VEXPRESS_A15_SCREEN_quark::getscreenwidth(void) { return 0; }

uint16_t VEXPRESS_A15_SCREEN_quark::getscreenheight(void) { return 0; }

void VEXPRESS_A15_SCREEN_quark::setfont(Font f)
{
    switch (mode) {
    case TEXT:
        return;
    case GRAPHIC:
        font = f;
    }
}
