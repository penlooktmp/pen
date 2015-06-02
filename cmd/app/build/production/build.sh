#!/bin/bash
CURRENT=`pwd`

lf() {
	cp $1 $1_2
	tr -d '\r' < $1_2 > $1
	rm -rf $1_2
}

clear
cd nginx
make
make install
cp -rf ../config/nginx.conf /etc/nginx/nginx.conf
cp -rf ../config/nginx /etc/init.d/nginx
lf /etc/init.d/nginx
service nginx reload
pkill nginx
service nginx restart
netstat -tulpn | grep nginx