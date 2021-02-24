#!/bin/make -f
# By Tsuki Superior
.RECIPEPREFIX=:

BUILD_DIR:=$(PWD)/../build
NUCLEUS_DIR:=$(PWD)/../nucleus
CONFIG_DIR:=$(PWD)/../config
LINKER_SCRIPTS_DIR:=$(PWD)/../linker-scripts

CC:=tsos-i686-gcc
CC_FLAGS:=-g -std=c99 -ffreestanding -O3 -Wall -Wextra -pedantic -mtune=i686 -mfpmath=387 -m32

CPP:=tsos-i686-g++
CPP_FLAGS:=-g -std=c++20 -ffreestanding -O3 -Wall -Wextra -Wno-write-strings -Wno-unused-parameter -fno-exceptions -fno-rtti -nostdlib -lgcc -pedantic -mtune=i686 -mfpmath=387 -m32

AS:=tsos-i686-as
AS_FLAGS:=-g -mtune=i686

LD:=tsos-i686-ld.gold
LD_FLAGS:=-g -T $(LINKER_SCRIPTS_DIR)/pc-elf.ld -nostartfiles -mtune=i686 -mfpmath=387 -m32 -ffreestanding -O2 -nostdlib -lgcc

CPP_FILES=$(shell find $(NUCLEUS_DIR) -name \*.cpp)
OBJ_FILES=${CPP_FILES:.cpp=.o}

$(BUILD_DIR)/nucleus.tse: $(OBJ_FILES) $(BUILD_DIR)/bootloader.o 
:$(CPP) $(LD_FLAGS) -o $@ $^ 

$(BUILD_DIR)/%.o: $(CPP_FILES)
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/bootloader.o: $(NUCLEUS_DIR)/drivers/boot/grub2/grub2.asm 
:$(AS) $(AS_FLAGS) -o $@ $^

clean:
:rm -rfv $(shell find $(NUCLEUS_DIR) -name \*.o)
