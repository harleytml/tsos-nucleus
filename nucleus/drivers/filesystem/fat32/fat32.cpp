//By Tsuki Superior
#include "fat32.hpp"

FAT32_driver::FAT32_driver(void)
{
    name = "File Allocation Table 32";
}

bool FAT32_driver::detectsystem(void)
{
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
}

char ** FAT32_driver::readdir(char *path) {
}

void FAT32_driver::rename(char *path, char *newPath)
{
}

Tsos_file FAT32_driver::open(char *path)
{
}

void FAT32_driver::close(Tsos_file file)
{
}

char *FAT32_driver::read(Tsos_file file)
{
}

void FAT32_driver::write(Tsos_file file, char *data)
{
}

char *FAT32_driver::readfile(char *path)
{
}

void FAT32_driver::writefile(char *path, char *data)
{
}

void FAT32_driver::appendfile(char *path, char *data)
{
}

bool FAT32_driver::exists(char *path)
{
}
