// By Tsuki Superior
#include <generic/nucleus_instance.hpp>
#include <generic/udf.hpp>

UDF_quark::UDF_quark(void)
{
    name = "Universal Disk Filesystem";
}

bool UDF_quark::detectsystem(void)
{
    return true;
    uint8_t diskfsname[5];
    tsos->disk.getbytes(0x4f, 0x05, diskfsname);
    const char *fsname = "CD001";
    for (uint8_t x = 0; x < 0x5; x++)
    {
        if ((uint8_t)fsname[x] != diskfsname[x])
        {
            return false;
        }
    }
}

void UDF_quark::reset(void)
{
}

char **UDF_quark::readdir(char *path)
{
    return nullptr;
}

void UDF_quark::rename(char *path, char *newPath)
{
}

File UDF_quark::open(char *path)
{
    File tmp;
    return tmp;
}

void UDF_quark::close(File file)
{
}

char *UDF_quark::read(File file)
{
    return nullptr;
}

void UDF_quark::write(File file, char *data)
{
}

char *UDF_quark::readfile(char *path)
{
    return nullptr;
}

void UDF_quark::writefile(char *path, char *data)
{
}

void UDF_quark::appendfile(char *path, char *data)
{
}

bool UDF_quark::exists(char *path)
{
    return false;
}

bool UDF_quark::isfilenamevalid(char *name)
{
    return true;
}
