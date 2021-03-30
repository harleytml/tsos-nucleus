#!/usr/bin/env python3
# By Tsuki Superior

import os
import json

from termcolor import cprint

# Convert to binary
if os.system("llvm-objcopy-12 -O binary nucleus") != 0:
    cprint("objcopy failed on given nucleus image!", "red")
    exit(1)

# Fix the gba rom
if os.system("tsos-gbafix nucleus") != 0:
    cprint("tsos-gbafix failed!", "red")
    exit(1)
