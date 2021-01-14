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
    NEEDED_COMMANDS=(make)
    ;;
dmg)
    NEEDED_COMMANDS=(make)
    ;;
*)
    echo "Choose a system...."
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
cd ./nucleus/
make -f Makefile.$1.mk
cd $CODE_DIR
cd applications

#Now we need to make the system applications
SYSTEM_APPLICATIONS=(cd cpy ctl date del echo info kill lstd lstp lstv math mov osi pi tsh)
for i in "${SYSTEM_APPLICATIONS[@]}"; do
    cd $i
    make -f Makefile.$1.mk
    cd ..
done
