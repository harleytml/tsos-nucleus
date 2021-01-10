#!/bin/make -f
#By Tsuki Superior
.RECIPEPREFIX=:

BUILD_DIR=$(PWD)/../build
NUCLEUS_DIR=$(PWD)/../nucleus
FILESYSTEM_DIR=$(PWD)/../filesystem
LIBRARY_DIR=$(PWD)/../libraries
TOOLCHAIN_DIR=$(PWD)/../toolchain

CC=$(where i686-elf-gcc)
CC_FLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra

CPP=$(where i686-elf-g++)
CPP_FLAGS=-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti

AS=$(where i686-elf-as)
AS_FLAGS=

LD=$(where i686-elf-ld.gold)
LD_FLAGS=

CORE=$(NUCLEUS_DIR)/core/core.cpp $(NUCLEUS_DIR)/core/core.hpp $(NUCLEUS_DIR)/subsystems/video/video.cpp $(NUCLEUS_DIR)/subsystems/video/video.hpp $(NUCLEUS_DIR)/subsystems/input/input.cpp $(NUCLEUS_DIR)/subsystems/input/input.hpp $(NUCLEUS_DIR)/subsystems/disk/disk.cpp $(NUCLEUS_DIR)/subsystems/disk/disk.hpp $(NUCLEUS_DIR)/subsystems/serial/serial.cpp $(NUCLEUS_DIR)/subsystems/serial/serial.hpp $(NUCLEUS_DIR)/subsystems/filesystem/filesystem.cpp $(NUCLEUS_DIR)/subsystems/filesystem/filesystem.hpp $(NUCLEUS_DIR)/subsystems/boot/boot.cpp $(NUCLEUS_DIR)/subsystems/boot/boot.hpp $(NUCLEUS_DIR)/subsystems/sound/sound.cpp $(NUCLEUS_DIR)/subsystems/sound/sound.hpp $(NUCLEUS_DIR)/subsystems/process/process.cpp $(NUCLEUS_DIR)/subsystems/process/process.hpp 

DRIVER=$(NUCLEUS_DIR)/drivers/video/mda/mda.cpp $(NUCLEUS_DIR)/drivers/video/mda/mda.hpp $(NUCLEUS_DIR)/drivers/video/cga/cga.cpp $(NUCLEUS_DIR)/drivers/video/cga/cga.hpp $(NUCLEUS_DIR)/drivers/video/ega/ega.cpp $(NUCLEUS_DIR)/drivers/video/ega/ega.hpp $(NUCLEUS_DIR)/drivers/video/vga/vga.cpp $(NUCLEUS_DIR)/drivers/video/vga/vga.hpp $(NUCLEUS_DIR)/drivers/filesystem/fat12/fat12.cpp $(NUCLEUS_DIR)/drivers/filesystem/fat12/fat12.hpp $(NUCLEUS_DIR)/drivers/filesystem/fat16/fat16.cpp $(NUCLEUS_DIR)/drivers/filesystem/fat16/fat16.hpp $(NUCLEUS_DIR)/drivers/filesystem/fat32/fat32.cpp $(NUCLEUS_DIR)/drivers/filesystem/fat32/fat32.hpp $(NUCLEUS_DIR)/drivers/filesystem/cdfs/cdfs.cpp $(NUCLEUS_DIR)/drivers/filesystem/cdfs/cdfs.hpp $(NUCLEUS_DIR)/drivers/serial/rs232/rs232.cpp $(NUCLEUS_DIR)/drivers/serial/rs232/rs232.hpp $(NUCLEUS_DIR)/drivers/input/xt_keyboard/xt_keyboard.cpp $(NUCLEUS_DIR)/drivers/input/xt_keyboard/xt_keyboard.hpp $(NUCLEUS_DIR)/drivers/input/at_keyboard/at_keyboard.cpp $(NUCLEUS_DIR)/drivers/input/at_keyboard/at_keyboard.hpp $(NUCLEUS_DIR)/drivers/disk/cd/cd.cpp $(NUCLEUS_DIR)/drivers/disk/cd/cd.hpp $(NUCLEUS_DIR)/drivers/boot/grub2/grub2.cpp $(NUCLEUS_DIR)/drivers/boot/grub2/grub2.hpp $(NUCLEUS_DIR)/drivers/process/elf/elf.cpp $(NUCLEUS_DIR)/drivers/process/elf/elf.hpp $(NUCLEUS_DIR)/drivers/process/zehn/zehn.cpp $(NUCLEUS_DIR)/drivers/process/zehn/zehn.hpp

$(OUTPUT_DIR)/nucleus.img: $(BUILD_DIR)/nucleus.o $(BUILD_DIR)/bootloader.o
:$(LD) $(LD_FLAGS) -o $@ $(BUILD_DIR)/nucleus.o $(BUILD_DIR)/bootloader.o

$(BUILD_DIR)/nucleus.o: $(BUILD_DIR)/current_config.hpp
:$(CPP) $(CPP_FLAGS) -o $@ $(BUILD_DIR)/current_config.hpp $(CORE)

$(BUILD_DIR)/bootloader.o:
:$(AS) $(NUCLEUS_DIR)/drivers/boot/grub2/grub.asm $(AS_FLAGS) -o $@

#Here is the irregular part:
$(BUILD_DIR)/current_config.hpp:
:echo "#define MACHINE PERSONAL_COMPUTER" >> $@
:echo "#define VIDEO_DRIVERS {new MDA_driver, new CGA_driver, new EGA_driver, new VGA_driver}" >> $@
:echo "#define INPUT_DRIVERS {new XT_KEYBOARD_driver, new AT_KEYBOARD_driver}" >> $@
:echo "#define DISK_DRIVERS {new CD_driver}" >> $@
:echo "#define SERIAL_DRIVERS {new RS232_driver}" >> $@
:echo "#define BOOT_DRIVERS {new GRUB2_driver}" >> $@
:echo "#define FILESYSTEM_DRIVERS {new FAT12_driver, new FAT16_driver, new FAT32_driver, new CDFS_driver}" >> $@
:echo "#define SOUND_DRIVERS {}" >> $@
:echo "#define PROCESS_DRIVERS {new ELF_driver, new ZEHN_driver}" >> $@
:echo "#define VIDEO_DRIVER_COUNT 4" >> $@
:echo "#define INPUT_DRIVER_COUNT 2" >> $@
:echo "#define DISK_DRIVER_COUNT 1" >> $@
:echo "#define SERIAL_DRIVER_COUNT 1" >> $@
:echo "#define BOOT_DRIVER_COUNT 1" >> $@
:echo "#define FILESYSTEM_DRIVER_COUNT 4" >> $@
:echo "#define SOUND_DRIVER_COUNT 0" >> $@
:echo "#define PROCESS_DRIVER_COUNT 2" >> $@
