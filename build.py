#!/usr/bin/env python3
# By Tsuki Superior

import sys
import os

systemlist = ["pc", "gba", "rpi3", "nspire"]

# Make sure the script has the correct number of arguments
if len(sys.argv) != 2:
    print(sys.argv[0], "<system>")
    print("Set the system to list to see the list if systems")

# Get the platform
platform = sys.argv[1]

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

if platform.lower() in systemlist:
    os.chdir("./build")
    os.system("cmake .. -DPLATFORM="+platform.upper())
    os.system("make -j$(nproc)")
