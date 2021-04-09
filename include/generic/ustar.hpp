/* By Tsuki Superior
 * Universal Disk Filesystem Quark
 * 
 * Normally filesystem quarks are multiplatform, but
 * this one is for PC only, because as of TS/OS version 0.0
 * the only drive that can be read from is the one that was booted from,
 * and this is most likely to happen on PC for UDF, because its used on Disks
 */

#ifndef __TSOS_USTAR_QUARK__
#define __TSOS_USTAR_QUARK__

#include <generic/filesystem_quark.hpp>
#include <generic/filesystem_file.hpp>
#include <generic/array.hpp>

extern "C"
{
  size_t oct2bin(char *str, size_t size);
}

class USTAR_quark : public Filesystem_quark
{
public:
  USTAR_quark(void);
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