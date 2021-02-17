//By Tsuki Superior
//Model by Brendan Trotter
#ifndef __TSOS_SFS_DRIVER__
#define __TSOS_SFS_DRIVER__

#include "../../../subsystems/filesystem/filesystem_driver.hpp"
#include "../../../subsystems/filesystem/filesystem_file.hpp"

class SFS_driver : public Filesystem_driver
{
public:
  SFS_driver(void);
  char ** readdir(char *path);
  void rename(char *path, char *newPath);
  File open(char *path);
  void close(File file);
  char *read(File file);
  void write(File file, char *data);
  char *readfile(char *path);
  void writefile(char *path, char *data);
  void appendfile(char *path, char *data);
  bool exists(char *path);

private:
  char *currentdirectory;
  File openfiles[128];
};

#endif