#!/usr/bin/env python3
# By Tsuki Superior

import sys
import os
import shutil
import json

from termcolor import cprint

# Open that config file and read from it
build_settings_file = open("../cfg/system_config.json")
build_settings = json.loads(build_settings_file.read())
build_settings_file.close()

# Make sure its installed
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
