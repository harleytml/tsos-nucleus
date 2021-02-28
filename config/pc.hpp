//By Tsuki Superior
#ifndef __TSOS_CURRENT_CONFIG__
#define __TSOS_CURRENT_CONFIG__

#include "grub2.hpp"
#include "cd.hpp"
#include "fat12.hpp"
#include "fat16.hpp"
#include "fat32.hpp"
#include "sfs.hpp"
#include "udf.hpp"
#include "at_keyboard.hpp"
#include "xt_keyboard.hpp"
#include "elf.hpp"
#include "rs232.hpp"
#include "cga.hpp"
#include "ega.hpp"
#include "mda.hpp"
#include "vga.hpp"

#define PERSONAL_COMPUTER

static GRUB2_driver grub2_driver;
static CD_driver cd_driver;
static FAT12_driver fat12_driver;
static FAT16_driver fat16_driver;
static FAT32_driver fat32_driver;
static SFS_driver sfs_driver;
static UDF_driver udf_driver;
static AT_KEYBOARD_driver at_keyboard_driver;
static XT_KEYBOARD_driver xt_keyboard_driver;
static ELF_driver elf_driver;
static VGA_driver vga_driver;
static EGA_driver ega_driver;
static CGA_driver cga_driver;
static MDA_driver mda_driver;

#endif
