//By Tsuki Superior
#include <generic/ustar.hpp>
#include <generic/nucleus_instance.hpp>

USTAR_quark::USTAR_quark(void)
{
  name = "Unix Standard Tape Archive";
}

bool USTAR_quark::detectsystem(void)
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

void USTAR_quark::reset(void)
{
}

char **USTAR_quark::readdir(char *path)
{
  return nullptr;
}

void USTAR_quark::rename(char *path, char *newPath)
{
}

File USTAR_quark::open(char *path)
{
  File tmp;
  return tmp;
}

void USTAR_quark::close(File file)
{
}

char *USTAR_quark::read(File file)
{
  return nullptr;
}

void USTAR_quark::write(File file, char *data)
{
}

char *USTAR_quark::readfile(char *path)
{
  return nullptr;
}

void USTAR_quark::writefile(char *path, char *data)
{
}

void USTAR_quark::appendfile(char *path, char *data)
{
}

bool USTAR_quark::exists(char *path)
{
  return false;
}

bool USTAR_quark::isfilenamevalid(char *name)
{
  return true;
}
