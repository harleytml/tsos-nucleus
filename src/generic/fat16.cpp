//By Tsuki Superior
#include "generic/fat16.hpp"

FAT16_driver::FAT16_driver(void)
{
  name = "File Allocation Table 16";
}

bool FAT16_driver::detectsystem(void)
{
  //Doesn't work right now
  /*
    uint8_t diskfsname[] = tsos.disk.getbytes(0x4f, 0x05);
    char *fsname = "FAT16";
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

void FAT16_driver::reset(void)
{
}

char **FAT16_driver::readdir(char *path)
{
  return (char **)NULL;
}

void FAT16_driver::rename(char *path, char *newPath)
{
}

File FAT16_driver::open(char *path)
{
  return File();
}

void FAT16_driver::close(File file)
{
}

char *FAT16_driver::read(File file)
{
  return "";
}

void FAT16_driver::write(File file, char *data)
{
}

char *FAT16_driver::readfile(char *path)
{
  return "";
}

void FAT16_driver::writefile(char *path, char *data)
{
}

void FAT16_driver::appendfile(char *path, char *data)
{
}

bool FAT16_driver::exists(char *path)
{
  return false;
}
