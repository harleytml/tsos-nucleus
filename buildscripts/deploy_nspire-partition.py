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

platform = sys.argv[1].lower()

if os.system("llvm-objcopy-12 -O binary nucleus") != 0:
    cprint("objcopy failed on given nucleus image!", "red")
    exit(1)
