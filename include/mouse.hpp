#ifndef TSOS_NUCLEUS_MOUSE
#define TSOS_NUCLEUS_MOUSE

#include "types.hpp"
#include "port.hpp"
#include "driver.hpp"
#include "IDT.hpp"

        class MouseEventHandler
        {
        public:
            MouseEventHandler();

            virtual void OnActivate();
            virtual void OnMouseDown(myos::common::uint8_t button);
            virtual void OnMouseUp(myos::common::uint8_t button);
            virtual void OnMouseMove(int x, int y);
        };
        
        
        class MouseDriver : public myos::hardwarecommunication::InterruptHandler, public Driver
        {
            myos::hardwarecommunication::Port8Bit dataport;
            myos::hardwarecommunication::Port8Bit commandport;
            myos::common::uint8_t buffer[3];
            myos::common::uint8_t offset;
            myos::common::uint8_t buttons;

            MouseEventHandler* handler;
        public:
            MouseDriver(myos::hardwarecommunication::InterruptManager* manager, MouseEventHandler* handler);
            ~MouseDriver();
            virtual myos::common::uint32_t HandleInterrupt(myos::common::uint32_t esp);
            virtual void Activate();
    
#endif
