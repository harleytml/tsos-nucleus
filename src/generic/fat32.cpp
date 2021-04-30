// By Tsuki Superior
#include <generic/fat32.hpp>
#include <generic/nucleus_instance.hpp>

FAT32_quark::FAT32_quark(void) : maxclustercount(0xFF5)
{
    name = "File Allocation Table 32";
}

bool FAT32_quark::detectsystem(void)
{
    return true;
    uint8_t diskfsname[5];
    tsos->disk.getbytes(0x4f, 0x05, diskfsname);
    const char *fsname = "FAT32";
    for (uint8_t x = 0; x < 0x5; x++)
    {
        if ((uint8_t)fsname[x] != diskfsname[x])
        {
            return false;
        }
    }
}

void FAT32_quark::reset(void)
{
}

char **FAT32_quark::readdir(char *path)
{
    return nullptr;
}

void FAT32_quark::rename(char *path, char *newPath)
{
}

File FAT32_quark::open(char *path)
{
    File tmp;
    return tmp;
}

void FAT32_quark::close(File file)
{
}

char *FAT32_quark::read(File file)
{
    return nullptr;
}

void FAT32_quark::write(File file, char *data)
{
}

char *FAT32_quark::readfile(char *path)
{
    return nullptr;
}

void FAT32_quark::writefile(char *path, char *data)
{
}

void FAT32_quark::appendfile(char *path, char *data)
{
}

bool FAT32_quark::exists(char *path)
{
    return false;
}

bool FAT32_quark::isfilenamevalid(char *name)
{
    return true;
}
