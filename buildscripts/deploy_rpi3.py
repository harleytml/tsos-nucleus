#!/usr/bin/env python3
# By Tsuki Superior

import os
import json

from termcolor import cprint

# Convert to binary
if os.system("llvm-objcopy-12 -O binary nucleus") != 0:
    cprint("objcopy failed on given nucleus image!", "red")
    exit(1)

# Make a file to make into a drive image
if os.system("dd if=/dev/zero of=tsos.img count=1 bs=50M") != 0:
    cprint("dd failed!", "red")
    exit(1)

# Make the image into a vfat drive
if os.system("mkfs.vfat -s1 -F32 -nTSOS \"tsos.img\"") != 0:
    cprint("mkfs failed!", "red")
    exit(1)

# Copy the nucleus image into the drive image
if os.system("mcopy -i tsos.img nucleus ::") != 0:
    cprint("mcopy failed!", "red")
    exit(1)
