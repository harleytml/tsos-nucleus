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

CC:=tsos-mipsel-gcc
CC_FLAGS:=-D__PLAYSTATON_X__ -g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c99 -ffreestanding -O0 -Wall -Wextra -pedantic -nostartfiles -c -fno-builtin -march=r3000

CPP:=tsos-mipsel-g++
CPP_FLAGS:=-D__PLAYSTATON_X__ -g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c++20 -trigraphs -ffreestanding -O0 -Wall -Wextra -Wno-write-strings -fno-threadsafe-statics -fno-exceptions -fno-builtin -fno-unwind-tables -fno-rtti -nostdlib -nodefaultlibs -lgcc -pedantic -nostartfiles -c -march=r3000 

AS:=tsos-mipsel-as
AS_FLAGS:=-g -march=r3000

LD:=tsos-mipsel-ld.gold
LD_FLAGS:=-g -T $(LINKER_SCRIPTS_DIR)/psx-elf.ld -static -nostartfiles -ffreestanding -O0 -nostdlib -march=r3000

CPP_FILES:=$(wildcard $(SRC_DIR)/generic/*.cpp)
OBJ_FILES:=$(patsubst %.cpp, $(BUILD_DIR)/%.o, $(CPP_FILES))

default: $(BUILD_DIR)/nucleus.tse

$(BUILD_DIR)/nucleus.tse: $(OBJ_FILES)
:$(CPP) $(LD_FLAGS) -o $@ $^ $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

clean:
:rm -rfv $(shell find ../ -name \*.o) $(shell find ../ -name \*.tse) $(shell find ../ -name \*.iso) $(shell find ../ -name \*.gba) 
