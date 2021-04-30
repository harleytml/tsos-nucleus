/* By Tsuki Superior
 * Generic FAT12 Quark
 *
 * The FAT12 will be used rarely these days, but you might see it on a floppy disk
 */

#pragma once

#include <generic/filesystem_quark.hpp>
#include <generic/filesystem_file.hpp>

class FAT12_quark : public Filesystem_quark
{
public:
  FAT12_quark(void);
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
  bool isfilenamevalid(char *name) final;

private:
  char *currentdirectory;
  File openfiles[128];
  const uint8_t cluster_count = 0xFF5;
};
