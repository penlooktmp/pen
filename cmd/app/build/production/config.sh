#!/bin/bash

lf() {
	cp $1 $1_2
	tr -d '\r' < $1_2 > $1
}

lf ./module/config

cd nginx

# Update nginx
git checkout .
git checkout master

# Override configuration
cp -rf ../config/gcc ../nginx/auto/cc/gcc
cp -rf ../config/make ../nginx/auto/make

# Remove CRLF characters
lf configure
lf ../nginx/auto/cc/gcc
lf ../nginx/auto/make

# Configure nginx
chmod +x configure
./configure \
	--prefix=/etc/nginx \
	--sbin-path=/usr/sbin/nginx \
	--conf-path=/etc/nginx/nginx.conf \
	--pid-path=/var/run/nginx.pid \
	--lock-path=/var/run/nginx.lock \
	--with-http_ssl_module \
	--with-pcre \
	--with-ld-opt="-lstdc++" \
	--with-cc=gcc \
	--add-module=../module;