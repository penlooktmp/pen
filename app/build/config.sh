#!/bin/bash
cd nginx
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
	--with-cc=cc \
	--add-module=../module;