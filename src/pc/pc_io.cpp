#include "pc/pc_io.hpp"
#include "generic/nucleus_instance.hpp"

PC_IO_quark::PC_IO_quark(void)
{
  name = "Personal Computer Input Output";
}

PC_IO_quark::~PC_IO_quark()
{
}

bool PC_IO_quark::detectsystem(void)
{

  return (bool)(__pentiumpro__);
}

void PC_IO_quark::reset(void)
{
}

// Get a uint8_t from the io ports
uint8_t PC_IO_quark::get8(uint16_t port)
{
  uint8_t ret;
  __asm__ volatile("inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port));
  return ret;
}

// Send a uint8_t through the io ports
void PC_IO_quark::put8(uint16_t port, uint8_t value)
{
  __asm__ volatile("outb %0, %1"
                   :
                   : "a"(value), "Nd"(port));
}

// Get a uint16_t from the io ports
uint16_t PC_IO_quark::get16(uint16_t port)
{
  uint16_t ret;
  __asm__ volatile("inw %1, %0"
                   : "=a"(ret)
                   : "dN"(port));
  return ret;
}

// Send a uint16_t through the io ports
void PC_IO_quark::put16(uint16_t port, uint16_t value)
{
  __asm__ volatile("outw %1, %0"
                   :
                   : "dN"(port), "a"(value));
}

// Get a uint32_t from the io ports
uint32_t PC_IO_quark::get32(uint16_t port)
{
  uint32_t ret;
  __asm__ volatile("inl %1, %0"
                   : "=a"(ret)
                   : "dN"(port));
  return ret;
}

// Send a uint32_t through the io ports
void PC_IO_quark::put32(uint16_t port, uint32_t value)
{
  __asm__ volatile("outl %1, %0"
                   :
                   : "dN"(port), "a"(value));
}