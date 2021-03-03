#!/bin/make -f
# By Tsuki Superior
.RECIPEPREFIX=:

BUILD_DIR:=../build
SRC_DIR:=../src
ASM_DIR:=../asm
INCLUDE_DIR:=../include
CONFIG_DIR:=../config
LINKER_SCRIPTS_DIR:=../linker-scripts

CC:=tsos-i686-gcc
CC_FLAGS:=-D__PERSONAL_COMPUTER__ -g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c99 -ffreestanding -O0 -Wall -Wextra -pedantic -mtune=i686 -mfpmath=387 -m32 -c -fno-builtin

CPP:=tsos-i686-g++
CPP_FLAGS:=-D__PERSONAL_COMPUTER__ -g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c++20 -trigraphs -ffreestanding -O0 -Wall -Wextra -Wno-write-strings  -Wno-write-strings -fno-threadsafe-statics -fno-exceptions -fno-builtin -fno-rtti -fno-unwind-tables -nostdlib -nodefaultlibs -lgcc -pedantic -mtune=i686 -mfpmath=387 -m32 -c

AS:=tsos-i686-as
AS_FLAGS:=-g -mtune=i686 

LD:=tsos-i686-ld.gold
LD_FLAGS:=-g -T $(LINKER_SCRIPTS_DIR)/pc-elf.ld -static -nostartfiles -mtune=i686 -mfpmath=387 -m32 -ffreestanding -O2 -nostdlib

CPP_FILES:=$(wildcard $(SRC_DIR)/generic/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/pc/*.cpp)
OBJ_FILES:=$(patsubst %.cpp, $(BUILD_DIR)/%.o, $(CPP_FILES))

default: $(BUILD_DIR)/nucleus.tse

$(BUILD_DIR)/nucleus.tse: $(ASM_DIR)/pc/grub2.o $(OBJ_FILES)
:$(CPP) $(LD_FLAGS) -o $@ $^ -lgcc 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(ASM_DIR)/pc/grub2.o: $(ASM_DIR)/pc/grub2.S
:$(AS) $(AS_FLAGS) -o $@ -c $^

clean:
:rm -rfv $(shell find ../ -name \*.o) $(shell find ../ -name \*.tse) $(shell find ../ -name \*.iso) $(shell find ../ -name \*.gba) 
