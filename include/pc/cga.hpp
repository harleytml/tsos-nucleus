// By Tsuki Superior
#pragma once

#include <generic/video_modes.hpp>
#include <generic/video_quark.hpp>

class CGA_quark : public Video_quark
{
  public:
    CGA_quark(void);
    bool detectsystem(void) final;
    void reset(void) final;
    void drawpx(uint16_t pos_x, uint16_t pos_y, const Color &c) final;
    void putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc) final;
    uint16_t getscreenwidth(void) final;
    uint16_t getscreenheight(void) final;
    void setfont(Font f);

  private:
    // The text buffer
    char *screen_buffer;

    video_mode mode;

    Font font;
};
