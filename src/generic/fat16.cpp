//By Tsuki Superior
#include "generic/fat16.hpp"
#include "generic/nucleus_instance.hpp"

FAT16_quark::FAT16_quark(void)
{
  name = "File Allocation Table 16";
}

bool FAT16_quark::detectsystem(void)
{
  uint8_t *diskfsname = tsos->disk.getbytes(0x4f, 0x05);
  char *fsname = "FAT16";
  for (uint8_t x = 0; x < 0x5; x++)
  {
    if ((uint8_t)fsname[x] != diskfsname[x])
    {
      return false;
    }
  }
  return true;
}

void FAT16_quark::reset(void)
{
}

char **FAT16_quark::readdir(char *path)
{
  return (char **)NULL;
}

void FAT16_quark::rename(char *path, char *newPath)
{
}

File FAT16_quark::open(char *path)
{
  return File();
}

void FAT16_quark::close(File file)
{
}

char *FAT16_quark::read(File file)
{
  return "";
}

void FAT16_quark::write(File file, char *data)
{
}

char *FAT16_quark::readfile(char *path)
{
  return "";
}

void FAT16_quark::writefile(char *path, char *data)
{
}

void FAT16_quark::appendfile(char *path, char *data)
{
}

bool FAT16_quark::exists(char *path)
{
  return false;
}
