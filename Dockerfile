FROM debian:bullseye
RUN dpkg --add-architecture i386
RUN apt-get -y update
RUN apt-get -y --no-install-recommends install software-properties-common apt-utils 
RUN apt-get -y update
RUN apt-get -y --no-install-recommends install libc6:i386 libstdc++6:i386
RUN apt-get -y --no-install-recommends install mtools g++ gcc make dos2unix python3 libncurses-dev bison flex libssl-dev libelf-dev wget curl git libncurses5-dev libreadline-dev autoconf automake texinfo libisl-dev gcc-multilib g++-multilib xz-utils grub2 grub-pc-bin xorriso cmake python3-pip dosfstools qemu-system-i386 qemu-system-arm syslinux
RUN pip3 install termcolor
RUN apt-get -y update
RUN apt-get -y --no-install-recommends install llvm clang lld
RUN apt-get -y remove tcsh w3m
RUN apt-get -y autoremove
RUN apt-get clean
RUN rm -rf /var/lib/apt/lists/*
