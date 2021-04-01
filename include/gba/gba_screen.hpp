/* By Tsuki Superior
 * Gameboy Advanced Screen Driver 
 *
 * The quark for the GBA's Screen
 * 
 * The GBA has a 320 by 240 sized screen, with 4 maximum layers to the screen buffer
 * None of this will not be fully used by TS/OS (As of version 0.0)
 * This version of TS/OS is focusing of console mode, which means that
 * The screen quarks will report back the charactor width of the screen
 * as its height.
 */

#ifndef __TSOS_GBA_SCREEN_QUARK__
#define __TSOS_GBA_SCREEN_QUARK__

#define MODE3 0x0003
#define BG2 0x0400

#include "generic/video_quark.hpp"
#include "generic/video_modes.hpp"

class GBA_SCREEN_quark : public Video_quark
{
public:
  GBA_SCREEN_quark(void);
  ~GBA_SCREEN_quark();
  bool detectsystem(void) final;
  void reset(void) final;
  void putchar(uint16_t posx, uint16_t posy, char c, const Color &bc, const Color &fc) final;
  void drawpx(uint16_t pos_x, uint16_t pos_y, const Color &c) final;
  uint16_t getscreenwidth(void) final;
  uint16_t getscreenheight(void) final;
  void setfont(Font f);

private:
  // The text buffer
  char *text_buffer;

  video_mode mode;

  Font font;
};

#endif
