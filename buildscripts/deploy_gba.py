#!/usr/bin/env python3
# By Tsuki Superior

import os
import sys
import shutil

from termcolor import cprint

# No conversion has to be done
shutil.copyfile("nucleus.elf", "nucleus")

# Convert to binary
if os.system("llvm-objcopy-12 -O binary nucleus") != 0:
    cprint("objcopy failed on given nucleus image!", "red")
    sys.exit(1)

# Fix the gba rom
if os.system("tsos-gbafix nucleus") != 0:
    cprint("tsos-gbafix failed!", "red")
    sys.exit(1)
