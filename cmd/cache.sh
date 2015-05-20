# Cache for GCC
wget http://samba.org/ftp/ccache/ccache-3.2.2.tar.gz
tar -xvf ccache-3.2.2.tar.gz
cd ccache-3.2.2/
./configure && make && make install && make test
#Symlink gcc
cp ccache /usr/local/bin/
ln -s ccache /usr/local/bin/gcc
ln -s ccache /usr/local/bin/g++
ln -s ccache /usr/local/bin/cc
ln -s ccache /usr/local/bin/c++