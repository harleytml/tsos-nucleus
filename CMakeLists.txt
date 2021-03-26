cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(CMAKE_CXX_COMPILER "/usr/tsos-toolchain/bin/clang++")
set(CMAKE_C_COMPILER "/usr/tsos-toolchain/bin/clang")
set(CMAKE_ASM_COMPILER "/usr/tsos-toolchain/bin/clang++")

project("TS/OS Nucleus" VERSION 0.0)

enable_language(CXX ASM C)
set(CMAKE_CXX_STANDARD 11)

option(PLATFORM "Set the target platform of TS/OS" PC)

if(PLATFORM STREQUAL "PC")
  message(STATUS "Platform ${PLATFORM}")
  set(platform_options -D__PERSONAL_COMPUTER__ -mtune=i686 -mno-red-zone
                       --target=i686-pc-none-elf -mcmodel=kernel)
  set(linker_script pc.ld)
  include_directories("include/pc")
  file(GLOB platform_specific_files "src/pc/*" "src/x86/*" "startup/pc/*"
       "startup/x86/*")
endif(PLATFORM STREQUAL "PC")

if(PLATFORM STREQUAL "GBA")
  message(STATUS "Platform ${PLATFORM}")
  set(platform_options -D__GAMEBOY_ADVANCED__ -mtune=arm7tdmi -mthumb
                       --target=armv4t-unknown-none-eabi)
  set(linker_script gba.ld)
  include_directories("include/gba")
  file(GLOB platform_specific_files "src/gba/*" "src/arm/*" "startup/gba/*"
       "startup/arm/*")
endif(PLATFORM STREQUAL "GBA")

if(PLATFORM STREQUAL "NSPIRE")
  message(STATUS "Platform ${PLATFORM}")
  set(platform_options -D__NSPIRE__ -mtune=arm926ej-s
                       --target=armv5tej-unknown-none-eabi)
  set(linker_script nspire.ld)
  include_directories("include/nspire")
  file(GLOB platform_specific_files "src/nspire/*" "src/arm/*"
       "startup/nspire/*" "startup/arm/*")
endif(PLATFORM STREQUAL "NSPIRE")

if(PLATFORM STREQUAL "RPI3")
  message(STATUS "Platform ${PLATFORM}")
  set(platform_options -D__RASPBERRY_PI_3__ -mtune=cortex-a53
                       --target=aarch64-unknown-none-eabi)
  set(linker_script rpi3.ld)
  include_directories("include/rpi3")
  file(GLOB platform_specific_files "src/rpi3/*" "src/aarch64/*"
       "startup/rpi3/*" "startup/aarch64/*")
endif(PLATFORM STREQUAL "RPI3")

include_directories("include/generic")

file(GLOB source_files "src/generic/*")

set(CMAKE_ASM-ATT_FLAGS "${platform-target}")
add_compile_options(
  -ggdb
  -ffreestanding
  -Og
  -Wall
  -Wextra
  -Wno-unused-private-field
  -Wno-unused-parameter
  -Wno-write-strings
  -Wno-unused-command-line-argument
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
  -ggdb
  -Og
  -T
  ../linker-scripts/${linker_script}
  -fuse-ld=lld
  -static
  -ffreestanding
  -nostdlib
  -nodefaultlibs
  ${platform_options})

add_executable(nucleus ${source_files} ${platform_specific_files})
