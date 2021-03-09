# TS/OS Nucleus

[![Discord](https://badgen.net/badge/Discord/join/purple?icon=discord)](https://discord.gg/UgXJwS5rup)
[![Gitpod ready-to-code](https://img.shields.io/badge/Gitpod-ready--to--code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/tsuki-superior/tsos-nucleus)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/e7822fe3509d493e818a56e7ec8d53d6)](https://www.codacy.com/gh/tsuki-superior/tsos-nucleus/dashboard?utm_source=github.com&utm_medium=referral&utm_content=tsuki-superior/tsos-nucleus&utm_campaign=Badge_Grade)
![LoC](https://raw.githubusercontent.com/tsuki-superior/tsos-nucleus/loc/badge.svg)

This is TS/OS's Monolithic kernel

Current Version: `Neutronium (0.0)`

TS/OS is a SysV ABI, \*nix inspired (sorta), operating system with a focus on being as multiplatform as possible.

TS/OS was a operating system made for several reasons

```text
1: Because I got bored, and I had nothing to do

2: Because I needed to learn C/C++

3: Because I got infuriated by the fact that some devices cannot have Linux ports (like the GBA)

4: And finally, because I was inspired by the genius of Terry A. Davis.
```

TS/OS's existence is for it to be ported. With a fairly rigid and simple driver interface, it should be easy to run it on all those small devices Linux is too picky to run on. The first ports are PC, GBA

I intend for TS/OS to be ported to everything. My first goal is all those handheld game consoles, PSP and below. If I can get it to run on a GBA, surely I can run it on the others.

The story behind TS/OS is a interesting one. The first edition was mostly developed on a hacked TI-Nspire, a graphing calculator. I got bored during the winter break of my sophmore year, and I always wanted to make a OS. So I did with a copy of The Revolutionary Guide To Assembly Language, and some random documents on the GBA.

I had just learned C++, and wanted to reinvent the wheel. I had a little too much time on my hands.

The TS/OS kernel is called the Nucleus. Many other chemistry analogues will be made in the OS. The TS/OS version of a kernel panic is a Nucleus Fission!

In the documents directory, you can find more documents concerning TS/OS.

To build TS/OS, run

```sh
./build.sh <platform>
```

For example, the platform `pc` runs the pc build.

If you want to test, simply run `test` also

```sh
./build.sh <platform> test
```

Note that each platform needs its own testing tools

To debug, simply use this command

```sh
./build.sh <platform> debug
```

The debugging tools are the same as the testing tools

The GDB port you need to connect to is outputted to the terminal as a message.
