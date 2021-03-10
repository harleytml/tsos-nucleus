//By Tsuki Superior
#ifndef __TSOS_FAT12_DRIVER__
#define __TSOS_FAT12_DRIVER__

#include "filesystem_driver.hpp"
#include "filesystem_file.hpp"

class FAT12_driver : public Filesystem_driver
{
public:
  FAT12_driver(void);
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
} __attribute__((packed));

#endif