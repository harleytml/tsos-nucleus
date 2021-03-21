#!/usr/bin/env make -f
# By Tsuki Superior
.RECIPEPREFIX=:

PLATFORM_OPTIONS:=-D__PERSONAL_COMPUTER__ --target=i686-pc-none-elf -march=i686

BUILD_DIR:=../build
SRC_DIR:=../src
ASM_DIR:=../asm
INCLUDE_DIR:=../include
CONFIG_DIR:=../config
LINKER_SCRIPTS_DIR:=../linker-scripts
LIB=

CC:=clang-11
CC_FLAGS:=-g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c99 -ffreestanding -fno-builtin -O0 -Wall -Wextra -pedantic -c $(PLATFORM_OPTIONS)

CPP:=clang++-11
CPP_FLAGS:=-g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c++17 -trigraphs -ffreestanding -O0 -Wall -Wextra -Wno-unused-private-field -Wno-unused-parameter -Wno-write-strings -Wno-write-strings -fno-threadsafe-statics -fno-exceptions -fno-builtin -fno-rtti -fno-unwind-tables -nostdlib -nodefaultlibs -pedantic -c $(PLATFORM_OPTIONS)

AS:=llvm-as-11
AS_FLAGS:=$(PLATFORM_OPTIONS) -c

LD:=ld.lld-11
LD_FLAGS:=-g -T $(LINKER_SCRIPTS_DIR)/pc.ld -fuse-ld=lld -static -ffreestanding -O0 -nostdlib $(PLATFORM_OPTIONS)

CPP_FILES:=$(wildcard $(SRC_DIR)/generic/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/pc/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/x86/*.cpp)
ASM_FILES:=$(wildcard $(ASM_DIR)/pc/*.S)

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
:$(CPP) $(AS_FLAGS) -o $@ $^

clean:
:rm -rfv $(shell find ../ -name \*.o) $(BUILD_DIR)/*
