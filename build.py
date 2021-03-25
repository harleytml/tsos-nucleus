#!/usr/bin/env python3
# By Tsuki Superior

from termcolor import cprint
import sys
import os
import shutil
import json

# Open that config file and read from it
build_settings_file = open("cfg/build.json")
build_settings = json.loads(build_settings_file.read())
build_settings_file.close()

# Make sure the most important part is there
if not "systems" in build_settings:
    cprint("Malformed build file!")
    exit(1)

# This only works on unix like systems right now
if os.name != "posix":
    cprint("Only posix systems are supported in this script!", "red")
    exit(1)

# You must install cmake to use this
if shutil.which("cmake") == None:
    cprint("cmake is not installed!", "red")
    exit(1)

# Make sure the script has the correct number of arguments, and if not, display help
if not(len(sys.argv) == 2 or len(sys.argv) == 3) or sys.argv[1] == "help":
    cprint("Official TS/OS buildscript (C) Tsuki Superior. Licensed under the same as TS/OS (see LICENSE file)\n", "yellow")
    print(sys.argv[0], "<system> <action>")
    print("Supported systems:\n")

    for x in build_settings["systems"]:
        print(x, "-", build_settings["systems"][x]["description"])
    cprint("\nSet the action to either debug or test, or you can leave it blank", "yellow")
    exit(0)

# Get the platform
platform = sys.argv[1].lower()
if len(sys.argv) > 2:
    action = sys.argv[2].lower()
else:
    action = ""

if platform in build_settings["systems"]:

    # Create build folder if it doesn't exist
    if not os.path.isdir("build"):
        os.mkdir("build")

    # Change to build dir
    os.chdir("build")

    if os.path.exists("nucleus"):
        os.remove("nucleus")

    # Run cmake
    os.system("cmake .. -DPLATFORM=" + platform.upper())

    # Run make
    os.system("make -j$(nproc)")

    # Insure that the kernel was produced, and if not, fail
    if not os.path.exists("nucleus"):
        cprint("Compiling failed!", "red")
        exit(1)

    # Deploy the pc port
    if platform == "pc":

        # Make sure grub-file exists
        if shutil.which("grub-file") == None:
            cprint("grub-file is not installed!", "red")
            exit(1)

        # Verify that the nucleus produced is actually not malformed
        if os.system("grub-file --is-x86-multiboot nucleus") != 0:
            cprint("The Nucleus is malformed (not x86 multiboot complaint)", "red")
            exit(1)

        if shutil.which("grub-mkrescue") == None:
            cprint("grub-mkrescue is not installed!", "red")
            exit(1)

    # The user wants to deploy the gba system
    elif platform == "gba":

        if shutil.which("llvm-objcopy-12") == None:
            cprint("llvm-objcopy-12 is not installed!", "red")
            exit(1)

        if os.system("llvm-objcopy-12 -O binary nucleus") != 0:
            cprint("objcopy failed on given nucleus image!", "red")
            exit(1)

        # Make sure gba fix is installed
        if shutil.which("tsos-gbafix") == None:
            cprint("tsos-gbafix is not installed!", "red")
            exit(1)

        # Fix the gba rom
        if os.system("tsos-gbafix nucleus") != 0:
            cprint("tsos-gbafix failed!", "red")
            exit(1)

    # Target the nspire
    elif platform == "nspire":
        if shutil.which("llvm-objcopy-12") == None:
            cprint("llvm-objcopy-12 is not installed!", "red")
            exit(1)

        if os.system("llvm-objcopy-12 -O binary nucleus") != 0:
            cprint("objcopy failed on given nucleus image!", "red")
            exit(1)

    elif platform == "rpi3":
        if shutil.which("llvm-objcopy-12") == None:
            cprint("llvm-objcopy-12 is not installed!", "red")
            exit(1)

        if os.system("llvm-objcopy-12 -O binary nucleus") != 0:
            cprint("objcopy failed on given nucleus image!", "red")
            exit(1)

else:

    # You tried to build for the wrong system
    cprint("Invalid system", "red")
    exit(1)

# Building was succesful if it made it to here
cprint("Compiling and deploying completed.", "green")
cprint("Your copy of the TS/OS nucleus is at build/nucleus", "green")

# Meaning that the user didn't want any other action
if action == "":
    exit(0)

if action in ["debug", "test"]:

    if(build_settings["systems"][platform][action+"_command"] != ""):
        os.system(build_settings["systems"][platform][action+"_command"])

    else:
        cprint("Cannot " + action + " this system with this script yet.", "yellow")
        exit(0)
else:
    cprint("Invalid action", "red")
