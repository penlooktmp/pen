#!/bin/bash
##### Install Makefile and Cached
sudo apt-get install -y make dsniff

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
sudo apt-get update
sudo apt-get install -y libpcre3 libpcre3-dev libpcre++-dev openssl libssl-dev libcurl4-openssl-dev
cd $CURRENT
chmod +x config.sh
./config.sh
mkdir -p /var/log/nginx
cd ..