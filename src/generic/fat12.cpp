//By Tsuki Superior
#include "generic/fat12.hpp"

FAT12_driver::FAT12_driver(void)
{
  name = "File Allocation Table 12";
}

bool FAT12_driver::detectsystem(void)
{
  //Doesn't work right now
  /*
    uint8_t *diskfsname = tsos.disk.getbytes(0x4f, 0x05);
    char *fsname = "FAT12";
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

void FAT12_driver::reset(void)
{
}

char **FAT12_driver::readdir(char *path)
{
  return (char **)NULL;
}

void FAT12_driver::rename(char *path, char *newPath)
{
}

File FAT12_driver::open(char *path)
{
  return File();
}

void FAT12_driver::close(File file)
{
}

char *FAT12_driver::read(File file)
{
  return "";
}

void FAT12_driver::write(File file, char *data)
{
}

char *FAT12_driver::readfile(char *path)
{
  return "";
}

void FAT12_driver::writefile(char *path, char *data)
{
}

void FAT12_driver::appendfile(char *path, char *data)
{
}

bool FAT12_driver::exists(char *path)
{
  return true;
}