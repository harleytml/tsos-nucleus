FROM debian:bullseye
RUN dpkg --add-architecture i386
RUN apt -y update
RUN apt -y --no-install-recommends install software-properties-common apt-utils 
RUN apt -y update
RUN apt -y --no-install-recommends install libc6:i386 libstdc++6:i386
RUN apt -y --no-install-recommends install mtools dos2unix python3 wget xz-utils grub2 grub-pc-bin xorriso cmake python3-pip dosfstools qemu-system-i386 qemu-system-arm
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
