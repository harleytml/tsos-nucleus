/* By Tsuki Superior
 * Generic Elf Quark
 *
 * This is a quark for controlling system runtime, oriented
 * around the ELF format
 *
 * Reference: https://stackoverflow.com/questions/34960383/how-read-elf-header-in-c
 */

#ifndef __TSOS_ELF_QUARK__
#define __TSOS_ELF_QUARK__

#define EI_NIDENT 16
#define ELFMAG "\177ELF"

#include <generic/process_quark.hpp>
#include <generic/filesystem_file.hpp>

extern "C"
{
  int memcmp(const void *aptr, const void *bptr, size_t size);
}

class ELF_quark : public Process_quark
{
public:
  ELF_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  bool isvalidexecutable(String &path) final;

private:
  class Elf64_header
  {
  public:
    uint8_t e_ident[16];  /* Magic number and other info */
    uint16_t e_type;      /* Object file type */
    uint16_t e_machine;   /* Architecture */
    uint32_t e_version;   /* Object file version */
    uint64_t e_entry;     /* Entry point virtual address */
    uint64_t e_phoff;     /* Program header table file offset */
    uint64_t e_shoff;     /* Section header table file offset */
    uint32_t e_flags;     /* Processor-specific flags */
    uint16_t e_ehsize;    /* ELF header size in bytes */
    uint16_t e_phentsize; /* Program header table entry size */
    uint16_t e_phnum;     /* Program header table entry count */
    uint16_t e_shentsize; /* Section header table entry size */
    uint16_t e_shnum;     /* Section header table entry count */
    uint16_t e_shstrndx;  /* Section header string table index */
  } __attribute__((packed));

  class Elf32_header
  {
  public:
    uint8_t e_ident[16];  /* Magic number and other info */
    uint16_t e_type;      /* Object file type */
    uint16_t e_machine;   /* Architecture */
    uint32_t e_version;   /* Object file version */
    uint32_t e_entry;     /* Entry point virtual address */
    uint32_t e_phoff;     /* Program header table file offset */
    uint32_t e_shoff;     /* Section header table file offset */
    uint32_t e_flags;     /* Processor-specific flags */
    uint16_t e_ehsize;    /* ELF header size in bytes */
    uint16_t e_phentsize; /* Program header table entry size */
    uint16_t e_phnum;     /* Program header table entry count */
    uint16_t e_shentsize; /* Section header table entry size */
    uint16_t e_shnum;     /* Section header table entry count */
    uint16_t e_shstrndx;  /* Section header string table index */
  } __attribute__((packed));

  enum e_type
  {
    ET_NONE = 0,
    ET_REL = 1,
    ET_EXEC = 2,
    ET_DYN = 3,
    ET_CORE = 4,
    ET_LOPROC = 0xff00,
    ET_HIPROC = 0xffff
  };
};

#endif
