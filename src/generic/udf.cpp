//By Tsuki Superior
#include "generic/udf.hpp"
#include "generic/nucleus_instance.hpp"

UDF_quark::UDF_quark(void)
{
  name = "Universal Disk Filesystem";
}

bool UDF_quark::detectsystem(void)
{

  uint8_t *diskfsname = tsos->disk.getbytes(0x4f, 0x05);
  char *fsname = "";
  for (uint8_t x = 0; x < 0x5; x++)
  {
    if ((uint8_t)fsname[x] != diskfsname[x])
    {
      return false;
    }
  }
  return true;
}

void UDF_quark::reset(void)
{
}

char **UDF_quark::readdir(char *path)
{
  return (char **)"";
}

void UDF_quark::rename(char *path, char *newPath)
{
}

File UDF_quark::open(char *path)
{
  return File();
}

void UDF_quark::close(File file)
{
}

char *UDF_quark::read(File file)
{
  return "";
}

void UDF_quark::write(File file, char *data)
{
}

char *UDF_quark::readfile(char *path)
{
  return "";
}

void UDF_quark::writefile(char *path, char *data)
{
}

void UDF_quark::appendfile(char *path, char *data)
{
}

bool UDF_quark::exists(char *path)
{
  return false;
}