// By Tsuki Superior
#include "filesystem_module.hpp"
#include "nucleus_instance.hpp"

Filesystem::Filesystem(void)
{
    static FAT12_driver fat12_driver = FAT12_driver();
    static FAT16_driver fat16_driver = FAT16_driver();
    static FAT32_driver fat32_driver = FAT32_driver();
    static SFS_driver sfs_driver = SFS_driver();
    static UDF_driver udf_driver = UDF_driver();

    if (attachdriver(fat32_driver) ||
        attachdriver(fat16_driver) ||
        attachdriver(fat12_driver) ||
        attachdriver(sfs_driver) ||
        attachdriver(udf_driver))
    {
        return;
    }
}

Filesystem::~Filesystem()
{
}

char **Filesystem::readdir(char *path)
{
    if (exists(path))
    {
        return driver->readdir(path);
    }
    return (char **)"";
}

void Filesystem::rename(char *path, char *newPath)
{
    if (!exists(newPath) && exists(path))
    {
        driver->rename(path, newPath);
    }
}

File Filesystem::open(char *path)
{
    if (exists(path))
    {
    }
}

void Filesystem::close(File file)
{
    if (strcmp(file.path, "") != 0)
    {
    }
}

uint8_t *Filesystem::read(File file, uint32_t length)
{
}

void Filesystem::write(File file, uint8_t data[])
{
}

uint8_t *Filesystem::readfile(char *path)
{
    if (exists(path))
    {
    }
}

void Filesystem::writefile(char *path, uint8_t *data)
{
    if (exists(path))
    {
    }
}

void Filesystem::appendfile(char *path, uint8_t *data)
{
    if (exists(path))
    {
    }
}

bool Filesystem::exists(char *path)
{
    return driver->exists(path);
}

void Filesystem::mkdir(char *path, Permissions f)
{
}

void Filesystem::rmdir(char *path)
{
}

void Filesystem::access(char *path)
{
}
