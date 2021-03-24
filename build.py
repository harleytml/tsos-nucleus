#!/usr/bin/env python3
# By Tsuki Superior

import sys
import os
import shutil

# You will have to install this one
import termcolor

# This only works on unix like systems right now
if os.name != "posix":
    print(termcolor.colored("Only posix systems are supported in this script!", "red"))
    exit(1)

# You must install cmake to use this
if shutil.which("cmake") == None:
    print(termcolor.colored("cmake is not installed!", "red"))
    exit(1)

systemlist = ["pc", "gba", "rpi3", "nspire"]

# Make sure the script has the correct number of arguments, and if not, display help
if not(len(sys.argv) == 2 or len(sys.argv) == 3) or sys.argv[1] == "help":
    print(sys.argv[0], "<system> <action>")
    print("Supported systems:")
    print(
        """
    - pc - i686 or higher IBM Personal Computer

    - gba - Nintendo Gameboy Advanced

    - nspire - Texas Instruments TI-Nspire

    - rpi3 - Raspberry Pi 3
    """
    )
    print("Set the action to either", termcolor.colored(
        "debug", "yellow"), "or", termcolor.colored("test", "yellow"))
    exit(0)

# Get the platform
platform = sys.argv[1].lower()
if len(sys.argv) > 2:
    extra_action = sys.argv[2].lower()
else:
    extra_action = ""

if platform in systemlist:

    # Create build folder if it doesn't exist
    if not os.path.isdir("build"):
        os.mkdir("build")

    # Change to build dir
    os.chdir("build")

    if os.path.exists("nucleus"):
        os.remove("nucleus")

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

    # The user wants to deploy the gba system
    elif platform == "gba":

        if shutil.which("llvm-objcopy-11") == None:
            print(termcolor.colored("llvm-objcopy-11 is not installed!", "red"))
            exit(1)

        if os.system("llvm-objcopy-11 -O binary nucleus") != 0:
            print(termcolor.colored("objcopy failed on given nucleus image!", "red"))
            exit(1)

        # Make sure gba fix is installed
        if shutil.which("tsos-gbafix") == None:
            print(termcolor.colored("tsos-gbafix is not installed!", "red"))
            exit(1)

        # Fix the gba rom
        if os.system("tsos-gbafix nucleus") != 0:
            print(termcolor.colored("tsos-gbafix failed!", "red"))
            exit(1)

    # Target the nspire
    elif platform == "nspire":
        if shutil.which("llvm-objcopy-11") == None:
            print(termcolor.colored("llvm-objcopy-11 is not installed!", "red"))
            exit(1)

        if os.system("llvm-objcopy-11 -O binary nucleus") != 0:
            print(termcolor.colored("objcopy failed on given nucleus image!", "red"))
            exit(1)

    elif platform == "rpi3":
        if shutil.which("llvm-objcopy-11") == None:
            print(termcolor.colored("llvm-objcopy-11 is not installed!", "red"))
            exit(1)

        if os.system("llvm-objcopy-11 -O binary nucleus") != 0:
            print(termcolor.colored("objcopy failed on given nucleus image!", "red"))
            exit(1)

else:

    # You tried to build for the wrong system
    print(termcolor.colored("Invalid system", "red"))
    exit(1)

# Building was succesful if it made it to here
print(termcolor.colored("Compiling and deploying completed.", "green"))
print(termcolor.colored("Your copy of the TS/OS nucleus is at build/nucleus", "green"))

# Meaning that the user didn't want any other action
if extra_action == "":
    exit(0)

# Test the deployed system
if extra_action == "test":

    # Debug the pc system
    if platform == "pc":
        if shutil.which("qemu-system-i386") == None:
            print(termcolor.colored("qemu-system-i386 is not installed!", "red"))
            exit(1)
        os.system("qemu-system-i386 -kernel nucleus")
        exit(0)

    if platform == "rpi3":
        if shutil.which("qemu-system-aarch64") == None:
            print(termcolor.colored("qemu-system-aarch64 is not installed!", "red"))
            exit(1)
        os.system("qemu-system-aarch64 -M raspi3 -kernel nucleus")
        exit(0)

    else:
        print(termcolor.colored(
            "Cannot test this system with this script yet.", "yellow"))
        exit(0)

# Debug the deployed system
elif extra_action == "debug":

    # Debug the pc system
    if platform == "pc":
        if shutil.which("qemu-system-i386") == None:
            print(termcolor.colored("qemu-system-i386 is not installed!", "red"))
            exit(1)
        os.system("qemu-system-i386 -kernel nucleus -s -S")
        exit(0)

    # Debug the rpi3 system
    elif platform == "rpi3":
        if shutil.which("qemu-system-aarch64") == None:
            print(termcolor.colored("qemu-system-aarch64 is not installed!", "red"))
            exit(1)
        os.system("qemu-system-aarch64 -M raspi3 -kernel nucleus -s -S")
        exit(0)

    else:
        print(termcolor.colored(
            "Cannot test this system with this script yet.", "yellow"))
        exit(0)
else:
    print(termcolor.colored("Invalid action", "red"))
