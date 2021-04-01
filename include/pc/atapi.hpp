//By Tsuki Superior
#ifndef __TSOS_ATAPI_QUARK__
#define __TSOS_ATAPI_QUARK__

#include "generic/disk_quark.hpp"

class ATAPI_quark : public Disk_quark
{
public:
  // Constructor
  ATAPI_quark(void);

  ~ATAPI_quark();

  bool detectsystem(void) final;

  void reset(void) final;

  // Get an amount of bytes from the disk
  void getbytes(uint8_t *buffer, uint16_t offset, uint8_t len) final;

  // Get the sector size
  uint16_t getsectorsize(void) final;
};

#endif
