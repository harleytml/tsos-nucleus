#include <generic/interrupt_nucleon.hpp>

Interrupt::Interrupt(void)
{
}

Interrupt::~Interrupt()
{
}

void Interrupt::registerinterrupt(func_ptr func, uint16_t id)
{
  quark->registerinterrupt(func, id);
}