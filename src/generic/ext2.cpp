//By Tsuki Superior
#include <generic/ext2.hpp>
#include <generic/nucleus_instance.hpp>

EXT2_quark::EXT2_quark(void)
{
  name = "EXT2";
}

bool EXT2_quark::detectsystem(void)
{
  return true;
  uint8_t *diskfsname = tsos->disk.getbytes(0x4f, 0x04);
  const char *fsname = "EXT2";
  for (uint8_t x = 0; x < 0x4; x++)
  {
    if ((uint8_t)fsname[x] != diskfsname[x])
    {
      return false;
    }
  }
}

void EXT2_quark::reset(void)
{
}

char **EXT2_quark::readdir(char *path)
{
  return nullptr;
}

void EXT2_quark::rename(char *path, char *newPath)
{
}

File EXT2_quark::open(char *path)
{
  File tmp;
  return tmp;
}

void EXT2_quark::close(File file)
{
}

char *EXT2_quark::read(File file)
{
  return nullptr;
}

void EXT2_quark::write(File file, char *data)
{
}

char *EXT2_quark::readfile(char *path)
{
  return nullptr;
}

void EXT2_quark::writefile(char *path, char *data)
{
}

void EXT2_quark::appendfile(char *path, char *data)
{
}

bool EXT2_quark::exists(char *path)
{
  return false;
}

bool EXT2_quark::isfilenamevalid(char *name)
{
  return true;
}
