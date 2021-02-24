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

CPP_FILES=$(shell find $(NUCLEUS_DIR) -name \*.cpp)

$(BUILD_DIR)/nucleus.tse: $(BUILD_DIR)/nucleus.o $(BUILD_DIR)/bootloader.o 
:$(CPP) $(LD_FLAGS) -o $@ $^ 

$(BUILD_DIR)/nucleus.o: $(CPP_FILES)
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/bootloader.o: $(NUCLEUS_DIR)/drivers/boot/gba_boot/gba_boot.asm 
:$(AS) $(AS_FLAGS) -o $@ $^
