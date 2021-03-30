#!/usr/bin/env python3
# By Tsuki Superior

import os
import json

from termcolor import cprint

if os.system("llvm-objcopy-12 -O binary nucleus") != 0:
    cprint("objcopy failed on given nucleus image!", "red")
    exit(1)
