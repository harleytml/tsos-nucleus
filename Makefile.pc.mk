#!/bin/make -f
# By Tsuki Superior
.RECIPEPREFIX=:

BUILD_DIR=$(PWD)/../build
NUCLEUS_DIR=$(PWD)/../nucleus
CONFIG_DIR=$(PWD)/../config
LINKER_SCRIPTS_DIR=$(PWD)/../linker-scripts

CC=i686-elf-gcc
CC_FLAGS=-std=c9x -ffreestanding -O2 -Wall -Wextra -pedantic -mtune=i686 -mfpmath=387 -m32

CPP=i686-elf-g++
CPP_FLAGS=-std=c++20 -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -nostdlib -lgcc -pedantic -mtune=i686 -mfpmath=387 -m32

AS=i686-elf-as
AS_FLAGS=-mtune=i686

LD=i686-elf-ld.gold
LD_FLAGS=-T $(LINKER_SCRIPTS_DIR)/pc-elf.ld -nostartfiles -mtune=i686 -mfpmath=387 -m32

$(BUILD_DIR)/nucleus.tse: $(BUILD_DIR)/bootloader.o $(BUILD_DIR)/core.o $(BUILD_DIR)/video.o $(BUILD_DIR)/input.o $(BUILD_DIR)/disk.o $(BUILD_DIR)/serial.o $(BUILD_DIR)/filesystem.o $(BUILD_DIR)/boot.o $(BUILD_DIR)/sound.o $(BUILD_DIR)/process.o $(BUILD_DIR)/bootloader.o $(BUILD_DIR)/sfs.o $(BUILD_DIR)/grub2.o $(BUILD_DIR)/cd.o $(BUILD_DIR)/udf.o $(BUILD_DIR)/fat12.o $(BUILD_DIR)/fat16.o $(BUILD_DIR)/fat32.o $(BUILD_DIR)/at_keyboard.o $(BUILD_DIR)/xt_keyboard.o $(BUILD_DIR)/elf.o $(BUILD_DIR)/rs232.o $(BUILD_DIR)/cga.o $(BUILD_DIR)/ega.o $(BUILD_DIR)/mda.o $(BUILD_DIR)/vga.o
:$(CPP) $(LD_FLAGS) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/core.o: $(NUCLEUS_DIR)/core/core.cpp $(NUCLEUS_DIR)/core/core.hpp $(NUCLEUS_DIR)/core/driver.cpp $(NUCLEUS_DIR)/core/driver.hpp $(NUCLEUS_DIR)/core/module.cpp $(NUCLEUS_DIR)/core/module.hpp $(BUILD_DIR)/current_config.hpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/video.o: $(NUCLEUS_DIR)/subsystems/video/video.cpp $(NUCLEUS_DIR)/subsystems/video/video.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/input.o: $(NUCLEUS_DIR)/subsystems/input/input.cpp $(NUCLEUS_DIR)/subsystems/input/input.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/disk.o: $(NUCLEUS_DIR)/subsystems/disk/disk.cpp $(NUCLEUS_DIR)/subsystems/disk/disk.hpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/serial.o: $(NUCLEUS_DIR)/subsystems/serial/serial.cpp $(NUCLEUS_DIR)/subsystems/serial/serial.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/filesystem.o: $(NUCLEUS_DIR)/subsystems/filesystem/filesystem.cpp $(NUCLEUS_DIR)/subsystems/filesystem/filesystem.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/boot.o: $(NUCLEUS_DIR)/subsystems/boot/boot.cpp $(NUCLEUS_DIR)/subsystems/boot/boot.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/sound.o: $(NUCLEUS_DIR)/subsystems/sound/sound.cpp $(NUCLEUS_DIR)/subsystems/sound/sound.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/process.o: $(NUCLEUS_DIR)/subsystems/process/process.cpp $(NUCLEUS_DIR)/subsystems/process/process.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/bootloader.o: $(NUCLEUS_DIR)/drivers/boot/grub2/grub2.asm 
:$(AS) $(AS_FLAGS) -o $@ $^

$(BUILD_DIR)/grub2.o: $(NUCLEUS_DIR)/drivers/boot/grub2/grub2.cpp $(NUCLEUS_DIR)/drivers/boot/grub2/grub2.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/cd.o: $(NUCLEUS_DIR)/drivers/disk/cd/cd.cpp $(NUCLEUS_DIR)/drivers/disk/cd/cd.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/udf.o: $(NUCLEUS_DIR)/drivers/filesystem/udf/udf.cpp $(NUCLEUS_DIR)/drivers/filesystem/udf/udf.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/sfs.o: $(NUCLEUS_DIR)/drivers/filesystem/sfs/sfs.cpp $(NUCLEUS_DIR)/drivers/filesystem/sfs/sfs.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/fat12.o: $(NUCLEUS_DIR)/drivers/filesystem/fat12/fat12.cpp $(NUCLEUS_DIR)/drivers/filesystem/fat12/fat12.hpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/fat16.o: $(NUCLEUS_DIR)/drivers/filesystem/fat16/fat16.cpp $(NUCLEUS_DIR)/drivers/filesystem/fat16/fat16.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/fat32.o: $(NUCLEUS_DIR)/drivers/filesystem/fat32/fat32.cpp $(NUCLEUS_DIR)/drivers/filesystem/fat32/fat32.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/at_keyboard.o: $(NUCLEUS_DIR)/drivers/input/at_keyboard/at_keyboard.cpp $(NUCLEUS_DIR)/drivers/input/at_keyboard/at_keyboard.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/xt_keyboard.o: $(NUCLEUS_DIR)/drivers/input/xt_keyboard/xt_keyboard.cpp $(NUCLEUS_DIR)/drivers/input/xt_keyboard/xt_keyboard.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/elf.o: $(NUCLEUS_DIR)/drivers/process/elf/elf.cpp $(NUCLEUS_DIR)/drivers/process/elf/elf.hpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/rs232.o: $(NUCLEUS_DIR)/drivers/serial/rs232/rs232.cpp $(NUCLEUS_DIR)/drivers/serial/rs232/rs232.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/cga.o: $(NUCLEUS_DIR)/drivers/video/cga/cga.cpp $(NUCLEUS_DIR)/drivers/video/cga/cga.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/ega.o: $(NUCLEUS_DIR)/drivers/video/ega/ega.cpp $(NUCLEUS_DIR)/drivers/video/ega/ega.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/mda.o: $(NUCLEUS_DIR)/drivers/video/mda/mda.cpp $(NUCLEUS_DIR)/drivers/video/mda/mda.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/vga.o: $(NUCLEUS_DIR)/drivers/video/vga/vga.cpp $(NUCLEUS_DIR)/drivers/video/vga/vga.hpp 
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/current_config.hpp: $(CONFIG_DIR)/pc.hpp
:cp -v $^ $@


