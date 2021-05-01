FROM debian:bullseye
RUN dpkg --add-architecture i386
RUN apt -y update
RUN apt -y --no-install-recommends install software-properties-common apt-utils 
RUN apt -y update
RUN apt -y --no-install-recommends install libc6:i386 libstdc++6:i386
RUN apt -y --no-install-recommends install mtools g++ gcc make dos2unix python3 libncurses-dev bison flex libssl-dev libelf-dev wget curl git libncurses5-dev libreadline-dev autoconf automake texinfo libisl-dev gcc-multilib g++-multilib xz-utils grub2 grub-pc-bin xorriso cmake python3-pip dosfstools qemu-system-i386 qemu-system-arm syslinux
RUN pip3 install termcolor
RUN apt -y update
RUN apt -y --no-install-recommends install llvm clang lld
RUN apt -y autoremove
RUN apt clean
RUN rm -rf /var/lib/apt/lists/
RUN rm -rf /var/cache/apt/archives 
RUN rm -rf /usr/share/doc/
RUN rm -rf /usr/share/man/
RUN rm -rf /usr/share/locale/
