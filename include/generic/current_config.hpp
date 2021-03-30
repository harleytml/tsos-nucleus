//By Tsuki Superior
#ifndef __TSOS_CURRENT_CONFIG__
#define __TSOS_CURRENT_CONFIG__

/*
This file ensures the proper headers are being used for the proper system
*/

#include "fat12.hpp"
#include "fat16.hpp"
#include "fat32.hpp"
#include "sfs.hpp"
#include "udf.hpp"
#include "elf.hpp"

#ifdef __PERSONAL_COMPUTER__

#include "grub2.hpp"
#include "atapi.hpp"
#include "at_keyboard.hpp"
#include "xt_keyboard.hpp"
#include "elf.hpp"
#include "rs232.hpp"
#include "cga.hpp"
#include "ega.hpp"
#include "mda.hpp"
#include "vga.hpp"
#include "gdt.hpp"
#include "pc_speaker.hpp"
#include "pc_io.hpp"

#endif

#ifdef __GAMEBOY_ADVANCED__

#include "gba_screen.hpp"
#include "gba_gamepad.hpp"
#include "gba_io_port.hpp"
#include "gba_boot.hpp"
#include "gba_cartridge.hpp"
#include "gba_sound.hpp"

#endif

#ifdef __NSPIRE__

#endif

#ifdef __RASPBERRY_PI_3__

#include "rpi3_boot.hpp"
#include "rpi3_keyboard.hpp"
#include "rpi3_screen.hpp"
#include "rpi3_sd_card.hpp"
#include "rpi3_sound.hpp"
#include "rpi3_uart.hpp"

#endif

#ifdef __NINTENDO_DUAL_SCREEN__

#endif

#endif
