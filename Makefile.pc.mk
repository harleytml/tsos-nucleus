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
CC_FLAGS:=-g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c99 -ffreestanding -O3 -Wall -Wextra -pedantic -mtune=i686 -mfpmath=387 -m32 -c

CPP:=tsos-i686-g++
CPP_FLAGS:=-g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c++20 -ffreestanding -O3 -Wall -Wextra -Wno-write-strings -Wno-return-type -Wno-int-to-pointer-cast -Wno-unused-parameter -fno-exceptions -fno-rtti -nostdlib -lgcc -pedantic -mtune=i686 -mfpmath=387 -m32 -c

AS:=tsos-i686-as
AS_FLAGS:=-g -mtune=i686

LD:=tsos-i686-ld.gold
LD_FLAGS:=-g -T $(LINKER_SCRIPTS_DIR)/pc-elf.ld -nostartfiles -mtune=i686 -mfpmath=387 -m32 -ffreestanding -O2 -nostdlib -lgcc

CPP_FILES:=$(wildcard $(SRC_DIR)/generic/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/pc/*.cpp)
OBJ_FILES:=$(patsubst %.cpp, $(BUILD_DIR)/%.o, $(CPP_FILES))

default: $(BUILD_DIR)/nucleus.tse

$(BUILD_DIR)/nucleus.tse: $(OBJ_FILES) $(ASM_DIR)/pc/grub2.o 
:$(CPP) $(LD_FLAGS) -o $@ $^ 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(ASM_DIR)/pc/grub2.o: $(ASM_DIR)/pc/grub2.asm 
:$(AS) $(AS_FLAGS) -o $@ -c $^

clean:
:rm -rfv $(shell find ../ -name \*.o)
