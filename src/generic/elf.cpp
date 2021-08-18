// By Tsuki Superior
#include <generic/elf.hpp>
#include <generic/nucleus_instance.hpp>

ELF_quark::ELF_quark(void)
{
    name = "Executable and Linkable Format";
}

bool ELF_quark::detectsystem(void)
{
    return true;
    // return isvalidexecutable("/nucleus");
}

void ELF_quark::reset(void)
{
}

bool ELF_quark::isvalidexecutable(char *path)
{
    Elf32_header header = Elf32_header();
    File file = tsos->filesystem.open(path);
    uint8_t *exec = tsos->filesystem.read(file, sizeof(Elf32_header));
    memcpy(&header, exec, sizeof(Elf32_header));

    // Make sure this is a verison 1 elf file
    if (header.ei_version != 1)
    {
        return false;
    }

    // Make sure the elf file is marked as the default value, sysv
    if (header.ei_osabi != ei_osabi::EIO_SYSV)
    {
        return false;
    }

    // Make sure the executable is of a version lower or equal to the kernel
    if (header.ei_osabiversion > tsos->version)
    {
        return false;
    }

    if (memcpy(&header.ei_magic, EI_MAG, 4) == 0)
    {

// A i386 elf file
#ifdef __i386__
        return header.e_machine == e_machine::EM_386;
#endif

// A generic ARM elf file
#ifdef __arm__
        return header.e_machine == e_machine::EM_ARM;
#endif

// A generic ARM64 elf file
#ifdef __aarch64__
        return header.e_machine == e_machine::EM_AARCH64;
#endif

        return false;
    }
    else
    {
        return false;
    }
}
