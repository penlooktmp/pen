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
sudo mkdir /opt/gtest /opt/gtest/include /opt/gtest/lib
./configure --prefix=/opt/gtest
make
sudo cp -a include/gtest/ /opt/gtest/include
sudo cp -a lib/.libs/* /opt/gtest/lib
rm /opt/gtest/lib/libgtest.la
rm /opt/gtest/lib/libgtest_main.la
sudo cp -a lib/libgtest.la /opt/gtest/lib
sudo cp -a lib/libgtest_main.la /opt/gtest/lib