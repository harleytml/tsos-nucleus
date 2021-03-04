#ifndef __TSOS_NUCLEUS_MOUSE__
#define __TSOS_NUCLEUS_MOUSE__

#include "types.hpp"
#include "port.hpp"
#include "driver.hpp"
#include "idt.hpp"

class MouseEventHandler
{
public:
    MouseEventHandler();

    virtual void OnActivate();
    virtual void OnMouseDown(uint8_t button);
    virtual void OnMouseUp(uint8_t button);
    virtual void OnMouseMove(int16_t x, int16_t y);
};

class MouseDriver : public InterruptHandler, public Driver
{
    Port8Bit dataport;
    Port8Bit commandport;
    uint8_t buffer[3];
    uint8_t offset;
    uint8_t buttons;

    MouseEventHandler *handler;

public:
    MouseDriver(InterruptManager *manager, MouseEventHandler *handler);
    ~MouseDriver();
    virtual uint32_t HandleInterrupt(uint32_t esp);
    virtual void Activate();
}

#endif
