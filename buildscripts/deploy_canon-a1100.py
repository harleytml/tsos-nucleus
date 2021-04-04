#!/usr/bin/env python3
# By Tsuki Superior

import os
import sys
import shutil

from termcolor import cprint

shutil.copyfile("nucleus.elf", "nucleus")

if os.system("llvm-objcopy -O binary nucleus") != 0:
    cprint("objcopy failed on given nucleus image!", "red")
    sys.exit(1)

if os.system("dd if=/dev/zero bs=4M count=1 of=nucleus.tmp") != 0:
    cprint("dd failed on given nucleus image!", "red")
    sys.exit(1)

if os.system("dd if=nucleus of=nucleus.tmp conv=notrunc") != 0:
    cprint("dd failed on given nucleus image!", "red")
    sys.exit(1)

# 0xffff0000:  fe 3f f0 ea     b       0xffc00000
if os.system("echo -n -e \"\xfe\x3f\xf0\xea\" | dd of=nucleus.tmp bs=64K seek=63 conv=notrunc") != 0:
    cprint("dd failed on given nucleus image!", "red")
    sys.exit(1)

if os.path.exists("nucleus"):
    if os.remove("nucleus"):
        cprint("Removing failed on given nucleus image!", "red")
        sys.exit(1)
else:
    cprint("Nucleus image did not exist", "red")
    sys.exit(1)

if not(shutil.copy("nucleus.tmp", "nucleus")):
    cprint("Copying failed on given nucleus image!", "red")
    sys.exit(1)

if os.remove("nucleus.tmp"):
    cprint("Removing failed on given nucleus temp image!", "red")
    sys.exit(1)
