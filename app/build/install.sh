#!/bin/bash
CURRENT=`pwd`

##### Install Makefile and Cached
sudo apt-get install -y make
# Cache for GCC
cd /tmp
wget http://samba.org/ftp/ccache/ccache-3.2.2.tar.gz
tar -xvf ccache-3.2.2.tar.gz
cd ccache-3.2.2
./configure && make && make install
# Symlink gcc
cp ccache /usr/local/bin/
ln -s ccache /usr/local/bin/gcc
ln -s ccache /usr/local/bin/g++
ln -s ccache /usr/local/bin/cc
ln -s ccache /usr/local/bin/c++
rm -rf /tmp/ccache-3.2.2

##### Configure for Nginx
sudo apt-get install -y libpcre3-dev libpcre++-dev openssl
cd $CURRENT
cd nginx
chmod +x configure
./configure \
	--prefix=/opt/nginx \
	--sbin-path=/usr/sbin/nginx \
	--conf-path=/opt/nginx/nginx.conf \
	--pid-path=/var/run/nginx.pid \
	--lock-path=/var/run/nginx.lock \
	--with-http_ssl_module \
	--add-module=../src;
cd ..

