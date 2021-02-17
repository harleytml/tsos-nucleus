//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_FILESYSTEM_FILE__
#define __TSOS_NUCLEUS_FILESYSTEM_FILE__

#include "../../core/driver.hpp"
#include "../../core/types.hpp"
#include "./filesystem_permissions.hpp"

//A file in Tsos
class File
{
public:
  //Constructor of a file
  File(void);

  //Constructor
  File(char *pa, Permissions per);

  //The path of the file
  char *path;

  //The permissions the file was opened in
  Permissions permissions;
};

#endif
