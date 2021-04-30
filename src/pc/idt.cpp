#include <pc/idt.hpp>

IDT_quark::IDT_quark(void) { name = "Interrupt Descriptor Table"; }

bool IDT_quark::detectsystem(void) { return true; }

void IDT_quark::reset(void) { }

void IDT_quark::registerinterrupt(func_ptr func, uint16_t id) { }
