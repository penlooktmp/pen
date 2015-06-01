#!/bin/bash
cd nginx

# Update nginx
git checkout .
git checkout master

# Override configuration
cp -rf ../config/gcc ../nginx/auto/cc/gcc
cp -rf ../config/make ../nginx/auto/make

# Remove CRLF characters
cp configure configure2
tr -d '\r' < configure2 > configure

cp ../nginx/auto/cc/gcc ../nginx/auto/cc/gcc2
tr -d '\r' < ../nginx/auto/cc/gcc2 > ../nginx/auto/cc/gcc

cp ../nginx/auto/make ../nginx/auto/make2
tr -d '\r' < ../nginx/auto/make2 > ../nginx/auto/make

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