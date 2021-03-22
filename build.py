#!/usr/bin/env python3
# By Tsuki Superior

import sys
import os

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
    """)
    exit(0)

if platform in systemlist:
    if not os.path.isdir("build"):
        os.mkdir("build")
    os.chdir("build")
    os.system("cmake .. -DPLATFORM="+platform.upper())
    os.system("make -j$(nproc)")
    if not os.path.exists("nucleus"):
        exit(1)
    if platform == "pc":
        if os.name == "posix":
            if os.system("grub-file --is-x86-multiboot nucleus") == 0:
                exit(0)
            else:
                print("The Nucleus is malformed (not x86 multiboot complaint)")
                exit(1)
        else:
            print("Build script is not supporting the target", os.name)
else:
    print("Invalid system")
    exit(1)
