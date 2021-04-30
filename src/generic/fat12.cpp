// By Tsuki Superior
#include <generic/fat12.hpp>
#include <generic/nucleus_instance.hpp>

FAT12_quark::FAT12_quark(void)
    : maxclustercount(0xFF5)
{
    name = "File Allocation Table 12";
}

bool FAT12_quark::detectsystem(void)
{
    return true;
    uint8_t diskfsname[5];
    tsos->disk.getbytes(0x4f, 0x05, diskfsname);
    const char* fsname = "FAT12";
    for (uint8_t x = 0; x < 0x5; x++) {
        if ((uint8_t)fsname[x] != diskfsname[x]) {
            return false;
        }
    }
}

void FAT12_quark::reset(void) { }

char** FAT12_quark::readdir(char* path) { return nullptr; }

void FAT12_quark::rename(char* path, char* newPath) { }

File FAT12_quark::open(char* path)
{
    File tmp;
    return tmp;
}

void FAT12_quark::close(File file) { }

char* FAT12_quark::read(File file) { return nullptr; }

void FAT12_quark::write(File file, char* data) { }

char* FAT12_quark::readfile(char* path) { return nullptr; }

void FAT12_quark::writefile(char* path, char* data) { }

void FAT12_quark::appendfile(char* path, char* data) { }

bool FAT12_quark::exists(char* path) { return false; }

bool FAT12_quark::isfilenamevalid(char* name) { return true; }
