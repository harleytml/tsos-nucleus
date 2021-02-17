//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_FILESYSTEM_PERMISSIONS__
#define __TSOS_NUCLEUS_FILESYSTEM_PERMISSIONS__

#include "../../core/driver.hpp"
#include "../../core/types.hpp"

class Permissions
{
public:
  //Constructor
  Permissions(bool r, bool w, bool e);

  //Read permission
  bool read;

  //Write permission
  bool write;

  //Execute permission
  bool execute;
};

#endif