#!/bin/sh
dir=${PWD}
echo ${PWD}
if [ "$1" = "reset" ] ; then 
	
	if [ ! -d ${dir}/download ] ; then
		mkdir ${dir}/download
	fi
	
	if [ ! -f ${dir}/download/curl.tgz ] ; then 
		cd ${dir}/download
		curl http://curl.haxx.se/download/curl-7.21.1.tar.gz -o curl.tgz
		tar -zxvf curl.tgz
		mv curl-* curl
	fi
fi 

if [ "$1" = "compile" ] ; then
	cd ${dir}/download/curl
	./configure 	--disable-ldap \
				--without-ssl \
				--prefix=${dir}/download/curl_lib/ \
				--enable-static \
				CFLAGS="-arch i386"
	make
	make install

fi


