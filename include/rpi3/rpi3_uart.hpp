//By Tsuki Superior
#ifndef __TSOS_RPI3_UART_QUARK__
#define __TSOS_RPI3_UART_QUARK__

#include <generic/serial_quark.hpp>

class RPI3_UART_quark : public Serial_quark
{
public:
  RPI3_UART_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  bool isdevicereadytotransmit(void) final;
  bool isdevicereadytoreceive(void) final;
  void inbyte(uint8_t byte) final;
  uint8_t outbyte(void) final;

private:
  enum class registers : uintptr_t
  {
    MMIO_BASE = 0x3F000000,
    AUX_ENABLES = (MMIO_BASE + 0x00215004),
    AUX_MU_IO_REG = (MMIO_BASE + 0x00215040),
    AUX_MU_IER_REG = (MMIO_BASE + 0x00215044),
    AUX_MU_IIR_REG = (MMIO_BASE + 0x00215048),
    AUX_MU_LCR_REG = (MMIO_BASE + 0x0021504C),
    AUX_MU_MCR_REG = (MMIO_BASE + 0x00215050),
    AUX_MU_LSR_REG = (MMIO_BASE + 0x00215054),
    AUX_MU_MSR_REG = (MMIO_BASE + 0x00215058),
    AUX_MU_SCRATCH = (MMIO_BASE + 0x0021505C),
    AUX_MU_CNTL_REG = (MMIO_BASE + 0x00215060),
    AUX_MU_STAT_REG = (MMIO_BASE + 0x00215064),
    AUX_MU_BAUD_REG = (MMIO_BASE + 0x00215068)
  };

  void mmio_write(uint32_t reg, uint32_t data)
  {
    volatile uint32_t *regi = (uint32_t *)((uintptr_t)registers::MMIO_BASE + reg);
    *regi = data;
  }

  uint32_t mmio_read(uint32_t reg)
  {
    volatile uint32_t *regi = (uint32_t *)((uintptr_t)registers::MMIO_BASE + reg);
    return *regi;
  }
};

#endif
