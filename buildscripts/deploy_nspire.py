#!/usr/bin/env python3
# By Tsuki Superior

import os
import sys
import shutil

from termcolor import cprint

shutil.copyfile("nucleus.elf", "nucleus")

if os.system("llvm-objcopy-12 -O binary nucleus") != 0:
    cprint("objcopy failed on given nucleus image!", "red")
    sys.exit(1)
