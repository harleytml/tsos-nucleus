#!/usr/bin/env python3
# By Tsuki Superior

import os
import json

from termcolor import cprint

if os.system("dd if=/dev/zero of=tsos.img count=1 bs=50M") != 0:
    cprint("dd failed!", "red")
    exit(1)

if os.system("mkfs.vfat -s1 -F32 -nTSOS \"tsos.img\"") != 0:
    cprint("mkfs failed!", "red")
    exit(1)

if os.system("mcopy -i tsos.img nucleus ::") != 0:
    cprint("mcopy failed!", "red")
    exit(1)
