#!/bin/bash

lf() {
	cp $1 $1_2
	tr -d '\r' < $1_2 > $1
	rm -rf $1_2
}

lf ./module/config

NGINX=nginx
if [ ! -d "$NGINX" ]; then
	wget https://github.com/nginx/nginx-releases/archive/master.zip
	unzip master.zip
	mv nginx-releases-master $NGINX
fi

cd $NGINX

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
	--without-mail_pop3_module \
	--without-mail_imap_module \
	--without-mail_smtp_module \
	--without-http_upstream_ip_hash_module \
	--without-http_memcached_module \
	--without-http_referer_module \
	--without-http_autoindex_module \
	--without-http_auth_basic_module \
	--without-http_userid_module \
	--without-http_map_module \
	--without-http_memcached_module \
	--without-http_proxy_module \
	--without-http_referer_module \
	--without-http_scgi_module \
	--without-http_ssi_module \
	--without-http_uwsgi_module \
	--without-http_geo_module \
	--with-http_ssl_module \
	--with-pcre \
	--with-ld-opt="-lstdc++" \
	--with-cc=gcc \
	--add-module=../module;