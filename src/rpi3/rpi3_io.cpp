#include <rpi3/rpi3_io.hpp>
#include <generic/nucleus_instance.hpp>

RPI3_IO_quark::RPI3_IO_quark(void)
{
  name = "Raspberry Pi 3 Input Output";
}

RPI3_IO_quark::~RPI3_IO_quark()
{
}

bool RPI3_IO_quark::detectsystem(void)
{
  return (bool)(__aarch64__);
}

void RPI3_IO_quark::reset(void)
{
}

// Get a uint8_t from the io ports
uint8_t RPI3_IO_quark::in8(uint16_t port)
{
  return *(volatile uint8_t *)(MMIO_BASE + port);
}

// Send a uint8_t through the io ports
void RPI3_IO_quark::out8(uint16_t port, uint8_t value)
{
  *(volatile uint8_t *)(MMIO_BASE + port) = value;
}

// Get a uint16_t from the io ports
uint16_t RPI3_IO_quark::in16(uint16_t port)
{
  return *(volatile uint16_t *)(MMIO_BASE + port);
}

// Send a uint16_t through the io ports
void RPI3_IO_quark::out16(uint16_t port, uint16_t value)
{
  *(volatile uint16_t *)(MMIO_BASE + port) = value;
}

// Get a uint32_t from the io ports
uint32_t RPI3_IO_quark::in32(uint16_t port)
{
  return *(volatile uint32_t *)(MMIO_BASE + port);
}

// Send a uint32_t through the io ports
void RPI3_IO_quark::out32(uint16_t port, uint32_t value)
{
  *(volatile uint32_t *)(MMIO_BASE + port) = value;
}