//By Tsuki Superior
#include "cdfs.hpp"

CDFS_driver::CDFS_driver(void)
{
    name = "Compact Disk Filesystem";
}

bool CDFS_driver::detectsystem(void)
{
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
}

char ** CDFS_driver::readdir(char *path) {
}

void CDFS_driver::rename(char *path, char *newPath)
{
}

Tsos_file CDFS_driver::open(char *path)
{
}

void CDFS_driver::close(Tsos_file file)
{
}

char *CDFS_driver::read(Tsos_file file)
{
}

void CDFS_driver::write(Tsos_file file, char *data)
{
}

char *CDFS_driver::readfile(char *path)
{
}

void CDFS_driver::writefile(char *path, char *data)
{
}

void CDFS_driver::appendfile(char *path, char *data)
{
}

bool CDFS_driver::exists(char *path)
{
}