#!/bin/make -f
#By Tsuki Superior
.RECIPEPREFIX=:

BUILD_DIR=$(PWD)/../build
KERNEL_DIR=$(PWD)/../kernel
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

CORE=$(KERNEL_DIR)/core/core.cpp $(KERNEL_DIR)/core/core.hpp $(KERNEL_DIR)/subsystems/video/video.cpp $(KERNEL_DIR)/subsystems/video/video.hpp $(KERNEL_DIR)/subsystems/input/input.cpp $(KERNEL_DIR)/subsystems/input/input.hpp $(KERNEL_DIR)/subsystems/disk/disk.cpp $(KERNEL_DIR)/subsystems/disk/disk.hpp $(KERNEL_DIR)/subsystems/serial/serial.cpp $(KERNEL_DIR)/subsystems/serial/serial.hpp $(KERNEL_DIR)/subsystems/filesystem/filesystem.cpp $(KERNEL_DIR)/subsystems/filesystem/filesystem.hpp $(KERNEL_DIR)/subsystems/boot/boot.cpp $(KERNEL_DIR)/subsystems/boot/boot.hpp $(KERNEL_DIR)/subsystems/sound/sound.cpp $(KERNEL_DIR)/subsystems/sound/sound.hpp $(NUCLEUS_DIR)/subsystems/process/process.cpp $(NUCLEUS_DIR)/subsystems/process/process.hpp 

DRIVER=$(KERNEL_DIR)/drivers/video/dmg_screen/dmg_screen.cpp $(KERNEL_DIR)/drivers/video/dmg_screen/dmg_screen.hpp $(KERNEL_DIR)/drivers/filesystem/fat12/fat12.cpp $(KERNEL_DIR)/drivers/filesystem/fat12/fat12.hpp $(KERNEL_DIR)/drivers/filesystem/fat16/fat16.cpp $(KERNEL_DIR)/drivers/filesystem/fat16/fat16.hpp $(KERNEL_DIR)/drivers/filesystem/fat32/fat32.cpp $(KERNEL_DIR)/drivers/filesystem/fat32/fat32.hpp $(KERNEL_DIR)/drivers/serial/dmg_io_port/dmg_io_port.cpp $(KERNEL_DIR)/drivers/serial/dmg_io_port/dmg_io_port.hpp $(KERNEL_DIR)/drivers/input/dmg_gamepad/dmg_gamepad.cpp $(KERNEL_DIR)/drivers/input/dmg_gamepad/dmg_gamepad.hpp $(KERNEL_DIR)/drivers/disk/dmg_cartridge/dmg_cartridge.cpp $(KERNEL_DIR)/drivers/disk/dmg_cartridge/dmg_cartridge.hpp $(KERNEL_DIR)/drivers/boot/dmg_boot/dmg_boot.cpp $(KERNEL_DIR)/drivers/boot/dmg_boot/dmg_boot.hpp $(NUCLEUS_DIR)/drivers/process/elf/elf.cpp $(NUCLEUS_DIR)/drivers/process/elf/elf.hpp $(NUCLEUS_DIR)/drivers/process/zehn/zehn.cpp $(NUCLEUS_DIR)/drivers/process/zehn/zehn.hpp

$(OUTPUT_DIR)/nucleus.tse: $(BUILD_DIR)/nucleus.o $(BUILD_DIR)/bootloader.o
:$(CC) $(CPP_FLAGS) -T elf-linker.ld -o $@ $(BUILD_DIR)/bootloader.o $(BUILD_DIR)/nucleus.o

$(BUILD_DIR)/nucleus.o: $(BUILD_DIR)/current_config.hpp
:$(CPP) $(CPP_FLAGS) -o $@ $(BUILD_DIR)/current_config.hpp $(CORE)

$(BUILD_DIR)/bootloader.o:
:$(AS) $(KERNEL_DIR)/drivers/boot/dmg_boot/dmg_boot.asm $(AS_FLAGS) -o $@

#Here is the irregular part:
$(BUILD_DIR)/current_config.hpp:
:echo "#define MACHINE DOT_MATRIX_GAME" >> $@
:echo "#define VIDEO_DRIVERS { DMG_SCREEN_driver()}" >> $@
:echo "#define INPUT_DRIVERS { DMG_GAMEPAD_driver()}" >> $@
:echo "#define DISK_DRIVERS { DMG_CARTRIDGE_driver()}" >> $@
:echo "#define SERIAL_DRIVERS { DMG_IO_PORT_driver()}" >> $@
:echo "#define BOOT_DRIVERS { DMG_BOOT_driver()}" >> $@
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
:echo "#define PROCESS_DRIVER_COUNT 2" >> $@
