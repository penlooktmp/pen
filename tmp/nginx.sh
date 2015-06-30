NGINX="1.9.2"
cd ../app/build/production
wget https://github.com/nginx/nginx/archive/release-$NGINX.tar.gz
tar -xvf release-$NGINX.tar.gz; mv nginx-release-$NGINX nginx