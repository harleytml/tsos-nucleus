#!/bin/make -f
#By Tsuki Superior
.RECIPEPREFIX=:

BUILD_DIR=$(PWD)/../build
NUCLEUS_DIR=$(PWD)/../nucleus
FILESYSTEM_DIR=$(PWD)/../filesystem
LIBRARY_DIR=$(PWD)/../libraries
TOOLCHAIN_DIR=$(PWD)/../toolchain

CC=$(where )
CC_FLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra

CPP=$(where )
CPP_FLAGS=-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti

AS=$(where )
AS_FLAGS=

LD=$(where )
LD_FLAGS=

CORE=$(NUCLEUS_DIR)/core/core.cpp $(NUCLEUS_DIR)/core/core.hpp $(NUCLEUS_DIR)/subsystems/video/video.cpp $(NUCLEUS_DIR)/subsystems/video/video.hpp $(NUCLEUS_DIR)/subsystems/input/input.cpp $(NUCLEUS_DIR)/subsystems/input/input.hpp $(NUCLEUS_DIR)/subsystems/disk/disk.cpp $(NUCLEUS_DIR)/subsystems/disk/disk.hpp $(NUCLEUS_DIR)/subsystems/serial/serial.cpp $(NUCLEUS_DIR)/subsystems/serial/serial.hpp $(NUCLEUS_DIR)/subsystems/filesystem/filesystem.cpp $(NUCLEUS_DIR)/subsystems/filesystem/filesystem.hpp $(NUCLEUS_DIR)/subsystems/boot/boot.cpp $(NUCLEUS_DIR)/subsystems/boot/boot.hpp $(NUCLEUS_DIR)/subsystems/sound/sound.cpp $(NUCLEUS_DIR)/subsystems/sound/sound.hpp 

DRIVER=$(NUCLEUS_DIR)/drivers/video/gba_screen/gba_screen.cpp $(NUCLEUS_DIR)/drivers/video/gba_screen/gba_screen.hpp $(NUCLEUS_DIR)/drivers/filesystem/fat12/fat12.cpp $(NUCLEUS_DIR)/drivers/filesystem/fat12/fat12.hpp $(NUCLEUS_DIR)/drivers/filesystem/fat16/fat16.cpp $(NUCLEUS_DIR)/drivers/filesystem/fat16/fat16.hpp $(NUCLEUS_DIR)/drivers/filesystem/fat32/fat32.cpp $(NUCLEUS_DIR)/drivers/filesystem/fat32/fat32.hpp $(NUCLEUS_DIR)/drivers/serial/gba_io_port/gba_io_port.cpp $(NUCLEUS_DIR)/drivers/serial/gba_io_port/gba_io_port.hpp $(NUCLEUS_DIR)/drivers/input/gba_gamepad/gba_gamepad.cpp $(NUCLEUS_DIR)/drivers/input/gba_gamepad/gba_gamepad.hpp $(NUCLEUS_DIR)/drivers/disk/gba_cartridge/gba_cartridge.cpp $(NUCLEUS_DIR)/drivers/disk/gba_cartridge/gba_cartridge.hpp $(NUCLEUS_DIR)/drivers/boot/gba_boot/gba_boot.cpp $(NUCLEUS_DIR)/drivers/boot/gba_boot/gba_boot.hpp $(NUCLEUS_DIR)/drivers/process/elf/elf.cpp $(NUCLEUS_DIR)/drivers/process/elf/elf.hpp $(NUCLEUS_DIR)/drivers/process/zehn/zehn.cpp $(NUCLEUS_DIR)/drivers/process/zehn/zehn.hpp

$(OUTPUT_DIR)/nucleus.img: $(BUILD_DIR)/nucleus.o $(BUILD_DIR)/bootloader.o
:$(LD) $(LD_FLAGS) -o $@ $(BUILD_DIR)/nucleus.o $(BUILD_DIR)/bootloader.o

$(BUILD_DIR)/nucleus.o: $(BUILD_DIR)/current_config.hpp
:$(CPP) $(CPP_FLAGS) -o $@ $(BUILD_DIR)/current_config.hpp $(CORE)

$(BUILD_DIR)/bootloader.o:
:$(AS) $(NUCLEUS_DIR)/drivers/boot/gba_boot/gba_boot.asm $(AS_FLAGS) -o $@

#Here is the irregular part:
$(BUILD_DIR)/current_config.hpp:
:echo "#define MACHINE GAMEBOY_ADVANCED" >> $@
:echo "#define VIDEO_DRIVERS { GBA_SCREEN_driver()}" >> $@
:echo "#define INPUT_DRIVERS { GBA_GAMEPAD_driver()}" >> $@
:echo "#define DISK_DRIVERS { GBA_CARTRIDGE_driver()}" >> $@
:echo "#define SERIAL_DRIVERS { GBA_IO_PORT_driver()}" >> $@
:echo "#define BOOT_DRIVERS { GBA_BOOT_driver()}" >> $@
:echo "#define FILESYSTEM_DRIVERS { FAT12_driver(),  FAT16_driver(),  FAT32_driver(),  CDFS_driver()}" >> $@
:echo "#define SOUND_DRIVERS {}" >> $@
:echo "#define PROCESS_DRIVERS { ELF_driver(),  ZEHN_driver()}" >> $@
:echo "#define VIDEO_DRIVER_COUNT 1" >> $@
:echo "#define INPUT_DRIVER_COUNT 1" >> $@
:echo "#define DISK_DRIVER_COUNT 1" >> $@
:echo "#define SERIAL_DRIVER_COUNT 1" >> $@
:echo "#define BOOT_DRIVER_COUNT 1" >> $@
:echo "#define FILESYSTEM_DRIVER_COUNT 4" >> $@
:echo "#define SOUND_DRIVER_COUNT 0" >> $@
