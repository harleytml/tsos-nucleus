#include "pc/pc_io.hpp"

PC_IO_driver::PC_IO_driver(void)
{
}

PC_IO_driver::~PC_IO_driver()
{
}

bool PC_IO_driver::detectsystem(void)
{
  return true;
}

void PC_IO_driver::reset(void)
{
}

// Get a uint8_t from the io ports
uint8_t PC_IO_driver::get8(uint16_t port)
{
  uint8_t ret;
  __asm__ volatile("inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port));
  return ret;
}

// Send a uint8_t through the io ports
void PC_IO_driver::put8(uint16_t port, uint8_t value)
{
  __asm__ volatile("outb %0, %1"
                   :
                   : "a"(value), "Nd"(port));
}

// Get a uint16_t from the io ports
uint16_t PC_IO_driver::get16(uint16_t port)
{
  uint16_t ret;
  __asm__ volatile("inw %1, %0"
                   : "=a"(ret)
                   : "dN"(port));
  return ret;
}

// Send a uint16_t through the io ports
void PC_IO_driver::put16(uint16_t port, uint16_t value)
{
  __asm__ volatile("outw %1, %0"
                   :
                   : "dN"(port), "a"(value));
}

// Get a uint32_t from the io ports
uint32_t PC_IO_driver::get32(uint16_t port)
{
  uint32_t ret;
  __asm__ volatile("inl %1, %0"
                   : "=a"(ret)
                   : "dN"(port));
  return ret;
}

// Send a uint32_t through the io ports
void PC_IO_driver::put32(uint16_t port, uint32_t value)
{
  __asm__ volatile("outl %1, %0"
                   :
                   : "dN"(port), "a"(value));
}