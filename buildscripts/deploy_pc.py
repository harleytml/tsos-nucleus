#!/usr/bin/env python3
# By Tsuki Superior

import os
import sys
import shutil
import json

from termcolor import cprint

# Open that config file and read from it
tmp_file = open("../config/directory_structure.json")
fileystem_dict = json.loads(tmp_file.read())
tmp_file.close()

root_dir = os.getcwd()
if not(os.path.exists("filesystem")):
    os.mkdir("filesystem")


def recurse(dic):
    def one_directory(dic, path):
        for name, info in dic.items():
            next_path = path + "/" + name
            if isinstance(info, dict):
                if not(os.path.exists(next_path)):
                    os.mkdir(next_path)
                one_directory(info, next_path)
    one_directory(dic, "filesystem")


recurse(fileystem_dict)

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

os.mkdir("./filesystem/boot/grub/")
shutil.copy("../misc/grub.cfg", "./filesystem/boot/grub/")
shutil.copy("./nucleus", "./filesystem/")

if os.system("grub-mkrescue -o nucleus.iso filesystem") != 0:
    cprint("Grub Rescue Failed", "red")
    sys.exit(1)
