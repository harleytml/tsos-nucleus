//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_FILESYSTEM_FILE__
#define __TSOS_NUCLEUS_FILESYSTEM_FILE__

#include "generic/driver.hpp"
#include "generic/types.hpp"
#include "generic/filesystem_permissions.hpp"

//A file in Tsos
class File
{
public:
  //Constructor of a file
  File(void);

  //Constructor
  File(char *pa, Permissions per);

  //Destructor
  ~File();

  //The path of the file
  const char *path;

  //The permissions the file was opened in
  Permissions permissions;
};

#endif
