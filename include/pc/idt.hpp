/* By Tsuki Superior
 * PC Interrupt Quark
 *
 */

#pragma once

#include <generic/interrupt_quark.hpp>
#include <generic/types.hpp>

class IDT_quark : public Interrupt_quark {
public:
    IDT_quark(void);
    bool detectsystem(void) final;
    void reset(void) final;
    void registerinterrupt(func_ptr func, uint16_t id) final;

private:
    class IDTDescr {
    public:
        uint16_t offset_1; // offset bits 0..15
        uint16_t selector; // a code segment selector in GDT or LDT
        uint8_t zero; // unused, set to 0
        uint8_t type_attr; // type and attributes, see below
        uint16_t offset_2; // offset bits 16..31
    } __attribute__((packed));
};
