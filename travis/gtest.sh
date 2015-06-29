#!/bin/bash
#
# Pengo Project
#
# Copyright (c) 2015 Penlook Development Team
#
# --------------------------------------------------------------------
#
# This program is free software: you can redistribute it and/or
# modify it under the terms of the GNU Affero General Public License
# as published by the Free Software Foundation, either version 3
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public
# License along with this program.
# If not, see <http://www.gnu.org/licenses/>.
#
# --------------------------------------------------------------------
#
# Authors:
#     Loi Nguyen       <loint@penlook.com>

# Google C++ Testing Framework
sudo apt-get install unzip
cd /tmp
wget https://googletest.googlecode.com/files/gtest-1.7.0.zip
unzip gtest-1.7.0.zip
cd gtest-1.7.0
GTEST=/usr/lib/gtest
sudo mkdir $GTEST $GTEST/include $GTEST/lib
./configure --prefix=$GTEST
make
sudo cp -a include/gtest/ $GTEST/include
sudo cp -a lib/.libs/* $GTEST/lib
sudo cp -a lib/libgtest.la $GTEST/lib
sudo cp -a lib/libgtest_main.la $GTEST/lib
sudo ln -s $GTEST/lib/libgtest.so.0 /usr/lib/libgtest.so.0
sudo ln -s $GTEST/lib/libgtest_main.so.0 /usr/lib/libgtest_main.so.0
ldconfig
cd /tmp
rm -rf gtest-1.7.*