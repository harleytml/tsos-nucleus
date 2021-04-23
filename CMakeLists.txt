cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_C_COMPILER "clang")
set(CMAKE_ASM_COMPILER "clang++")

set(linkerscriptdir ../linkerscripts)

project("TS/OS Nucleus" VERSION 0.0)

enable_language(CXX C ASM)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)

option(PLATFORM "Set the target platform of TS/OS" PC)
message(STATUS "Platform ${PLATFORM}")

if(PLATFORM STREQUAL "PC")
  set(platform_options -D__PERSONAL_COMPUTER__ -mtune=i686 -mno-red-zone -m32
                       --target=i686-pc-none-elf)
  set(linker_script_command -T${linkerscriptdir}/pc.ld)
  file(
    GLOB
    platform_specific_files
    "lib/x86/*"
    "src/pc/*"
    "src/x86/*"
    "startup/pc/*"
    "startup/x86/*")
endif(PLATFORM STREQUAL "PC")

if(PLATFORM STREQUAL "NSPIRE")
  set(platform_options
      -D__NSPIRE__ -mtune=arm926ej-s --target=armv5tej-unknown-none-eabi
      -mgeneral-regs-only -fno-threadsafe-statics)
  set(linker_script_command -T${linkerscriptdir}/nspire.ld)
  file(
    GLOB
    platform_specific_files
    "lib/arm/*"
    "src/nspire/*"
    "src/arm/*"
    "startup/nspire/*"
    "startup/arm/*")
endif(PLATFORM STREQUAL "NSPIRE")

if(PLATFORM STREQUAL "RPI3")
  set(platform_options -D__RASPBERRY_PI_3__ -mtune=cortex-a53
                       --target=aarch64-unknown-none-eabi -mgeneral-regs-only)
  set(linker_script_command -T${linkerscriptdir}/rpi3.ld)
  file(
    GLOB
    platform_specific_files
    "lib/aarch64/*"
    "src/rpi3/*"
    "src/aarch64/*"
    "startup/rpi3/*"
    "startup/aarch64/*")
endif(PLATFORM STREQUAL "RPI3")

if(PLATFORM STREQUAL "CANON-A1100")
  set(platform_options
      -D__CANON_A1100__ -mtune=arm926ej-s --target=armv5tej-unknown-none-eabi
      -mgeneral-regs-only -fno-threadsafe-statics)
  set(linker_script_command -T${linkerscriptdir}/canon-a1100.ld)
  file(
    GLOB
    platform_specific_files
    "lib/arm/*"
    "src/canon-a1100/*"
    "src/arm/*"
    "startup/canon-a1100/*"
    "startup/arm/*")
endif(PLATFORM STREQUAL "CANON-A1100")

if(PLATFORM STREQUAL "CUBIEBOARD1")
  set(platform_options -D__CUBIEBOARD_1__ -mtune=cortex-a8
                       --target=armv7a-unknown-none-eabi -mgeneral-regs-only)
  set(linker_script_command -T${linkerscriptdir}/cubieboard1.ld)
  file(
    GLOB
    platform_specific_files
    "lib/arm/*"
    "src/cubieboard1/*"
    "src/arm/*"
    "startup/cubieboard1/*"
    "startup/arm/*")
endif(PLATFORM STREQUAL "CUBIEBOARD1")

if(PLATFORM STREQUAL "VEXPRESS-A15")
  set(platform_options -D__VEXPRESS_A15__ -mtune=cortex-a15
                       --target=armv7a-unknown-none-eabi -mgeneral-regs-only)
  set(linker_script_command -T${linkerscriptdir}/cubieboard1.ld)
  file(
    GLOB
    platform_specific_files
    "lib/arm/*"
    "src/vexpress-a15/*"
    "src/arm/*"
    "startup/vexpress-a15/*"
    "startup/arm/*")
endif(PLATFORM STREQUAL "VEXPRESS-A15")

include_directories("include")

file(GLOB source_files "src/generic/*" "lib/generic/*")

set(CMAKE_ASM-ATT_FLAGS "${platform-target}")

add_compile_options(
  -Og
  -ggdb
  -Wall
  -Wextra
  -Werror
  -Wabi
  -Wno-unused-private-field
  -Wno-unused-parameter
  -Wno-write-strings
  -Wno-deprecated-copy
  -Wno-unused-variable
  -fno-exceptions
  -fno-builtin
  -fno-rtti
  -fno-unwind-tables
  -nostdlib
  -nodefaultlibs
  -nostdinc++
  -fno-stack-protector
  -fno-strict-aliasing
  -ffunction-sections
  -fdata-sections
  -ffreestanding
  -integrated-as
  -Qunused-arguments
  ${platform_options})

add_link_options(
  -ggdb
  -fuse-ld=lld
  -static
  -nostdlib
  -nodefaultlibs
  -ffunction-sections
  -fdata-sections
  -ffreestanding
  -Qunused-arguments
  ${platform_options}
  ${linker_script_command})

add_executable(nucleus.elf ${source_files} ${platform_specific_files})
