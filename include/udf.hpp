//By Tsuki Superior
#ifndef __TSOS_UDF_DRIVER__
#define __TSOS_UDF_DRIVER__

#include "filesystem_driver.hpp"
#include "filesystem_file.hpp"

class UDF_driver : public Filesystem_driver
{
public:
  UDF_driver(void);
  bool detectsystem(void) override;
  char **readdir(char *path) override;
  void rename(char *path, char *newPath) override;
  File open(char *path);
  void close(File file);
  char *read(File file);
  void write(File file, char *data);
  char *readfile(char *path);
  void writefile(char *path, char *data);
  void appendfile(char *path, char *data);
  bool exists(char *path) override;

private:
  char *currentdirectory;
  File openfiles[128];
};

#endif