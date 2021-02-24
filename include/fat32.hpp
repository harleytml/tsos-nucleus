//By Tsuki Superior
#ifndef __TSOS_FAT32_DRIVER__
#define __TSOS_FAT32_DRIVER__

#include "filesystem_driver.hpp"
#include "filesystem_file.hpp"

class FAT32_driver : public Filesystem_driver
{
public:
  FAT32_driver(void);
  bool detectsystem(void);
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