#!/usr/bin/env python3
# By Tsuki Superior

import sys
import os
import shutil
import json

from termcolor import cprint


def recurse(dic):
    def one_directory(dic, path):
        for name, info in list(dic.items()):
            next_path = path + "/" + name
            if isinstance(info, dict):
                if not(os.path.exists(next_path)):
                    os.mkdir(next_path)
                one_directory(info, next_path)
    one_directory(dic, "filesystem")


# Create build folder if it doesn't exist
if not os.path.isdir("build"):
    os.mkdir("build")

# Create build folder if it doesn't exist
if os.path.isdir("build/filesystem"):
    shutil.rmtree("build/filesystem")

# Open that config file and read from it
tmp_file = open("config/system_config.json")
build_settings = json.loads(tmp_file.read())
tmp_file.close()

# Open that config file and read from it
tmp_file = open("config/directory_structure.json")
fileystem_dict = json.loads(tmp_file.read())
tmp_file.close()

if not(os.path.exists("build/filesystem")):
    os.mkdir("build/filesystem")

# This only works on unix like systems right now
if os.name != "posix":
    cprint("Only posix systems are supported in this script!", "red")
    sys.exit(1)

# You must install cmake to use this
if shutil.which("cmake") is None:
    cprint("cmake is not installed!", "red")
    sys.exit(1)

# Make sure the script has the correct number of arguments, and if not, display help
if not(len(sys.argv) == 2 or len(sys.argv) == 3) or sys.argv[1] == "help":
    cprint("\nOfficial TS/OS buildscript (C) Tsuki Superior. Licensed under the same license as TS/OS (see LICENSE file)\n", "yellow")
    cprint(sys.argv[0] + " <system> <action>", "green")
    print("Supported systems:\n")

    for x in build_settings:
        print(x, "-", build_settings[x]["description"])
    cprint("\nSet the action to either debug or test, or you can leave it blank\n", "yellow")
    cprint("Look in buildscript directory to find the buildscripts pertaining to the systems\n", "yellow")
    sys.exit(1)

# Get the platform
platform = sys.argv[1].lower()
if len(sys.argv) > 2:
    action = sys.argv[2].lower()
else:
    action = ""

if platform in build_settings:

    # Change to build dir
    os.chdir("build")

    recurse(fileystem_dict)

    if os.path.exists("nucleus"):
        os.remove("nucleus")

    if os.path.exists("nucleus.elf"):
        os.remove("nucleus.elf")

    if os.path.exists("nucleus.iso"):
        os.remove("nucleus.iso")

    if os.path.exists("nucleus.img"):
        os.remove("nucleus.img")

    # Run cmake
    os.system("cmake .. -DPLATFORM=" + platform.upper())

    # Run make
    os.system("make")

    # Insure that the kernel was produced, and if not, fail
    if not os.path.exists("nucleus.elf"):
        cprint("Compiling failed!", "red")
        sys.exit(1)

    # Make sure the required tools are actually there
    for x in build_settings[platform]["required_tools"]:

        # Warn the user is this is not true
        if shutil.which(x) is None:
            cprint(x + " is not installed, which is needed for deploying", "red")
            sys.exit(1)

        # Make sure the script exists
    if os.path.exists("../buildscripts/deploy_" + platform + ".py"):

        # Run that script
        if os.system("python3 " + "../buildscripts/deploy_" + platform + ".py") != 0:
            cprint("Buildscript failed!", "red")
            sys.exit(1)

    else:
        cprint("Buildscript could not be found", "red")
        sys.exit(1)

else:
    cprint("System does not exist!", "red")
    exit(1)


# Building was succesful if it made it to here
if os.system("llvm-objdump -d --source --demangle --debug-vars nucleus.elf > nucleus_dump.asm") != 0:
    cprint("Dumping ELF file failed!", "yellow")

cprint("Compiling and deploying completed.", "green")
cprint("Your copy of the TS/OS nucleus is at build/nucleus", "green")

# Meaning that the user didn't want any other action
if action == "":
    sys.exit(0)

# Make sure you are either debugging or configuring
if action in ["debug", "test"]:

    # Make sure the correct testing tools are there
    for x in build_settings[platform]["required_test_tools"]:

        # Warn the user if not
        if shutil.which(x) is None:
            cprint(x + " is not installed, which is needed for " + action, "red")
            sys.exit(1)

    # Run said command
    if build_settings[platform][action+"_command"] != "":

        # Make sure command doesn't fail
        if os.system(build_settings[platform][action+"_command"]) != 0:
            cprint("Action " + action + " failed", "red")
            sys.exit(1)

    else:
        cprint("Cannot " + action + " this system with this script yet.", "yellow")
        sys.exit(0)

else:
    cprint("Invalid action", "red")
    sys.exit(1)
