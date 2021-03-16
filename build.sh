#!/usr/bin/env bash
# https://github.com/tsuki-superior/tsos-nucleus/blob/master/documents/TSOS-Ports.md

# Travel to the parent directory
cd "$(basename "$(dirname "$0")")" || exit 1

# This simple function checks if a command exists
exists() {
  command -v "$1" >/dev/null 2>&1
}

# The root dir of the project
CODE_DIR=$(pwd)

# Make sure the required tools are here
case $1 in
help)
  echo "Please choose a system to compile the TS/OS nucleus for."
  echo "Valid systems:"
  echo ""
  echo "pc     - i686 or higher IBM compatible Personal Computer"
  echo "gba    - Nintendo Gameboy Advance"
  echo "psx    - Sony Playstation 1"
  echo "nspire - TI-Nspire"
  exit 0
  ;;
pc)
  NEEDED_COMMANDS=(tsos-i686-gcc tsos-i686-g++ tsos-i686-ld.gold make xorriso grub-mkrescue)
  ;;
gba)
  NEEDED_COMMANDS=(tsos-armeabi-gcc tsos-armeabi-g++ tsos-armeabi-ld.gold make tsos-gbafix)
  ;;
psx)
  NEEDED_COMMANDS=(tsos-mipsel-gcc tsos-mipsel-g++ tsos-mipsel-ld.gold make tsos-elf2x)
  ;;
psp)
  NEEDED_COMMANDS=(tsos-mipsel-gcc tsos-mipsel-g++ tsos-mipsel-ld.gold make)
  echo "This system is not supported yet."
  exit 1
  ;;
nspire)
  NEEDED_COMMANDS=(tsos-armeabi-gcc tsos-armeabi-g++ tsos-armeabi-ld.gold make)
  ;;
rpi3)
  NEEDED_COMMANDS=(tsos-aarch64-gcc tsos-aarch64-g++ tsos-aarch64-ld.gold make)
  echo "This system is not supported yet."
  exit 1
  ;;
nds)
  NEEDED_COMMANDS=(make)
  echo "This system is not supported yet."
  exit 1
  ;;
*)
  echo "Choose a valid system"
  echo "Run $0 help to see the valid systems"
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
mkdir -pv "$FILESYSTEM_ROOT/"{bin,boot,cfg,lib,sys,sys/tmp,sys/headers,sys/info,sys/trash,tmp}

# Make the target nucleus
mkdir -pv "$CODE_DIR/build/"
cd "$CODE_DIR/build/" || exit 1
rm -rfv "$CODE_DIR/build/nucleus*"
cp -v "../makefiles/$1.mk" "./Makefile"
make clean
cp -v "../config/$1.hpp" "./current_config.hpp"
cp -v "../makefiles/$1.mk" "./Makefile"
make -j"$(nproc)"

echo ""

# Lets deploy these images
case $1 in
pc)
  if ! grub-file --is-x86-multiboot "./nucleus"; then
    echo "Compiling failed"
    exit 1
  fi
  cp -v "./nucleus" "$FILESYSTEM_ROOT/nucleus"
  mkdir -pv "$FILESYSTEM_ROOT/boot/grub/"
  cp -v "$CODE_DIR/misc/grub.cfg" "$FILESYSTEM_ROOT/boot/grub/grub.cfg"
  grub-mkrescue -o "./tsos.iso" "$FILESYSTEM_ROOT"
  ;;
gba)
  tsos-armeabi-objcopy -v -O binary "./nucleus" "./tsos.gba"
  tsos-gbafix "./tsos.gba" -t -p
  ;;
psx)
  tsos-elf2x "./nucleus" "./nucleus.psx"
  ;;
*)
  echo "This script cannot deploy this system yet."
  exit 0
  ;;
esac

echo ""

case $2 in
test)
  case $1 in
  pc)
    if ! exists "qemu-system-i386"; then
      echo "Error: qemu is not installed, which is needed for testing and debugging TS/OS"
      exit 1
    fi
    qemu-system-i386 -kernel "./nucleus" -name "TS/OS" -soundhw pcspk -cpu pentium2
    ;;
  gba)
    if ! exists "mgba"; then
      echo "Error: vba is not installed, which is needed for testing and debugging TS/OS on gba"
      exit 1
    fi
    vba "./tsos.gba"
    ;;
  *)
    echo "This script cannot test this system yet"
    exit 0
    ;;

  esac

  ;;
debug)
  case $1 in
  pc)
    if ! exists "qemu-system-i386"; then
      echo "Error: qemu is not installed, which is needed for testing and debugging TS/OS on PC"
      exit 1
    fi
    echo "Set you debugger to localhost:1234 with the nucleus.tse as your executable"
    qemu-system-i386 -kernel "./nucleus" -s -S -name "TS/OS" -soundhw pcspk -cpu pentium2
    ;;
  gba)
    if ! exists "mgba"; then
      echo "Error: mgba is not installed, which is needed for testing and debugging TS/OS on gba"
      exit 1
    fi
    echo "Set you debugger to localhost:1234 with the nucleus.tse as your executable"
    vba --gdb=tcp:1234 --rtc "./tsos.gba"
    ;;
  *)
    echo "This script cannot debug this system yet"
    exit 0
    ;;
  esac
  ;;
esac
