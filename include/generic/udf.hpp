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
  void reset(void) override;
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