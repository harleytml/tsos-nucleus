//By Tsuki Superior
//Model by Brendan Trotter
#ifndef __TSOS_SFS_DRIVER__
#define __TSOS_SFS_DRIVER__

#include "generic/filesystem_driver.hpp"
#include "generic/filesystem_file.hpp"

class SFS_driver : public Filesystem_driver
{
public:
  SFS_driver(void);
  bool detectsystem(void) final;
  void reset(void) final;
  char **readdir(char *path) final;
  void rename(char *path, char *newPath) final;
  File open(char *path) final;
  void close(File file) final;
  char *read(File file) final;
  void write(File file, char *data) final;
  char *readfile(char *path) final;
  void writefile(char *path, char *data) final;
  void appendfile(char *path, char *data) final;
  bool exists(char *path) final;

private:
  char *currentdirectory;
  File openfiles[128];
};

#endif