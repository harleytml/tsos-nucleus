// By Tsuki Superior
#include <generic/filesystem_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

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

Array<String &> &Filesystem::readdir(String &path)
{
  if (exists(path))
  {
    return quark->readdir(path);
  }
  Array<String &> *tmp = (Array<String &> *)nullptr;
  return *tmp;
}

void Filesystem::rename(String &path, String &newPath)
{
  if (!exists(newPath) && exists(path))
  {
    quark->rename(path.raw(), newPath.raw());
  }
}

File Filesystem::open(String &path)
{
  if (exists(path))
  {
  }
  return File();
}

void Filesystem::close(File file)
{
  if (file.path.len() != 0)
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

uint8_t *Filesystem::readfile(String &path)
{
  if (exists(path))
  {
  }
  return (uint8_t *)"";
}

void Filesystem::writefile(String &path, uint8_t *data)
{
  if (exists(path))
  {
  }
}

void Filesystem::appendfile(String &path, uint8_t *data)
{
  if (exists(path))
  {
  }
}

bool Filesystem::exists(String &path)
{
  return quark->exists(path);
}

void Filesystem::mkdir(String &path, Permissions f)
{
}

void Filesystem::rmdir(String &path)
{
}

void Filesystem::access(String &path)
{
}
