#!/usr/bin/env python3
# By Tsuki Superior

import sys
import os
import shutil

# You will have to install this one
import termcolor

if os.name != "posix":
    print(termcolor.colored("Only posix systems are supported in this script!", "red"))
    exit(1)

systemlist = ["pc", "gba", "rpi3", "nspire"]

# Make sure the script has the correct number of arguments
if len(sys.argv) != 2 or sys.argv[1] == "help":
    print(sys.argv[0], "<system>")
    print("Set the system to list to see the list if systems")
    exit(1)

# Get the platform
platform = sys.argv[1].lower()

# Get a switch block emulation of the list of systems
if platform == "list":
    print(
        """
    - PC - i686 or higher IBM Personal Computer

    - GBA - Nintendo Gameboy Advanced

    - NSPIRE - Texas Instruments TI-Nspire

    - RPI3 - Raspberry Pi 3
    """
    )
    exit(0)

if platform in systemlist:

    # Create build folder if it doesn't exist
    if not os.path.isdir("build"):
        os.mkdir("build")

    # Change to build dir
    os.chdir("build")

    # Run cmake
    os.system("cmake .. -DPLATFORM="+platform.upper())

    # Run make
    os.system("make -j$(nproc)")

    # Insure that the kernel was produced, and if not, fail
    if not os.path.exists("nucleus"):
        print(termcolor.colored("Compiling failed!", "red"))
        exit(1)

    # Deploy the pc port
    if platform == "pc":

        # Make sure grub-file exists
        if shutil.which("grub-file") == None:
            print(termcolor.colored("grub-file is not installed!", "red"))
            exit(1)

        # Verify that the nucleus produced is actually not malformed
        if os.system("grub-file --is-x86-multiboot nucleus") != 0:
            print(termcolor.colored(
                "The Nucleus is malformed (not x86 multiboot complaint)", "red"))
            exit(1)

    elif platform == "gba":
        if not os.system("llvm-objcopy-11 -O binary nucleus"):
            print(termcolor.colored("objcopy failed on given nucleus image!", "red"))
            exit(1)

        if shutil.which("tsos-gbafix") == None:
            print(termcolor.colored("tsos-gbafix is not installed!", "red"))
            exit(1)

        if not os.system("tsos-gbafix nucleus"):
            print(termcolor.colored("tsos-gbafix failed!", "red"))
            exit(1)

    elif platform == "nspire":
        exit(0)
    elif platform == "rpi3":
        exit(0)

else:

    # You tried to build for the wrong system
    print(termcolor.colored("Invalid system", "red"))
    exit(1)

print(termcolor.colored("Compiling and deploying completed.", "green"))
