#!/usr/bin/env python3
# By Tsuki Superior

import os
import sys
import shutil

from termcolor import cprint

shutil.copyfile("nucleus.elf", "nucleus")

# Convert to binary
if os.system("llvm-objcopy -O binary nucleus") != 0:
    cprint("objcopy failed on given nucleus image!", "red")
    sys.exit(1)

shutil.copy("./nucleus", "./filesystem/")
shutil.copy("../contrib/rpi-firmware/boot/bootcode.bin", "./filesystem/")
shutil.copy("../contrib/rpi-firmware/boot/start.elf", "./filesystem/")
shutil.copy("../misc/config.txt", "./filesystem/")

# Make a file to make into a drive image
if os.system("dd if=/dev/zero of=nucleus.img count=1 bs=50M") != 0:
    cprint("dd failed!", "red")
    sys.exit(1)

# Make the image into a vfat drive
if os.system("mkfs.vfat -s1 -F32 -nTSOS \"nucleus.img\"") != 0:
    cprint("mkfs failed!", "red")
    sys.exit(1)

with os.scandir("filesystem") as it:
    for entry in it:
        # Copy the filesystem directory into the drive image
        if os.system("mcopy -s -i nucleus.img " + entry.path + " ::") != 0:
            cprint("mcopy failed!", "red")
            sys.exit(1)
