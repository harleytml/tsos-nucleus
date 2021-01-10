#!/usr/bin/env bash

#The version of gcc that will be used here
GCC_VERSION=10.2.0

#The version of binutils that will be used here
BINUTILS_VERSION=2.35

#The url for gcc`s tarball
GCC_DOWNLOAD_URL=https://ftp.gnu.org/gnu/gcc/gcc-$GCC_VERSION.tar.xz

#The url for binutils`s tarball
BINUTILS_DOWNLOAD_URL=https://ftp.gnu.org/gnu/binutils/binutils-$BINUTILS_VERSION.tar.xz

#The install dir for the compilers
INSTALL_DIR=/usr/tsos-toolchain

#Prepare and move to the directory
rm -rfv /tmp/tsos
mkdir -pv /tmp/tsos
cd /tmp/tsos

#Get the compilers from the web
wget $GCC_DOWNLOAD_URL
wget $BINUTILS_DOWNLOAD_URL

#Unarchive those tarballs
tar -xf gcc-$GCC_VERSION.tar.xz
mv -v gcc-$GCC_VERSION/ gcc/
tar -xf binutils-$BINUTILS_VERSION.tar.xz
mv -v binutils-$BINUTILS_VERSION/ binutils/

#We will compile binutils first
cd binutils
mkdir -pv build
cd build
../configure --prefix=$INSTALL_DIR \
			 --enable-gold
make
make install

#Now we will compile gcc
cd /tmp/tsos
cd gcc
mkdir -pv build
cd build
../configure --prefix=$INSTALL_DIR \
			 --enable-languages=c,c++
make
make install

//Lets update that path variable
PATH=$PATH:$INSTALL_DIR/bin

echo "export PATH=$PATH" >> ~/.bashrc

cd $TSOS_CODE_DIR

#Prepare the filesystem root for TS/OS
FILESYSTEM_ROOT=$(PWD)/../filesystem
rm -rfv $FILESYSTEM_ROOT
mkdir -pv $FILESYSTEM_ROOT/{bin,cfg,lib,sys,sys/tmp,sys/headers,sys/info,sys/trash,tmp}

#Make the target kernel
cd ./kernel/
make -f Makefile.$1

#Now we need to make the system applications
SYSTEM_APPLICATIONS={cd,cpy,ctl,date,del,echo,info,kill,lstd,lstp,lstv,math,mov,osi,pi,tsh}
