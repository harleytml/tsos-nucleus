#!/bin/make -f
# By Tsuki Superior
.RECIPEPREFIX=:

BUILD_DIR:=../build
SRC_DIR:=../src
ASM_DIR:=../asm
INCLUDE_DIR:=../include
CONFIG_DIR:=../config
LINKER_SCRIPTS_DIR:=../linker-scripts
LIB=-lgcc

CC:=tsos-armeabi-gcc
CC_FLAGS:=-D__GAMEBOY_ADVANCED__ -g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c99 -ffreestanding -O0 -Wall -Wextra -pedantic -mthumb -mcpu=arm7tdmi -nostartfiles -mthumb-interwork -c -fno-builtin

CPP:=tsos-armeabi-g++
CPP_FLAGS:=-D__GAMEBOY_ADVANCED__ -g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c++20 -trigraphs -ffreestanding -O0 -Wall -Wextra -Wno-unused-parameter -Wno-write-strings -fno-threadsafe-statics -fno-exceptions -fno-builtin -fno-unwind-tables -fno-rtti -nostdlib -nodefaultlibs -lgcc -pedantic -mthumb -mcpu=arm7tdmi -nostartfiles -mthumb-interwork -c

AS:=tsos-armeabi-as
AS_FLAGS:=-g -mcpu=arm7tdmi -mthumb-interwork

LD:=tsos-armeabi-ld.gold
LD_FLAGS:=-g -T $(LINKER_SCRIPTS_DIR)/gba-elf.ld -static -mcpu=arm7tdmi -nostartfiles -mthumb-interwork -ffreestanding -O0 -nostdlib

CPP_FILES:=$(wildcard $(SRC_DIR)/generic/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/gba/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/armeabi/*.cpp)
OBJ_FILES:=$(patsubst %.cpp, $(BUILD_DIR)/%.o, $(CPP_FILES))

default: $(BUILD_DIR)/nucleus

$(BUILD_DIR)/nucleus: $(OBJ_FILES) $(ASM_DIR)/gba/gba_boot.o 
:$(CPP) $(LD_FLAGS) -o $@ $^ $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(ASM_DIR)/gba/gba_boot.o: $(ASM_DIR)/gba/gba_boot.S
:$(AS) $(AS_FLAGS) -o $@ -c $^

clean:
:rm -rfv $(shell find ../ -name \*.o) $(shell find ../ -name \*.tse) $(shell find ../ -name \*.iso) $(shell find ../ -name \*.gba) 
