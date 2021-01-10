#!/usr/bin/env bash

CODE_DIR=$(pwd)

if [ ! -f "./token" ]; then
    
    #The version of gcc that will be used here
    GCC_VERSION=10.2.0
    
    #The version of binutils that will be used here
    BINUTILS_VERSION=2.35
    
    #The version of devkitarm that will be used here
    DEVKITARM_VERSION=r55
    
    #The version of gbdk to use
    GBDK_VERSION=4.0.1
    
    #The url for gcc`s tarball
    GCC_DOWNLOAD_URL=https://ftp.gnu.org/gnu/gcc/gcc-$GCC_VERSION.tar.xz
    
    #The url for binutils`s tarball
    BINUTILS_DOWNLOAD_URL=https://ftp.gnu.org/gnu/binutils/binutils-$BINUTILS_VERSION.tar.xz
    
    #The url for devkitarms`s tarball
    DEVKITARM_DOWNLOAD_URL=https://github.com/devkitPro/buildscripts/archive/devkitARM_$DEVKITARM_VERSION.tar.gz
    
    #The url for gbdk
    GBDK_DOWNLOAD_URL=https://github.com/Zal0/gbdk-2020/archive/$GBDK_VERSION.tar.gz
    
    #The install dir for the compilers
    INSTALL_DIR=/usr/tsos-toolchain
    
    #Prepare and move to the directory
    rm -rfv /tmp/tsos
    mkdir -pv /tmp/tsos
    cd /tmp/tsos
    
    #Get the compilers from the web
    wget $GCC_DOWNLOAD_URL
    wget $BINUTILS_DOWNLOAD_URL
    wget $DEVKITARM_DOWNLOAD_URL
    wget $GBDK_DOWNLOAD_URL
    
    #Unarchive those tarballs
    tar -xf gcc-$GCC_VERSION.tar.xz
    mv -v gcc-$GCC_VERSION/ gcc/
    tar -xf binutils-$BINUTILS_VERSION.tar.xz
    mv -v binutils-$BINUTILS_VERSION/ binutils/
    tar -xf devkitARM_$DEVKITARM_VERSION.tar.gz
    mv -v devkitARM_$DEVKITARM__VERSION/ devkitarm
    tar -xf $GBDK_VERSION.tar.gz
    mv -v $GBDK_VERSION/ gbdk
    
    #We will compile binutils first
    cd binutils
    mkdir -pv build
    cd build
    ../configure --prefix=$INSTALL_DIR \
    --enable-gold \
    --enable-interwork \
    --target=1686-elf \
    --enable-multilib \
    --disable-nls \
    --disable-werror
    
    make
    make install
    
    #Now we will compile gcc
    cd /tmp/tsos
    cd gcc
    mkdir -pv build
    cd build
    ../configure --prefix=$INSTALL_DIR \
    --enable-languages=c,c++ \
    --disable-libssp \
    --disable-nls \
    --disable-libssp \
    --disable-werror
    
    make
    make install
    
    //Lets update that path variable
    PATH=$PATH:$INSTALL_DIR/bin
    
    echo "export PATH=$PATH" >> ~/.bashrc
    
    cd $CODE_DIR
    
    touch ./token
fi

#Prepare the filesystem root for TS/OS
FILESYSTEM_ROOT=$CODE_DIR/../filesystem
rm -rfv $FILESYSTEM_ROOT
mkdir -pv $FILESYSTEM_ROOT/{bin,cfg,lib,sys,sys/tmp,sys/headers,sys/info,sys/trash,tmp}

#Make the target nucleus
mkdir -pv $CODE_DIR/build/
cd ./nucleus/
make -f Makefile.$1.mk
cd $CODE_DIR
cd applications

#Now we need to make the system applications
SYSTEM_APPLICATIONS=(cd cpy ctl date del echo info kill lstd lstp lstv math mov osi pi tsh)
for i in "${SYSTEM_APPLICATIONS[@]}"
do
    cd $i
    make -f Makefile.$1.mk
    cd ..
done