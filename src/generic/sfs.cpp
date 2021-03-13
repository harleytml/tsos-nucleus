//By Tsuki Superior
#include "sfs.hpp"

SFS_driver::SFS_driver(void)
{
    name = "Simple File System";
}

bool SFS_driver::detectsystem(void)
{
    //Doesn't work right now
    /*
    uint8_t diskfsname[] = tsos.disk.getbytes(0x4f, 0x03);
    char *fsname = "SFS";
    for (uint8_t x = 0; x < 0x3; x++)
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

void SFS_driver::reset(void)
{
}

char **SFS_driver::readdir(char *path)
{
    return (char **)"";
}

void SFS_driver::rename(char *path, char *newPath)
{
}

File SFS_driver::open(char *path)
{
    return File();
}

void SFS_driver::close(File file)
{
}

char *SFS_driver::read(File file)
{
    return "";
}

void SFS_driver::write(File file, char *data)
{
}

char *SFS_driver::readfile(char *path)
{
    return "";
}

void SFS_driver::writefile(char *path, char *data)
{
}

void SFS_driver::appendfile(char *path, char *data)
{
}

bool SFS_driver::exists(char *path)
{
    return false;
}
