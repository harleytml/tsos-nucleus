/* By Tsuki Superior
 * Generic FAT12 Quark
 *
 * The FAT12 will be used rarely these days, but you might see it on a floppy disk
 */

#ifndef __TSOS_FAT12_QUARK__
#define __TSOS_FAT12_QUARK__

#include <generic/filesystem_quark.hpp>
#include <generic/filesystem_file.hpp>
#include <generic/array.hpp>

class FAT12_quark : public Filesystem_quark
{
public:
  FAT12_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  Array<String &> &readdir(String &path) final;
  void rename(String &path, char *newPath) final;
  File open(String &path) final;
  void close(File file) final;
  char *read(File file) final;
  void write(File file, char *data) final;
  char *readfile(String &path) final;
  void writefile(String &path, char *data) final;
  void appendfile(String &path, char *data) final;
  bool exists(String &path) final;
  bool isfilenamevalid(char *name) final;

private:
  char *currentdirectory;
  File openfiles[128];
};

#endif