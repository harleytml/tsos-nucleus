#include <generic/interrupt_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

Interrupt::Interrupt(void)
{
#ifdef __PERSONAL_COMPUTER__
  IDT_quark idt_quark;

  attachquark(idt_quark);
#endif
}

Interrupt::~Interrupt()
{
}

void Interrupt::registerinterrupt(func_ptr func, uint16_t id)
{
  quark->registerinterrupt(func, id);
}