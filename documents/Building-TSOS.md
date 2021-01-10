TS/OS is meant to be built on a standard Linux system, but other *nix enviroments will work.

The base packages you need are ones that include make, gcc, and g++. Usually the most basic development tools can all be installed in one package, so consult the documentation for your system.

Under no circumstances may TS/OS be built with your standared gcc that came with the system. No matter what settings you set to produce independent executables, it will still optimize for your system, causing TS/OS to do god knows what.

The previous statement may change, as I may make a port of TS/OS as a compatibility layer (Think WINE), but my Makefiles will take care of this.

Run ./build.sh to build the toolchain, and the OS.

This might take a while, especially if you ran this for the first time, because the compilers have to be compiled.