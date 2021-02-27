//By Tsuki Superior
#include "fat32.hpp"

FAT32_driver::FAT32_driver(void)
{
    name = "File Allocation Table 32";
}

bool FAT32_driver::detectsystem(void)
{
    //Doesn't work right now
    /*
    uint8_t diskfsname[] = tsos.disk.getbytes(0x4f, 0x05);
    char *fsname = "FAT32";
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

char **FAT32_driver::readdir(char *path)
{
    return (char **)NULL;
}

void FAT32_driver::rename(char *path, char *newPath)
{
}

File FAT32_driver::open(char *path)
{
    return File();
}

void FAT32_driver::close(File file)
{
}

char *FAT32_driver::read(File file)
{
    return "";
}

void FAT32_driver::write(File file, char *data)
{
}

char *FAT32_driver::readfile(char *path)
{
    return "";
}

void FAT32_driver::writefile(char *path, char *data)
{
}

void FAT32_driver::appendfile(char *path, char *data)
{
}

bool FAT32_driver::exists(char *path)
{
    return false;
}
