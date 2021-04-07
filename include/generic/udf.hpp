/* By Tsuki Superior
 * Universal Disk Filesystem Quark
 * 
 * Normally filesystem quarks are multiplatform, but
 * this one is for PC only, because as of TS/OS version 0.0
 * the only drive that can be read from is the one that was booted from,
 * and this is most likely to happen on PC for UDF, because its used on Disks
 */

#ifndef __TSOS_UDF_QUARK__
#define __TSOS_UDF_QUARK__

#include <generic/filesystem_quark.hpp>
#include <generic/filesystem_file.hpp>

class UDF_quark : public Filesystem_quark
{
public:
  UDF_quark(void);
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
};

#endif