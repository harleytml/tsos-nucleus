//By Tsuki Superior
#ifndef __TSOS_SFS_DRIVER__
#define __TSOS_SFS_DRIVER__

#include "../../../subsystems/filesystem/filesystem.hpp"

class SFS_driver : public Filesystem_driver
{
public:
  SFS_driver(void);
  char *[] readdir(char *path);
  void rename(char *path, char *newPath);
  Tsos_file open(char *path);
  void close(Tsos_file file);
  char *read(Tsos_file file);
  void write(Tsos_file file, char *data);
  char *readfile(char *path);
  void writefile(char *path, char *data);
  void appendfile(char *path, char *data);
  bool exists(char *path);

private:
  char *currentdirectory;
  Tsos_file openfiles[MAX_FILES_OPEN];
};

#endif