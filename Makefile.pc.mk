#!/usr/bin/env make -f
# By Tsuki Superior
.RECIPEPREFIX=:

PLATFORM_OPTIONS:=-mtune=i686

BUILD_DIR:=../build
SRC_DIR:=../src
ASM_DIR:=../asm
INCLUDE_DIR:=../include
CONFIG_DIR:=../config
LINKER_SCRIPTS_DIR:=../linker-scripts
LIB=-lgcc

CC:=tsos-i686-gcc
CC_FLAGS:=-D__PERSONAL_COMPUTER__ -g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c99 -ffreestanding -fno-builtin -O0 -Wall -Wextra -pedantic -c $(PLATFORM_OPTIONS)

CPP:=tsos-i686-g++
CPP_FLAGS:=-D__PERSONAL_COMPUTER__ -g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c++20 -trigraphs -ffreestanding -O0 -Wall -Wextra -Wno-unused-parameter -Wno-write-strings  -Wno-write-strings -fno-threadsafe-statics -fno-exceptions -fno-builtin -fno-rtti -fno-unwind-tables -nostdlib -nodefaultlibs -pedantic -c $(PLATFORM_OPTIONS)

AS:=tsos-i686-as
AS_FLAGS:=-g $(PLATFORM_OPTIONS)

LD:=tsos-i686-ld.gold
LD_FLAGS:=-g -T $(LINKER_SCRIPTS_DIR)/pc.ld -static -nostartfiles -ffreestanding -O0 -nostdlib $(PLATFORM_OPTIONS)

CPP_FILES:=$(wildcard $(SRC_DIR)/generic/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/pc/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/x86/*.cpp)
OBJ_FILES:=$(patsubst %.cpp, $(BUILD_DIR)/%.o, $(CPP_FILES))

default: $(BUILD_DIR)/nucleus

$(BUILD_DIR)/nucleus: $(ASM_DIR)/pc/grub2.o $(OBJ_FILES)
:$(CPP) $(LD_FLAGS) -o $@ $^ $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(ASM_DIR)/pc/grub2.o: $(ASM_DIR)/pc/grub2.S
:$(AS) $(AS_FLAGS) -o $@ -c $^

clean:
:rm -rfv $(shell find ../ -name \*.o) $(BUILD_DIR)/*
