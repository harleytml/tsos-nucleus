#!/usr/bin/env python3
# By Tsuki Superior

import os
import sys

from termcolor import cprint

if os.system("dd if=/dev/zero bs=4M count=1 of=nucleus") != 0:
    cprint("dd failed on given nucleus image!", "red")
    sys.exit(1)

if os.system("dd if=nucleus.elf of=nucleus conv=notrunc") != 0:
    cprint("dd failed on given nucleus image!", "red")
    sys.exit(1)

# 0xffff0000:  fe 3f f0 ea     b       0xffc00000
if os.system("echo -n -e \"\xfe\x3f\xf0\xea\" | dd of=nucleus bs=64K seek=63 conv=notrunc") != 0:
    cprint("dd failed on given nucleus image!", "red")
    sys.exit(1)
