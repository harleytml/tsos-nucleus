// By Tsuki Superior
#include "generic/filesystem_nucleon.hpp"
#include "generic/nucleus_instance.hpp"

Filesystem::Filesystem(void)
{
  static FAT12_quark fat12_quark = FAT12_quark();
  static FAT16_quark fat16_quark = FAT16_quark();
  static FAT32_quark fat32_quark = FAT32_quark();
  static SFS_quark sfs_quark = SFS_quark();
  static UDF_quark udf_quark = UDF_quark();

  if (attachquark(fat32_quark) ||
      attachquark(fat16_quark) ||
      attachquark(fat12_quark) ||
      attachquark(sfs_quark) ||
      attachquark(udf_quark))
  {
    return;
  }
}

Filesystem::~Filesystem()
{
}

char **Filesystem::readdir(char *path)
{
  if (exists(path))
  {
    return quark->readdir(path);
  }
  return (char **)"";
}

void Filesystem::rename(char *path, char *newPath)
{
  if (!exists(newPath) && exists(path))
  {
    quark->rename(path, newPath);
  }
}

File Filesystem::open(char *path)
{
  if (exists(path))
  {
  }
  return File();
}

void Filesystem::close(File file)
{
  if (strcmp(file.path, "") != 0)
  {
  }
}

uint8_t *Filesystem::read(File file, uint32_t length)
{
  return (uint8_t *)"";
}

void Filesystem::write(File file, uint8_t data[])
{
}

uint8_t *Filesystem::readfile(char *path)
{
  if (exists(path))
  {
  }
  return (uint8_t *)"";
}

void Filesystem::writefile(char *path, uint8_t *data)
{
  if (exists(path))
  {
  }
}

void Filesystem::appendfile(char *path, uint8_t *data)
{
  if (exists(path))
  {
  }
}

bool Filesystem::exists(char *path)
{
  return quark->exists(path);
}

void Filesystem::mkdir(char *path, Permissions f)
{
}

void Filesystem::rmdir(char *path)
{
}

void Filesystem::access(char *path)
{
}
