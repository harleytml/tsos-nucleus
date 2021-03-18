#!/usr/bin/env make -f
# By Tsuki Superior
.RECIPEPREFIX=:

PLATFORM_OPTIONS:=-mcpu=arm926ej-s

BUILD_DIR:=../build
SRC_DIR:=../src
ASM_DIR:=../asm
INCLUDE_DIR:=../include
CONFIG_DIR:=../config
LINKER_SCRIPTS_DIR:=../linker-scripts
LIB=-lgcc

CC:=tsos-armeabi-gcc
CC_FLAGS:=-D__NSPIRE__ -g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c99 -ffreestanding -fno-builtin -O0 -Wall -Wextra -pedantic -nostartfiles -c $(PLATFORM_OPTIONS)

CPP:=tsos-armeabi-g++
CPP_FLAGS:=-D__NSPIRE__ -g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c++17 -trigraphs -ffreestanding -O0 -Wall -Wextra -Wno-unused-parameter -Wno-write-strings -fno-threadsafe-statics -fno-exceptions -fno-builtin -fno-unwind-tables -fno-rtti -nostdlib -nodefaultlibs -pedantic -nostartfiles -c $(PLATFORM_OPTIONS) 

AS:=tsos-armeabi-as
AS_FLAGS:=-g $(PLATFORM_OPTIONS) 

LD:=tsos-armeabi-ld
LD_FLAGS:=-g -T $(LINKER_SCRIPTS_DIR)/nspire.ld -static -ffreestanding -O0 -nostdlib $(PLATFORM_OPTIONS) 

CPP_FILES:=$(wildcard $(SRC_DIR)/generic/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/nspire/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/armeabi/*.cpp)
ASM_FILES:=$(wildcard $(ASM_DIR)/nspire/*.S)

OBJ_FILES:=$(patsubst %.cpp, $(BUILD_DIR)/%.o, $(CPP_FILES))
OBJ_FILES+=$(patsubst %.S, $(BUILD_DIR)/%.o, $(ASM_FILES))

default: $(BUILD_DIR)/nucleus

$(BUILD_DIR)/nucleus: $(OBJ_FILES)
:$(CPP) $(LD_FLAGS) -o $@ $^ $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
:$(CC) $(CC_FLAGS) -o $@ $^ 

$(BUILD_DIR)/%.o: $(ASM_DIR)/%.S
:$(AS) $(AS_FLAGS) -o $@ -c $^

clean:
:rm -rfv $(shell find ../ -name \*.o) $(BUILD_DIR)/*
