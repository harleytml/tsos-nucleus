/* By Tsuki Superior
 * Nucleus Configuration
 *
 * This is the configuration file that detects from the defines to see what
 * quarks should actually be included
 */

#ifndef __TSOS_CURRENT_CONFIG__
#define __TSOS_CURRENT_CONFIG__

#include "generic/fat12.hpp"
#include "generic/fat16.hpp"
#include "generic/fat32.hpp"
#include "generic/sfs.hpp"
#include "generic/udf.hpp"
#include "generic/elf.hpp"

#ifdef __PERSONAL_COMPUTER__

#include "pc/grub2.hpp"
#include "pc/atapi.hpp"
#include "pc/at_keyboard.hpp"
#include "pc/xt_keyboard.hpp"
#include "pc/rs232.hpp"
#include "pc/cga.hpp"
#include "pc/ega.hpp"
#include "pc/mda.hpp"
#include "pc/vga.hpp"
#include "pc/gdt.hpp"
#include "pc/pc_speaker.hpp"
#include "pc/pc_io.hpp"

#endif

#ifdef __GAMEBOY_ADVANCED__

#include "gba/gba_screen.hpp"
#include "gba/gba_gamepad.hpp"
#include "gba/gba_io_port.hpp"
#include "gba/gba_boot.hpp"
#include "gba/gba_cartridge.hpp"
#include "gba/gba_sound.hpp"

#endif

#ifdef __NSPIRE__

#endif

#ifdef __RASPBERRY_PI_3__

#include "rpi3/rpi3_boot.hpp"
#include "rpi3/rpi3_keyboard.hpp"
#include "rpi3/rpi3_screen.hpp"
#include "rpi3/rpi3_sd_card.hpp"
#include "rpi3/rpi3_sound.hpp"
#include "rpi3/rpi3_uart.hpp"

#endif

#ifdef __NINTENDO_DUAL_SCREEN__

#endif

#endif
