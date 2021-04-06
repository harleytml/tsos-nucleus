//By Tsuki Superior
#ifndef __TSOS_NSPIRE_CM_DISK_QUARK__
#define __TSOS_NSPIRE_CM_DISK_QUARK__

#include <generic/disk_quark.hpp>

class NSPIRE_CM_DISK_quark : public Disk_quark
{
public:
  // Constructor
  NSPIRE_CM_DISK_quark(void);

  ~NSPIRE_CM_DISK_quark();

  bool detectsystem(void) final;

  void reset(void) final;

  // Get an amount of bytes from the disk
  void getbytes(uint8_t *buffer, uint16_t offset, uint8_t len) final;

  // Get the sector size
  uint16_t getsectorsize(void) final;
};

#endif
