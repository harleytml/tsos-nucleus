#include <generic/nucleus_instance.hpp>
#include <vexpress-a15/vexpress-a15_io.hpp>

VEXPRESS_A15_IO_quark::VEXPRESS_A15_IO_quark(void)
{
    name = "Raspberry Pi 3 Input Output";
}

VEXPRESS_A15_IO_quark::~VEXPRESS_A15_IO_quark() { }

bool VEXPRESS_A15_IO_quark::detectsystem(void) { return (bool)(__arm__); }

void VEXPRESS_A15_IO_quark::reset(void) { }

// Get a uint8_t from the io ports
uint8_t VEXPRESS_A15_IO_quark::in8(size_t port)
{
    return *(volatile uint8_t*)(MMIO_BASE + port);
}

// Send a uint8_t through the io ports
void VEXPRESS_A15_IO_quark::out8(size_t port, uint8_t value)
{
    *(volatile uint8_t*)(MMIO_BASE + port) = value;
}

// Get a uint16_t from the io ports
uint16_t VEXPRESS_A15_IO_quark::in16(size_t port)
{
    return *(volatile uint16_t*)(MMIO_BASE + port);
}

// Send a uint16_t through the io ports
void VEXPRESS_A15_IO_quark::out16(size_t port, uint16_t value)
{
    *(volatile uint16_t*)(MMIO_BASE + port) = value;
}

// Get a uint32_t from the io ports
uint32_t VEXPRESS_A15_IO_quark::in32(size_t port)
{
    return *(volatile uint32_t*)(MMIO_BASE + port);
}

// Send a uint32_t through the io ports
void VEXPRESS_A15_IO_quark::out32(size_t port, uint32_t value)
{
    *(volatile uint32_t*)(MMIO_BASE + port) = value;
}