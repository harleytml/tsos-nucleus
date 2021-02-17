//By Tsuki Superior
#ifndef __TSOS_FAT16_DRIVER__
#define __TSOS_FAT16_DRIVER__

#include "../../../subsystems/filesystem/filesystem_driver.hpp"
#include "../../../subsystems/filesystem/filesystem_file.hpp"

class FAT16_driver : public Filesystem_driver
{
public:
  FAT16_driver(void);
  char **readdir(char *path);
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