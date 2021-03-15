//By Tsuki Superior
#include "udf.hpp"

UDF_driver::UDF_driver(void)
{
  name = "Universal Disk Filesystem";
}

bool UDF_driver::detectsystem(void)
{
  //Doesn't work right now
  /*
    uint8_t diskfsname[5] = tsos.disk.getbytes(0x4f, 0x05);
    char *fsname = "";
    for (uint8_t x = 0; x < 0x5; x++)
    {
        if ((uint8_t)fsname[x] != diskfsname[x])
        {
            return false;
        }
    }
    return true;
    */
  return true;
}

void UDF_driver::reset(void)
{
}

char **UDF_driver::readdir(char *path)
{
  return (char **)"";
}

void UDF_driver::rename(char *path, char *newPath)
{
}

File UDF_driver::open(char *path)
{
  return File();
}

void UDF_driver::close(File file)
{
}

char *UDF_driver::read(File file)
{
  return "";
}

void UDF_driver::write(File file, char *data)
{
}

char *UDF_driver::readfile(char *path)
{
  return "";
}

void UDF_driver::writefile(char *path, char *data)
{
}

void UDF_driver::appendfile(char *path, char *data)
{
}

bool UDF_driver::exists(char *path)
{
  return false;
}