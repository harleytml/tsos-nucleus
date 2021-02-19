#!/bin/make -f
# By Tsuki Superior
.RECIPEPREFIX=:

BUILD_DIR=$(PWD)/../build
NUCLEUS_DIR=$(PWD)/../nucleus
CONFIG_DIR=$(PWD)/../config
LINKER_SCRIPTS_DIR=$(PWD)/../linker-scripts

CC=arm-none-eabi-gcc
CC_FLAGS=-g -std=c99 -ffreestanding -O2 -Wall -Wextra -pedantic -mcpu=arm7tdmi -nostartfiles -mthumb-interwork

CPP=arm-none-eabi-g++
CPP_FLAGS=-g -std=c++20 -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -nostdlib -lgcc -pedantic -mcpu=arm7tdmi -nostartfiles -mthumb-interwork -D__is_kernel

AS=arm-none-eabi-as
AS_FLAGS=-mcpu=arm7tdmi -mthumb-interwork

LD=arm-none-eabi-ld.gold
LD_FLAGS=-g -T $(LINKER_SCRIPTS_DIR)/gba-elf.ld -mcpu=arm7tdmi -nostartfiles -mthumb-interwork

$(BUILD_DIR)/nucleus.tse: $(BUILD_DIR)/icxxabi.o $(BUILD_DIR)/bootloader.o $(BUILD_DIR)/core.o $(BUILD_DIR)/video.o $(BUILD_DIR)/input.o $(BUILD_DIR)/disk.o $(BUILD_DIR)/serial.o $(BUILD_DIR)/filesystem.o $(BUILD_DIR)/boot.o $(BUILD_DIR)/sound.o $(BUILD_DIR)/process.o $(BUILD_DIR)/bootloader.o $(BUILD_DIR)/sfs.o $(BUILD_DIR)/grub2.o $(BUILD_DIR)/cd.o $(BUILD_DIR)/udf.o $(BUILD_DIR)/fat12.o $(BUILD_DIR)/fat16.o $(BUILD_DIR)/fat32.o $(BUILD_DIR)/at_keyboard.o $(BUILD_DIR)/xt_keyboard.o $(BUILD_DIR)/elf.o $(BUILD_DIR)/rs232.o $(BUILD_DIR)/cga.o $(BUILD_DIR)/ega.o $(BUILD_DIR)/mda.o $(BUILD_DIR)/vga.o
:$(CPP) $(LD_FLAGS) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/icxxabi.o: $(NUCLEUS_DIR)/core/icxxabi.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/core.o: $(NUCLEUS_DIR)/core/core.cpp $(NUCLEUS_DIR)/core/driver.cpp $(NUCLEUS_DIR)/core/module.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

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


