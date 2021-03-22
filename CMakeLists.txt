cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++-11")
set(CMAKE_C_COMPILER "/usr/bin/clang-11")
set(CMAKE_ASM-ATT_COMPILER "/usr/bin/clang++-11")

project("TS/OS Nucleus")

enable_language(CXX ASM)

option(PLATFORM "Set the target platform of TS/OS" PC)

if(PLATFORM STREQUAL "PC")
  message(STATUS "Platform ${PLATFORM}")
  set(platform_options -D__PERSONAL_COMPUTER__ --target=i686-pc-none-elf
                       -march=i686)
  set(linker_script pc.ld)
  file(GLOB platform_specific_files "src/pc/*.cpp" "asm/pc/*.S")
endif(PLATFORM STREQUAL "PC")

if(PLATFORM STREQUAL "GBA")
  message(STATUS "Platform ${PLATFORM}")
  set(platform_options -D__GAMEBOY_ADVANCED__ --target=armv4t-unknown-none-eabi
                       -mcpu=arm7tdmi -mthumb)
  set(linker_script gba.ld)
  file(GLOB platform_specific_files "src/gba/*.cpp" "asm/gba/*.S")
endif(PLATFORM STREQUAL "GBA")

if(PLATFORM STREQUAL "NSPIRE")
  message(STATUS "Platform ${PLATFORM}")
  set(platform_options -D__NSPIRE__ --target=armv5tej-unknown-none-eabi
                       -mcpu=arm926ej-s)
  set(linker_script nspire.ld)
  file(GLOB platform_specific_files "src/nspire/*.cpp" "asm/nspire/*.S")
endif(PLATFORM STREQUAL "NSPIRE")

if(PLATFORM STREQUAL "RPI3")
  message(STATUS "Platform ${PLATFORM}")
  set(platform_options -D__RASPBERRY_PI_3__ --target=aarch64-unknown-none-eabi)
  set(linker_script rpi3.ld)
  file(GLOB platform_specific_files "src/rpi3/*.cpp" "asm/rpi3/*.S")
endif(PLATFORM STREQUAL "RPI3")

include_directories(include)

set(CMAKE_CXX_STANDARD 17)
file(GLOB source_files "src/generic/*.cpp")

set(CMAKE_ASM-ATT_FLAGS "${platform_options}")
add_compile_options(
  -trigraphs
  -ffreestanding
  -O0
  -Wall
  -Wextra
  -Wno-unused-private-field
  -Wno-unused-parameter
  -Wno-write-strings
  -Wno-write-strings
  -fno-threadsafe-statics
  -fno-exceptions
  -fno-builtin
  -fno-rtti
  -fno-unwind-tables
  -ffunction-sections
  -nostdlib
  -nodefaultlibs
  ${platform_options})

add_link_options(
  -T
  ../linker-scripts/${linker_script}
  -fuse-ld=lld
  -static
  -ffreestanding
  -O0
  -nostdlib
  ${platform_options})

add_executable(nucleus ${source_files} ${platform_specific_files})
