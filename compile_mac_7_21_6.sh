#!/bin/sh
# 1. download libcurl source from: http://curl.haxx.se/download/curl-7.21.6.tar.gz 
# 2. extract and copy this file
# 3. chmod 777 on this file 
# 4. execute this file
set -x
dir=${PWD}
bd=${dir}/build
if [ ! -d ${db} ] ; then
        mkdir -p ${bd}
fi

export CC="/Developer/usr/bin/llvm-gcc-4.2"
./configure     --disable-ldap \
                --without-ssl \
                --prefix=${bd} \
                --enable-static \
                --disable-ldaps \
                CFLAGS="-arch i386"
make
make install
