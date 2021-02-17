// By Tsuki Superior
#include "./filesystem_module.hpp"

Filesystem::Filesystem(void)
{
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
    return NULL;
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
    if (file.path != NULL)
    {
    }
}

uint8_t *Filesystem::read(File file, uint32_t length);
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

void Filesystem::writefile(char *path, uint8_t *data[])
{
    if (exists(path))
    {
    }
}

void Filesystem::appendfile(char *path, uint8_t[] data)
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
