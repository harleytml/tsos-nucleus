//By Tsuki Superior
#ifndef __TSOS_RPI3_SD_CARD_QUARK__
#define __TSOS_RPI3_SD_CARD_QUARK__

#include <generic/disk_quark.hpp>

class RPI3_SD_CARD_quark : public Disk_quark
{
public:
  // Constructor
  RPI3_SD_CARD_quark(void);

  ~RPI3_SD_CARD_quark();

  bool detectsystem(void) final;

  void reset(void) final;

  // Get an amount of bytes from the disk
  void getbytes(uint8_t *buffer, uint16_t offset, uint8_t len) final;

  // Get the sector size
  uint16_t getsectorsize(void) final;
};

#endif
