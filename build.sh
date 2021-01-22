#!/usr/bin/env bash

exists() {
    command -v "$1" >/dev/null 2>&1
}

CODE_DIR=$(pwd)

case $1 in
pc)
    NEEDED_COMMANDS=(i686-elf-gcc i686-elf-g++ i686-elf-ld.gold make)
    ;;
gba)
    NEEDED_COMMANDS=(arm-none-eabi-gcc arm-none-eabi-g++ arm-none-eabi-ld make )
    ;;
dmg)
    NEEDED_COMMANDS=(make)
    ;;
*)
    echo "Choose a valid system...."
    exit 1
    ;;
esac

for i in "${NEEDED_COMMANDS[@]}"; do
    if ! exists $i; then
        echo "Error: $i is not installed."
        exit 1
    fi
done

#Prepare the filesystem root for TS/OS
FILESYSTEM_ROOT=$CODE_DIR/../filesystem
rm -rfv $FILESYSTEM_ROOT
mkdir -pv $FILESYSTEM_ROOT/{bin,cfg,lib,sys,sys/tmp,sys/headers,sys/info,sys/trash,tmp}

#Make the target nucleus
mkdir -pv $CODE_DIR/build/
cd $CODE_DIR/build/
cp ../Makefile.$1 ./Makefile.$1
make -f Makefile.$1


