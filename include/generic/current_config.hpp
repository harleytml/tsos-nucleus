/* By Tsuki Superior
 * Nucleus Configuration
 *
 * This is the configuration file that detects from the defines to see what
 * quarks should actually be included
 */

#pragma once

#include <generic/fat12.hpp>
#include <generic/fat16.hpp>
#include <generic/fat32.hpp>
#include <generic/sfs.hpp>
#include <generic/udf.hpp>
#include <generic/elf.hpp>
#include <generic/ustar.hpp>

#ifdef __PERSONAL_COMPUTER__

#include <pc/multiboot.hpp>
#include <pc/atapi.hpp>
#include <pc/at_keyboard.hpp>
#include <pc/xt_keyboard.hpp>
#include <pc/pc_uart.hpp>
#include <pc/cga.hpp>
#include <pc/ega.hpp>
#include <pc/mda.hpp>
#include <pc/vga.hpp>
#include <pc/gdt.hpp>
#include <pc/pc_speaker.hpp>
#include <pc/pc_io.hpp>
#include <pc/pc_mem.hpp>
#include <pc/cmos.hpp>

#endif

#ifdef __NSPIRE__

#include <nspire/nspire-cm_boot.hpp>
#include <nspire/nspire-cm_disk.hpp>
#include <nspire/nspire-cm_keyboard.hpp>
#include <nspire/nspire-cm_screen.hpp>
#include <nspire/nspire-cm_sound.hpp>
#include <nspire/nspire-cm_uart.hpp>
#include <nspire/nspire-cx_boot.hpp>
#include <nspire/nspire-cx_disk.hpp>
#include <nspire/nspire-cx_keyboard.hpp>
#include <nspire/nspire-cx_screen.hpp>
#include <nspire/nspire-cx_sound.hpp>
#include <nspire/nspire-cx_uart.hpp>

#endif

#ifdef __RASPBERRY_PI_3__

#include <rpi3/rpi3_boot.hpp>
#include <rpi3/rpi3_keyboard.hpp>
#include <rpi3/rpi3_screen.hpp>
#include <rpi3/rpi3_sd_card.hpp>
#include <rpi3/rpi3_sound.hpp>
#include <rpi3/rpi3_uart.hpp>

#endif

#ifdef __NINTENDO_DUAL_SCREEN__

#endif
