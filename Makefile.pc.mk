#!/bin/make -f
# By Tsuki Superior
.RECIPEPREFIX=:

BUILD_DIR:=$(PWD)/../build
SRC_DIR:=$(PWD)/../src
ASM_DIR:=$(PWD)/../asm
INCLUDE_DIR:=$(PWD)/../include
CONFIG_DIR:=$(PWD)/../config
LINKER_SCRIPTS_DIR:=$(PWD)/../linker-scripts

CC:=tsos-i686-gcc
CC_FLAGS:=-g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c99 -ffreestanding -O3 -Wall -Wextra -pedantic -mtune=i686 -mfpmath=387 -m32

CPP:=tsos-i686-g++
CPP_FLAGS:=-g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c++20 -ffreestanding -O3 -Wall -Wextra -Wno-write-strings -Wno-return-type -Wno-int-to-pointer-cast -Wno-unused-parameter -fno-exceptions -fno-rtti -nostdlib -lgcc -pedantic -mtune=i686 -mfpmath=387 -m32

AS:=tsos-i686-as
AS_FLAGS:=-g -mtune=i686

LD:=tsos-i686-ld.gold
LD_FLAGS:=-g -T $(LINKER_SCRIPTS_DIR)/pc-elf.ld -nostartfiles -mtune=i686 -mfpmath=387 -m32 -ffreestanding -O2 -nostdlib -lgcc

CPP_FILES:=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES:=$(CPP_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/nucleus.tse: $(OBJ_FILES) $(BUILD_DIR)/bootloader.o 
:$(CPP) $(LD_FLAGS) -o $@ $^ 

$(BUILD_DIR)/%.o: $(CPP_FILES)
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/bootloader.o: $(ASM_DIR)/grub2.asm 
:$(AS) $(AS_FLAGS) -o $@ $^

clean:
:rm -rfv $(shell find $(SRC_DIR) -name \*.o)
