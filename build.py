#!/usr/bin/env python3
# By Tsuki Superior

import sys
import os
import shutil
import termcolor

systemlist = ["pc", "gba", "rpi3", "nspire"]

# Make sure the script has the correct number of arguments
if len(sys.argv) != 2:
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

        # Grub file can only exist on a posix system anyway
        if os.name == "posix":

            # Make sure grub-file exists
            if shutil.which("grub-file") == None:
                print(termcolor.colored("grub-file is not installed!", "red"))
                exit(1)

            # Verify that the nucleus produced is actually not malformed
            if os.system("grub-file --is-x86-multiboot nucleus") != 0:
                print(termcolor.colored(
                    "The Nucleus is malformed (not x86 multiboot complaint)", "red"))
                exit(1)
        else:

            # I don't know how to do this on a non-posix system
            print(termcolor.colored(
                "Build script is not supporting the host system", "red"), os.name)
else:

    # You tried to build for the wrong system
    print(termcolor.colored("Invalid system", "red"))
    exit(1)
