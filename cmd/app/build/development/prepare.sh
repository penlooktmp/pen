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

ROOT_INCLUDE=`readlink -e ../../../../`
ROOT_LOCAL=`readlink -e ./`
ROOT_RAM=$ROOT_LOCAL/tmp

# Mount source code to ram disk

[ -d $ROOT_RAM ] && umount -v $ROOT_RAM > /dev/null
/sbin/mke2fs -q -m 0 /dev/ram0
/bin/mount /dev/ram0 $ROOT_RAM
/bin/chown root:root $ROOT_RAM
/bin/chmod 0750 $ROOT_RAM

mkdir -p $ROOT_RAM/inc
mkdir -p $ROOT_RAM/src
mkdir -p $ROOT_RAM/main