//By Tsuki Superior
#include <generic/fat32.hpp>
#include <generic/nucleus_instance.hpp>

FAT32_quark::FAT32_quark(void)
{
  name = "File Allocation Table 32";
}

bool FAT32_quark::detectsystem(void)
{
  return true;
  uint8_t *diskfsname = tsos->disk.getbytes(0x4f, 0x05);
  const char *fsname = "FAT32";
  for (uint8_t x = 0; x < 0x5; x++)
  {
    if ((uint8_t)fsname[x] != diskfsname[x])
    {
      return false;
    }
  }
}

void FAT32_quark::reset(void)
{
}

Array<String &> &FAT16_quark::readdir(String &path)
{
  Array<String &> *tmp = (Array<String &> *)nullptr;
  return *tmp;
}

void FAT32_quark::rename(String &path, char *newPath)
{
}

File FAT32_quark::open(String &path)
{
  File tmp;
  return tmp;
}

void FAT32_quark::close(File file)
{
}

char *FAT32_quark::read(File file)
{
  return "";
}

void FAT32_quark::write(File file, char *data)
{
}

char *FAT32_quark::readfile(String &path)
{
  return "";
}

void FAT32_quark::writefile(String &path, char *data)
{
}

void FAT32_quark::appendfile(String &path, char *data)
{
}

bool FAT32_quark::exists(String &path)
{
  return false;
}

bool FAT32_quark::isfilenamevalid(char *name)
{
  return true;
}
