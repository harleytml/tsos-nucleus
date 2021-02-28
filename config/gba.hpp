//By Tsuki Superior
#ifndef __TSOS_CURRENT_CONFIG__
#define __TSOS_CURRENT_CONFIG__

#include "gba_boot.hpp"
#include "gba_cartridge.hpp"
#include "fat12.hpp"
#include "fat16.hpp"
#include "fat32.hpp"
#include "sfs.hpp"
#include "udf.hpp"
#include "gba_gamepad.hpp"
#include "gba_io_port.hpp"
#include "elf.hpp"
#include "gba_screen.hpp"

#define GAMEBOY_ADVANCED

static GBA_BOOT_driver gba_boot_driver;
static GBA_CARTRIDGE_driver gba_cartridge_driver;
static FAT12_driver fat12_driver;
static FAT16_driver fat16_driver;
static FAT32_driver fat32_driver;
static SFS_driver sfs_driver;
static UDF_driver udf_driver;
static GBA_GAMEPAD_driver gba_gamepad_driver;
static ELF_driver elf_driver;
static GBA_SCREEN_driver gba_screen_driver;

#endif
