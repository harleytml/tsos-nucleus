/* By Tsuki Superior
 * Generic FAT32 Quark
 *
 * The FAT32 will be used more than its previous versions of FAT.
 * 
 */

#ifndef __TSOS_FAT32_QUARK__
#define __TSOS_FAT32_QUARK__

#include <generic/filesystem_quark.hpp>
#include <generic/filesystem_file.hpp>
#include <generic/array.hpp>

class FAT32_quark : public Filesystem_quark
{
public:
  FAT32_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  Array<Array<char>> *readdir(char *path) final;
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
};

#endif