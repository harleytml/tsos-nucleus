// By Tsuki Superior
#include <generic/nucleus_instance.hpp>
#include <generic/sfs.hpp>

SFS_quark::SFS_quark(void)
{
    name = "Simple File System";
}

bool SFS_quark::detectsystem(void)
{
    return true;
    uint8_t diskfsname[3];
    tsos->disk.getbytes(0x4f, 0x03, diskfsname);
    const char *fsname = "SFS";
    for (uint8_t x = 0; x < 0x3; x++)
    {
        if ((uint8_t)fsname[x] != diskfsname[x])
        {
            return false;
        }
    }
}

void SFS_quark::reset(void)
{
}

char **SFS_quark::readdir(char *path)
{
    return nullptr;
}

void SFS_quark::rename(char *path, char *newPath)
{
}

File SFS_quark::open(char *path)
{
    File tmp;
    return tmp;
}

void SFS_quark::close(File file)
{
}

char *SFS_quark::read(File file)
{
    return nullptr;
}

void SFS_quark::write(File file, char *data)
{
}

char *SFS_quark::readfile(char *path)
{
    return nullptr;
}

void SFS_quark::writefile(char *path, char *data)
{
}

void SFS_quark::appendfile(char *path, char *data)
{
}

bool SFS_quark::exists(char *path)
{
    return false;
}

bool SFS_quark::isfilenamevalid(char *name)
{
    return true;
}
