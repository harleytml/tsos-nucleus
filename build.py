#!/usr/bin/env python3
# By Tsuki Superior

import sys
import os
import shutil
import json

from termcolor import cprint

# Create build folder if it doesn't exist
if os.path.isdir("/tmp/tsos-filesystem"):
    shutil.rmtree("/tmp/tsos-filesystem")

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
if shutil.which("cmake") is None:
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

# Building was succesful if it made it to here
cprint("Compiling and deploying completed.", "green")
cprint("Your copy of the TS/OS nucleus is at build/nucleus", "green")

if "deploy_disk_type" in build_settings["systems"][platform]["options"]:
    disk_type = build_settings["systems"][platform]["options"]["deploy_disk_type"]
    if disk_type == "grub-iso":
        if shutil.which("grub-file") is None:
            cprint("grub-file is not installed!", "red")
            exit(1)

        if build_settings["systems"][platform]["options"]["arch"] == "x86":
            check_type = "--is-x86-multiboot"
        else:
            cprint("Cannot deploy this kernel type yet to " + disk_type, "yellow")

        # Verify that the nucleus produced is actually not malformed
        if os.system("grub-file " + check_type + " nucleus") != 0:
            cprint("The Nucleus is malformed (not multiboot complaint)", "red")
            exit(1)

        if shutil.which("grub-mkrescue") is None:
            cprint("grub-mkrescue is not installed!", "red")
            exit(1)

    elif disk_type == "gba-rom":
        if build_settings["systems"][platform]["options"]["arch"] != "arm":
            cprint("The disk_type " + disk_type +
                   " can only be used in arm", "red")
            exit(1)

        # Make sure its install
        if shutil.which("llvm-objcopy-12") is None:
            cprint("llvm-objcopy-12 is not installed!", "red")
            exit(1)

        # Convert to binary
        if os.system("llvm-objcopy-12 -O binary nucleus") != 0:
            cprint("objcopy failed on given nucleus image!", "red")
            exit(1)

        # Make sure gba fix is installed
        if shutil.which("tsos-gbafix") is None:
            cprint("tsos-gbafix is not installed!", "red")
            exit(1)

        # Fix the gba rom
        if os.system("tsos-gbafix nucleus") != 0:
            cprint("tsos-gbafix failed!", "red")
            exit(1)

    elif disk_type == "nspire_boot_partition":
        if shutil.which("llvm-objcopy-12") is None:
            cprint("llvm-objcopy-12 is not installed!", "red")
            exit(1)

        if os.system("llvm-objcopy-12 -O binary nucleus") != 0:
            cprint("objcopy failed on given nucleus image!", "red")
            exit(1)

    else:
        cprint("Cannot yet deploy this system", "yellow")

# Meaning that the user didn't want any other action
if action == "":
    exit(0)

if action in ["debug", "test"]:

    if build_settings["systems"][platform][action+"_command"] != "":
        os.system(build_settings["systems"][platform][action+"_command"])

    else:
        cprint("Cannot " + action + " this system with this script yet.", "yellow")
        exit(0)
else:
    cprint("Invalid action", "red")
