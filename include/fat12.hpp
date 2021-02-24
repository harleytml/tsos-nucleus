//By Tsuki Superior
#ifndef __TSOS_FAT12_DRIVER__
#define __TSOS_FAT12_DRIVER__

#include "filesystem_driver.hpp"
#include "filesystem_file.hpp"

class FAT12_driver : public Filesystem_driver
{
public:
  FAT12_driver(void);
  bool detectsystem(void);
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

enum fattributes
{
  READ_ONLY = 0x01,
  HIDDEN = 0x02,
  SYSTEM = 0x04,
  VOLUME_ID = 0,
  DIRECTORY = 0x10,
  ARCHIVE = 0x20
};

//Standard 8.3 file directory
struct Directory
{
public:
  char directory_name[11];
  uint8_t file_attributes;
  uint8_t __reserved_1__;
};

#endif