/* By Tsuki Superior
 * Generic FAT16 Driver
 *
 * The FAT16 will be used rarely these days, but you might see it on a floppy disk
 */

#ifndef __TSOS_FAT16_QUARK__
#define __TSOS_FAT16_QUARK__

#include "generic/filesystem_driver.hpp"
#include "generic/filesystem_file.hpp"

class FAT16_driver : public Filesystem_driver
{
public:
  FAT16_driver(void);
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