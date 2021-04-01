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
tmp_file = open("cfg/system_config.json")
build_settings = json.loads(tmp_file.read())
tmp_file.close()

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
    cprint("Official TS/OS buildscript (C) Tsuki Superior. Licensed under the same license as TS/OS (see LICENSE file)\n", "yellow")
    print(sys.argv[0], "<system> <action>")
    print("Supported systems:\n")

    for x in build_settings:
        print(x, "-", build_settings[x]["description"])
    cprint("\nSet the action to either debug or test, or you can leave it blank\n", "yellow")
    print("Look in buildscript directory to find the buildscripts pertaining to the systems")
    sys.exit(1)

# Get the platform
platform = sys.argv[1].lower()
if len(sys.argv) > 2:
    action = sys.argv[2].lower()
else:
    action = ""

if platform in build_settings:

    # Create build folder if it doesn't exist
    if not os.path.isdir("build"):
        os.mkdir("build")

    # Change to build dir
    os.chdir("build")

    if os.path.exists("nucleus"):
        os.remove("nucleus")

    if os.path.exists("tsos.iso"):
        os.remove("tsos.iso")

    if os.path.exists("tsos.img"):
        os.remove("tsos.img")

    if os.path.exists("tsos.gba"):
        os.remove("tsos.gba")

    # Run cmake
    os.system("cmake .. -DPLATFORM=" + platform.upper())

    # Run make
    os.system("make")

    # Insure that the kernel was produced, and if not, fail
    if not os.path.exists("nucleus"):
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
    cprint("Cannot yet deploy this system", "yellow")


# Building was succesful if it made it to here
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
            cprint("Action " + action + "failed", "red")
            sys.exit(1)

    else:
        cprint("Cannot " + action + " this system with this script yet.", "yellow")
        sys.exit(0)

else:
    cprint("Invalid action", "red")
    sys.exit(1)
