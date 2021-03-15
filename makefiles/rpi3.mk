#!/usr/bin/env make -f
# By Tsuki Superior
.RECIPEPREFIX=:

PLATFORM_OPTIONS:=

BUILD_DIR:=../build
SRC_DIR:=../src
ASM_DIR:=../asm
INCLUDE_DIR:=../include
CONFIG_DIR:=../config
LINKER_SCRIPTS_DIR:=../linker-scripts
LIB=-lgcc

CC:=tsos-aarch64-gcc
CC_FLAGS:=-D__RASPBERRY_PI_3__ -g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c99 -ffreestanding -fno-builtin -O0 -Wall -Wextra -pedantic -nostartfiles -c $(PLATFORM_OPTIONS)

CPP:=tsos-aarch64-g++
CPP_FLAGS:=-D__RASPBERRY_PI_3__ -g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c++20 -trigraphs -ffreestanding -O0 -Wall -Wextra -Wno-unused-parameter -Wno-write-strings -fno-threadsafe-statics -fno-exceptions -fno-builtin -fno-unwind-tables -fno-rtti -nostdlib -nodefaultlibs -pedantic -nostartfiles -c $(PLATFORM_OPTIONS)

AS:=tsos-aarch64-as
AS_FLAGS:=-g $(PLATFORM_OPTIONS)

LD:=tsos-aarch64-ld.gold
LD_FLAGS:=-g -T $(LINKER_SCRIPTS_DIR)/rpi3.ld -static -nostartfiles -ffreestanding -O0 -nostdlib $(PLATFORM_OPTIONS)

CPP_FILES:=$(wildcard $(SRC_DIR)/generic/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/rpi3/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/aarch64/*.cpp)
OBJ_FILES:=$(patsubst %.cpp, $(BUILD_DIR)/%.o, $(CPP_FILES))

default: $(BUILD_DIR)/nucleus

$(BUILD_DIR)/nucleus: $(OBJ_FILES) $(ASM_DIR)/rpi3/rpi3_boot.o
:$(CPP) $(LD_FLAGS) -o $@ $^ $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(ASM_DIR)/rpi3/rpi3_boot.o: $(ASM_DIR)/rpi3/rpi3_boot.S
:$(AS) $(AS_FLAGS) -o $@ -c $^

clean:
:rm -rfv $(shell find ../ -name \*.o) $(BUILD_DIR)/*
