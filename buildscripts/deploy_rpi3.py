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
shutil.copy("../contrib/rpi-firmware/boot/LICENCE.broadcom", "./filesystem/")
shutil.copy("../misc/config.txt", "./filesystem/")

with open("nucleus.img", "wb") as f:
    f.seek(1024 * 1024 * 50) # 50 MB
    f.write(bytes('\x00'))
    f.close()
    
# Make the image into a vfat drive
if os.system("mkfs.fat -s1 -F32 -nTSOS \"nucleus.img\"") != 0:
    cprint("mkfs failed!", "red")
    sys.exit(1)

with os.scandir("filesystem") as it:
    for entry in it:
        # Copy the filesystem directory into the drive image
        if os.system("mcopy -s -i nucleus.img " + entry.path + " ::") != 0:
            cprint("mcopy failed!", "red")
            sys.exit(1)
