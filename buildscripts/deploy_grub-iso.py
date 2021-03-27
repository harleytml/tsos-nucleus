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

if not(len(sys.argv) == 2):
    cprint("This script is not meant to be run by users!", "red")

# Verify that the nucleus produced is actually not malformed
if os.system("grub-file --is-x86-multiboot nucleus") != 0:
    cprint("The Nucleus is malformed (not multiboot complaint)", "red")
    exit(1)
