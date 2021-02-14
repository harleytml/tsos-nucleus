#!/usr/bin/env bash
# https://github.com/tsuki-superior/tsos-nucleus/blob/master/documents/TSOS-Ports.md

# This simple function checks if a command exists
exists() {
    command -v "$1" >/dev/null 2>&1
}

CODE_DIR=$(pwd)

# Make sure the required tools are here
case $1 in
help)
    echo "Please choose a system to compile the TS/OS nucleus for."
    echo "Valid systems:"
    echo ""
    echo "pc  - i686 or higher IBM compatible Personal Computer"
    echo "gba - Nintendo Gameboy Advanced"
    exit 0
    ;;
pc)
    NEEDED_COMMANDS=(i686-elf-gcc i686-elf-g++ i686-elf-ld.gold make)
    ;;
gba)
    NEEDED_COMMANDS=(arm-none-eabi-gcc arm-none-eabi-g++ arm-none-eabi-ld.gold make)
    ;;
psp)
    NEEDED_COMMANDS=(make)
    echo "This system is not supported yet."
    exit 1
    ;;
nspire)
    NEEDED_COMMANDS=(make)
    echo "This system is not supported yet."
    exit 1
    ;;
rpi3)
    NEEDED_COMMANDS=(make)
    echo "This system is not supported yet."
    exit 1
    ;;
pc98)
    NEEDED_COMMANDS=(make)
    echo "This system is not supported yet."
    exit 1
    ;;
pcxt)
    NEEDED_COMMANDS=(make)
    echo "This system is not supported yet."
    exit 1
    ;;
pcat)
    NEEDED_COMMANDS=(make)
    echo "This system is not supported yet."
    exit 1
    ;;
nds)
    NEEDED_COMMANDS=(make)
    echo "This system is not supported yet."
    exit 1
    ;;
psx)
    NEEDED_COMMANDS=(make)
    echo "This system is not supported yet."
    exit 1
    ;;
*)
    echo "Choose a valid system...."
    exit 1
    ;;
esac

for i in "${NEEDED_COMMANDS[@]}"; do
    if ! exists "$i"; then
        echo "Error: $i is not installed."
        exit 1
    fi
done

# Prepare the filesystem root for TS/OS
FILESYSTEM_ROOT="$CODE_DIR/filesystem"
rm -rfv "$FILESYSTEM_ROOT"
mkdir -pv "$FILESYSTEM_ROOT/"{bin,cfg,lib,sys,sys/tmp,sys/headers,sys/info,sys/trash,tmp}

# Make the target nucleus
mkdir -pv "$CODE_DIR/build/"
rm -rfv "$CODE_DIR/build/*"
cd "$CODE_DIR/build/"
cp "../Makefile.$1.mk" "./Makefile"
make -j$(nproc)
