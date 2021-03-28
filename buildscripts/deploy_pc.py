#!/usr/bin/env python3
# By Tsuki Superior

import os
import json

from termcolor import cprint

# Open that config file and read from it
build_settings_file = open("../cfg/system_config.json")
build_settings = json.loads(build_settings_file.read())
build_settings_file.close()

# Verify that the nucleus produced is actually not malformed
if os.system("grub-file --is-x86-multiboot nucleus") != 0:
    cprint("The Nucleus is malformed (not multiboot complaint)", "red")
    exit(1)
