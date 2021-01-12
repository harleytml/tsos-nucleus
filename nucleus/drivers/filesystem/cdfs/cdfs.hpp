//By Tsuki Superior
#ifndef __TSOS_CDFS_DRIVER__
#define __TSOS_CDFS_DRIVER__

#include "filesystem.hpp"

class CDFS_driver: public Filesystem_driver
{
 public:
  CDFS_driver(void);
  BOOLEAN detectsystem(void);
  char ** readdir(char * path);
  void rename(char * path, char * newPath);
  Tsos_file open(char * path);
  void close(Tsos_file file);
  char * read(Tsos_file file);
  void write(Tsos_file file, char * data);
  char * readfile(char * path);
  void writefile(char * path, char * data);
  void appendfile(char * path, char * data);
  BOOLEAN exists(char * path);
 private:
  char * currentdirectory;
  Tsos_file openfiles[MAX_FILES_OPEN];
};

#endif