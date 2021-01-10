//By Tsuki Superior
#include "filesystem.hpp"

Filesystem::Filesystem(void)
{
}

Filesystem::~Filesystem(void)
{
}

char *[] Filesystem::readdir(char *path) {
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

Tsos_file Filesystem::open(char *path)
{
    if (exists(path))
    {
    }
}

void Filesystem::close(Tsos_file file)
{
    if (file.path != NULL)
    {
    }
}

uint8_t[] Filesystem::read(Tsos_file file, uint32_t length);
{
}

void Filesystem::write(Tsos_file file, uint8_t[] data)
{
}

uint8_t[] Filesystem::readfile(char *path)
{
    if (exists(path))
    {
    }
}

void Filesystem::writefile(char *path, uint8_t[] data)
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

BOOLEAN Filesystem::exists(char *path)
{
    return driver->exists(path);
}

void Filesystem::mkdir(char *path, File_permissions f)
{
}

void Filesystem::rmdir(char *path)
{
}

void Filesystem::access(char *path)
{
}

Filesystem_driver::Filesystem_driver(void)
{
}

Filesystem_driver::~Filesystem_driver(void)
{
}

File_permissions::File_permissions(BOOLEAN r, BOOLEAN w, BOOLEAN e)
{
    read = r;
    write = w;
    execute = e;
}