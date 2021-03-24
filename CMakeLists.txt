cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++-11")
set(CMAKE_C_COMPILER "/usr/bin/clang-11")
set(CMAKE_ASM-ATT_COMPILER "/usr/bin/clang++-11")

project("TS/OS Nucleus")

enable_language(CXX ASM)
set(CMAKE_CXX_STANDARD 17)

option(PLATFORM "Set the target platform of TS/OS" PC)

if(PLATFORM STREQUAL "PC")
  message(STATUS "Platform ${PLATFORM}")
  set(platform_options -D__PERSONAL_COMPUTER__ --target=i686-pc-none-elf
                       -mtune=i686 -mno-red-zone)
  set(linker_script pc.ld)
  file(GLOB platform_specific_files "src/pc/*.cpp" "startup/pc/*.S" "startup/pc/*.c" "startup/x86/*.S" "startup/x86/*.c")
endif(PLATFORM STREQUAL "PC")

if(PLATFORM STREQUAL "GBA")
  message(STATUS "Platform ${PLATFORM}")
  set(platform_options -D__GAMEBOY_ADVANCED__ --target=armv4t-unknown-none-eabi
                       -mtune=arm7tdmi -mthumb)
  set(linker_script gba.ld)
  file(GLOB platform_specific_files "src/gba/*.cpp" "startup/gba/*.S" "startup/gba/*.c" "startup/arm/*.S" "startup/arm/*.c")
endif(PLATFORM STREQUAL "GBA")

if(PLATFORM STREQUAL "NSPIRE")
  message(STATUS "Platform ${PLATFORM}")
  set(platform_options -D__NSPIRE__ --target=armv5tej-unknown-none-eabi
                       -mtune=arm926ej-s)
  set(linker_script nspire.ld)
  file(GLOB platform_specific_files "src/nspire/*.cpp" "startup/nspire/*.S" "startup/nspire/*.c" "startup/arm/*.S" "startup/arm/*.c")
endif(PLATFORM STREQUAL "NSPIRE")

if(PLATFORM STREQUAL "RPI3")
  message(STATUS "Platform ${PLATFORM}")
  set(platform_options -D__RASPBERRY_PI_3__ --target=aarch64-unknown-none-eabi
                       -mtune=cortex-a53)
  set(linker_script rpi3.ld)
  file(GLOB platform_specific_files "src/rpi3/*.cpp" "startup/rpi3/*.S" "startup/rpi3/*.c" "startup/aarch64/*.S" "startup/aarch64/*.c")
endif(PLATFORM STREQUAL "RPI3")

include_directories(include)

file(GLOB source_files "src/generic/*.cpp")

set(CMAKE_ASM-ATT_FLAGS "${platform_options}")
add_compile_options(
  -g
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
  -nostdlib
  -nodefaultlibs
  -fno-stack-protector
  -fno-strict-aliasing
  ${platform_options})

add_link_options(
  -g
  -T
  ../linker-scripts/${linker_script}
  -fuse-ld=lld
  -static
  -ffreestanding
  -O0
  -nostdlib
  -nodefaultlibs
  ${platform_options})

add_executable(nucleus ${source_files} ${platform_specific_files})
