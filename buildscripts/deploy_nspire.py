#!/usr/bin/env python3
# By Tsuki Superior

import os
import json
import sys

from termcolor import cprint

if os.system("llvm-objcopy-12 -O binary nucleus") != 0:
    cprint("objcopy failed on given nucleus image!", "red")
    sys.exit(1)
