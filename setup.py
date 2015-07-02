#!/usr/bin/python
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

from setuptools import setup, find_packages

setup(
	name='pen',
	version='1.0.0',
	description='Tools for pen application',
	url='https://github.com/penlook/pen',
	author='Nguyen Trung Loi <Steven Nguyen>',
	author_email='loint@penlook.com',
	license='GNU Affero General Public',
	scripts=['cmd/pen.py'],
	packages=find_packages(),
	install_requires=['MarkupSafe'],
    extras_require={
		'i18n': [
			'Babel>=0.8'
		]
	},
	entry_points = {
		'console_scripts': ['pen=cmd.pen:main'],
	},
	zip_safe = False
)