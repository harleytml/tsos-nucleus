/* By Tsuki Superior
 * Model by Brendan Trotter
 * Simple Filesystem Driver
 */

#ifndef __TSOS_SFS_QUARK__
#define __TSOS_SFS_QUARK__

#include "generic/filesystem_quark.hpp"
#include "generic/filesystem_file.hpp"

class SFS_quark : public Filesystem_quark
{
public:
  SFS_quark(void);
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