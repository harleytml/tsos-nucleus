# TS/OS Nucleus

[![Discord](https://badgen.net/badge/Discord/join/purple?icon=discord)](https://discord.gg/UgXJwS5rup)
[![Gitpod ready-to-code](https://img.shields.io/badge/Gitpod-ready--to--code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/tsuki-superior/tsos-nucleus)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/e7822fe3509d493e818a56e7ec8d53d6)](https://www.codacy.com/gh/tsuki-superior/tsos-nucleus/dashboard?utm_source=github.com&utm_medium=referral&utm_content=tsuki-superior/tsos-nucleus&utm_campaign=Badge_Grade)
![LoC](https://raw.githubusercontent.com/tsuki-superior/tsos-nucleus/loc/badge.svg)
[![LICENSE](https://img.shields.io/github/license/tsuki-superior/tsos-nucleus)](https://github.com/tsuki-superior/tsos-nucleus/blob/master/LICENSE)
![DOWNLOADS](https://img.shields.io/github/downloads/tsuki-superior/tsos-nucleus/total)
[![Docker Hub](https://badgen.net/docker/pulls/tsukisuperior/tsos-build)](https://hub.docker.com/r/tsukisuperior/tsos-build)

## Build Tests

[![Compile And Release](https://github.com/tsuki-superior/tsos-nucleus/actions/workflows/compile-and-release.yml/badge.svg)](https://github.com/tsuki-superior/tsos-nucleus/actions/workflows/compile-and-release.yml)
[![Build Docker Image](https://github.com/tsuki-superior/tsos-nucleus/actions/workflows/docker-image.yml/badge.svg)](https://github.com/tsuki-superior/tsos-nucleus/actions/workflows/docker-image.yml)
[![Test Pull Requests](https://github.com/tsuki-superior/tsos-nucleus/actions/workflows/test-pull-request.yml/badge.svg)](https://github.com/tsuki-superior/tsos-nucleus/actions/workflows/test-pull-request.yml)

## Contributors

![Contributers](https://contrib.rocks/image?repo=tsuki-superior/tsos-nucleus)

## Platforms

- `PC` - Personal Computer - Boots on real hardware, most promising port
- `NSPIRE` - TI-Nspire - Quark model in place, research being done
- `RPI3` - Raspberry Pi 3 - Boots on QEMU, Serial Works on QEMU
- `CANON-A1100` - Canon PowerShot A1100IS - Primitive and experimental quarks in place, and being modeled
- `CUBIEBOARD1` - CubieTech Cubieboard 1 - Planning being done
- `VEXPRESS-A15` - ARM Versatile Express for Cortex-A15 - Planning being done

## Description

This is TS/OS's Monolithic kernel

Current Version: `Neutronium (0.0)`

TS/OS is a unique operating system with a focus on being as multiplatform as possible.

TS/OS was a operating system made for several reasons

- 1: Because I got bored, and I had nothing to do
- 2: Because I needed to learn C/C++
- 3: Because I got infuriated by the fact that some devices cannot have Linux ports
- 4: And finally, because I was inspired by the genius of Terry A. Davis.

The story behind TS/OS is a interesting one. The first edition was mostly developed on a hacked TI-Nspire, a graphing calculator. I got bored during the winter break of my sophomore year, and I always wanted to make a OS. So I did with a copy of The Revolutionary Guide To Assembly Language, and a C++ book.

I had just learned C++, and wanted to reinvent the wheel. I had a little too much time on my hands.

The TS/OS kernel is called the Nucleus. Many other chemistry analogues will be made in the OS. The TS/OS version of a kernel panic is a Nucleus Fission, and the drivers and modules are called quarks and nucleons!

In the documents directory, you can find more documents concerning TS/OS.

## Current Platforms

Run

```sh
python3 ./build.py help
```

to see all the platforms

## Pre-Building

You need to install these tools:

```sh
clang        # 10 or above is recommended, I use 13
lld          # 10 or above is recommended, I use 13
llvm         # 10 or above is recommended, I use 13
termcolor
make
cmake        # 3.13 or above is recommended, I use 3.13
python3
pip3
dosfstools
gdb-multiarch
```

Debian/Ubuntu :

```sh
sudo apt-get update
sudo apt-get install clang lld llvm make cmake python3 python3-pip dosfstools grub-pc-bin xorriso grub2 gdb-multiarch
pip3 install -r requirements.txt
```

Please note that if your repo doesn't support llvm-10 or up, that you should look at the llvm website for more info.

## Building

To build TS/OS, run

```sh
python3 ./build.py <platform>
```

For example, the platform `pc` runs the pc build.

To get the list of supported systems and other options, type `help` as the platform

## Configuring

In the `config` directory, some json config files exist. I plan to make them control the entire build process of TS/OS.

## Developing

Look in the `documents` directory for some more information on TS/OS, and also the C++ header files have more information
on TS/OS, and how it is interacting with hardware.

## Docker

There is a Docker Container used to compile TS/OS. You can also use it to compile TS/OS if you so please.

## Cloning

Please note that the repo for rpi firmware (contained in `contrib`) is extremely large (~10 gb)

If you have no interest in the rpi3, you do not have to clone submodules recursively.
