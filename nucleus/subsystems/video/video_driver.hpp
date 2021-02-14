//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_VIDEO_DRIVER__
#define __TSOS_NUCLEUS_VIDEO_DRIVER__

#include "../../core/driver.hpp"
#include "../../core/types.hpp"

class Video_driver : public Driver
{
public:
    // Constructor
    Video_driver(void);

    //Default constructor
    ~Video_driver();

    // A very long way to describe the way to draw a character
    virtual void putchar(char c, Color bc, Color fc) = 0;

    // Draw pixel
    virtual void drawpx(uint16_t pos_x, uint16_t pos_y, Color c) = 0;

    // Get the text cursor
    virtual uint16_t gettextcursor(void) = 0;

    // Set the text cursor
    virtual void seektextcursor(uint16_t pos) = 0;

    // Get the text buffer
    virtual char *gettextbuffer(void) = 0;

    // Get the length of the text buffer
    virtual uint16_t gettextbufferlength(void) = 0;

    // Get the width of the screen
    virtual uint16_t getscreenwidth(void) = 0;

    // Get the height of the screen
    virtual uint16_t getscreenheight(void) = 0;

    // Reset the system
    virtual void reset(void) = 0;
};

#endif