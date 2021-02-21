#!/bin/make -f
# By Tsuki Superior
.RECIPEPREFIX=:

BUILD_DIR=$(PWD)/../build
NUCLEUS_DIR=$(PWD)/../nucleus
CONFIG_DIR=$(PWD)/../config
LINKER_SCRIPTS_DIR=$(PWD)/../linker-scripts

BOOT_CORE=$(BUILD_DIR)/boot_driver.o $(BUILD_DIR)/boot_module.o
DISK_CORE=$(BUILD_DIR)/disk_driver.o $(BUILD_DIR)/disk_module.o
FILESYSTEM_CORE=$(BUILD_DIR)/filesystem_driver.o $(BUILD_DIR)/filesystem_module.o $(BUILD_DIR)/filesystem_file.o
INPUT_CORE=$(BUILD_DIR)/input_driver.o $(BUILD_DIR)/input_module.o
PROCESS_CORE=$(BUILD_DIR)/process_driver.o $(BUILD_DIR)/process_module.o
SERIAL_CORE=$(BUILD_DIR)/serial_driver.o $(BUILD_DIR)/serial_module.o
SOUND_CORE=$(BUILD_DIR)/sound_driver.o $(BUILD_DIR)/sound_module.o $(BUILD_DIR)/sound_tone.o 
VIDEO_CORE=$(BUILD_DIR)/video_driver.o $(BUILD_DIR)/video_module.o $(BUILD_DIR)/video_color.o $(BUILD_DIR)/video_font.o
DRIVER_LIST=$(BUILD_DIR)/sfs.o $(BUILD_DIR)/gba_boot.o $(BUILD_DIR)/udf.o $(BUILD_DIR)/fat12.o $(BUILD_DIR)/fat16.o $(BUILD_DIR)/fat32.o $(BUILD_DIR)/gba_gamepad.o $(BUILD_DIR)/elf.o $(BUILD_DIR)/gba_io_port.o $(BUILD_DIR)/gba_screen.o

CC=tsos-armeabi-gcc
CC_FLAGS=-g -std=c99 -ffreestanding -O2 -Wall -Wextra -pedantic -mcpu=arm7tdmi -nostartfiles -mthumb-interwork

CPP=tsos-armeabi-g++
CPP_FLAGS=-g -std=c++20 -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -nostdlib -lgcc -pedantic -mcpu=arm7tdmi -nostartfiles -mthumb-interwork -D__is_kernel

AS=tsos-armeabi-as
AS_FLAGS=-mcpu=arm7tdmi -mthumb-interwork

LD=tsos-armeabi-ld.gold
LD_FLAGS=-g -T $(LINKER_SCRIPTS_DIR)/gba-elf.ld -mcpu=arm7tdmi -nostartfiles -mthumb-interwork -ffreestanding -O2 -nostdlib -lgcc

$(BUILD_DIR)/nucleus.tse:  $(BOOT_CORE) $(DISK_CORE) $(FILESYSTEM_CORE) $(INPUT_CORE) $(PROCESS_CORE) $(SERIAL_CORE) $(SOUND_CORE) $(DRIVER_LIST) $(BUILD_DIR)/icxxabi.o $(BUILD_DIR)/bootloader.o $(BUILD_DIR)/driver.o $(BUILD_DIR)/module.o $(BUILD_DIR)/core.o  $(BUILD_DIR)/bootloader.o
:$(CPP) $(LD_FLAGS) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/icxxabi.o: $(NUCLEUS_DIR)/core/icxxabi.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/core.o: $(NUCLEUS_DIR)/core/core.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/driver.o: $(NUCLEUS_DIR)/core/driver.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/module.o: $(NUCLEUS_DIR)/core/module.cpp
:$(CPP) $(CPP_FLAGS) -o 

$(BUILD_DIR)/video.o: $(NUCLEUS_DIR)/subsystems/video/video_module.cpp $(NUCLEUS_DIR)/subsystems/video/video_driver.cpp $(NUCLEUS_DIR)/subsystems/video/video_color.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^  

$(BUILD_DIR)/input.o: $(NUCLEUS_DIR)/subsystems/input/input_module.cpp $(NUCLEUS_DIR)/subsystems/input/input_driver.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/disk.o: $(NUCLEUS_DIR)/subsystems/disk/disk_module.cpp $(NUCLEUS_DIR)/subsystems/disk/disk_driver.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/serial.o: $(NUCLEUS_DIR)/subsystems/serial/serial_module.cpp $(NUCLEUS_DIR)/subsystems/serial/serial_driver.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/filesystem.o: $(NUCLEUS_DIR)/subsystems/filesystem/filesystem_module.cpp $(NUCLEUS_DIR)/subsystems/filesystem/filesystem_driver.cpp $(NUCLEUS_DIR)/subsystems/filesystem/filesystem_file.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/boot.o: $(NUCLEUS_DIR)/subsystems/boot/boot_module.cpp $(NUCLEUS_DIR)/subsystems/boot/boot_driver.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/sound.o: $(NUCLEUS_DIR)/subsystems/sound/sound_module.cpp $(NUCLEUS_DIR)/subsystems/sound/sound_driver.cpp $(NUCLEUS_DIR)/subsystems/sound/sound_tone.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/process.o: $(NUCLEUS_DIR)/subsystems/process/process_module.cpp $(NUCLEUS_DIR)/subsystems/process/process_driver.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/bootloader.o: $(NUCLEUS_DIR)/drivers/boot/gba_boot/gba_boot.asm 
:$(AS) $(AS_FLAGS) -o $@ $^

$(BUILD_DIR)/gba_boot.o: $(NUCLEUS_DIR)/drivers/boot/gba_boot/gba_boot.cpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

# Driver Modules

$(BUILD_DIR)/cd.o: $(NUCLEUS_DIR)/drivers/disk/cd/cd.cpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/udf.o: $(NUCLEUS_DIR)/drivers/filesystem/udf/udf.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/sfs.o: $(NUCLEUS_DIR)/drivers/filesystem/sfs/sfs.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/fat12.o: $(NUCLEUS_DIR)/drivers/filesystem/fat12/fat12.cpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/fat16.o: $(NUCLEUS_DIR)/drivers/filesystem/fat16/fat16.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/fat32.o: $(NUCLEUS_DIR)/drivers/filesystem/fat32/fat32.cpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/gba_gamepad.o: $(NUCLEUS_DIR)/drivers/input/gba_gamepad/gba_gamepad.cpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/elf.o: $(NUCLEUS_DIR)/drivers/process/elf/elf.cpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/gba_io_port.o: $(NUCLEUS_DIR)/drivers/serial/gba_io_port/gba_io_port.cpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/gba_screen.o: $(NUCLEUS_DIR)/drivers/video/gba_screen/gba_screen.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/gba_cartridge.o: $(NUCLEUS_DIR)/drivers/video/gba_cartridge/gba_cartridge.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

