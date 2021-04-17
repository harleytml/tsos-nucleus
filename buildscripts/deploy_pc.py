#!/usr/bin/env python3
# By Tsuki Superior

import os
import sys
import shutil
import json

from termcolor import cprint

# No conversion has to be done
shutil.copyfile("nucleus.elf", "nucleus")

# Verify that the nucleus produced is actually not malformed
if os.system("grub-file --is-x86-multiboot nucleus") != 0:
    cprint("The Nucleus is malformed (not multiboot complaint)", "red")
    sys.exit(1)

# Make sure that grub script is valid
if os.system("grub-script-check ../misc/grub.cfg") != 0:
    cprint("The grub config file is not valid", "red")
    sys.exit(1)

os.makedirs("./filesystem/boot/grub/", exist_ok=True)
shutil.copy("../misc/grub.cfg", "./filesystem/boot/grub/")
shutil.copy("./nucleus", "./filesystem/")

if os.system("grub-mkrescue -o nucleus.iso filesystem") != 0:
    cprint("Grub Rescue Failed", "red")
    sys.exit(1)
