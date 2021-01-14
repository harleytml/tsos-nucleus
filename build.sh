#!/usr/bin/env bash

CODE_DIR=$(pwd)

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