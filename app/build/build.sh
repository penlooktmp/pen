#!/bin/bash
clear
cd nginx
make -j
make install > /dev/null
cp -rf ../config/nginx.conf /etc/nginx/nginx.conf
cp -rf ../config/nginx /etc/init.d/nginx
service nginx reload
service nginx restart