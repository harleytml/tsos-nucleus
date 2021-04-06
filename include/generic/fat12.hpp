/* By Tsuki Superior
 * Generic FAT12 Quark
 *
 * The FAT12 will be used rarely these days, but you might see it on a floppy disk
 */

#ifndef __TSOS_FAT12_QUARK__
#define __TSOS_FAT12_QUARK__

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