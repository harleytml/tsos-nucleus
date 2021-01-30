//By Tsuki Superior
#include "./udf.hpp"

UDF_driver::UDF_driver(void)
{
    name = "Universal Disk Filesystem";
}

bool UDF_driver::detectsystem(void)
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

char **UDF_driver::readdir(char *path)
{
}

void UDF_driver::rename(char *path, char *newPath)
{
}

Tsos_file UDF_driver::open(char *path)
{
}

void UDF_driver::close(Tsos_file file)
{
}

char *UDF_driver::read(Tsos_file file)
{
}

void UDF_driver::write(Tsos_file file, char *data)
{
}

char *UDF_driver::readfile(char *path)
{
}

void UDF_driver::writefile(char *path, char *data)
{
}

void UDF_driver::appendfile(char *path, char *data)
{
}

bool UDF_driver::exists(char *path)
{
}