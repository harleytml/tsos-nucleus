#!/usr/bin/env python3
# By Tsuki Superior

import os
import json

from termcolor import cprint

# Verify that the nucleus produced is actually not malformed
if os.system("grub-file --is-x86-multiboot nucleus") != 0:
    cprint("The Nucleus is malformed (not multiboot complaint)", "red")
    exit(1)

if os.system("grub-script-check ../misc/grub.cfg") != 0:
    cprint("The grub config file is not valid", "red")
    exit(1)
