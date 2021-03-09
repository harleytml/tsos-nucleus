//By Tsuki Superior
//Model by Brendan Trotter
#ifndef __TSOS_SFS_DRIVER__
#define __TSOS_SFS_DRIVER__

#include "filesystem_driver.hpp"
#include "filesystem_file.hpp"

class SFS_driver : public Filesystem_driver
{
public:
  SFS_driver(void);
  bool detectsystem(void) override;
  char **readdir(char *path) override;
  void rename(char *path, char *newPath) override;
  File open(char *path) override;
  void close(File file) override;
  char *read(File file) override;
  void write(File file, char *data) override;
  char *readfile(char *path) override;
  void writefile(char *path, char *data) override;
  void appendfile(char *path, char *data) override;
  bool exists(char *path) override;

private:
  char *currentdirectory;
  File openfiles[128];
};

#endif