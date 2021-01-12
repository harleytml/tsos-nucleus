//By Tsuki Superior
#ifndef __TSOS_CD_DRIVER__
#define __TSOS_CD_DRIVER__

#define SECTOR_SIZE

#include "disk.hpp"

class CD_driver : public Disk_driver
{
public:
  //Constructor
  CD_driver(void);

  BOOLEAN detectsystem(void);

  //Get a amount of bytes from the disk
  char *getbytes(uint16_t offset, uint8_t len);

  //Get the sector size
  uint16_t getsectorsize(void);

private:
  //
};

#endif