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

import re
import os

class Pattern:

	ANNOTATION  = '\\@[A-Z]{1}[a-zA-Z0-9]+[\\s]+[\\w\\/\\:\"\\s]+'
	CLASS       = '^class[\s]+[a-zA-Z]+'
	PROPERTY    = '^[a-z\s]+[a-zA-Z]+(\;|([a-zA-Z0-9\s=&]+\;))'
	METHOD      = '^[a-z\s]+[a-zA-Z]+\(|([\a-zA-Z0-9\*\&\s,=]+)\)\;'
	TEMPLATE    = '[a-zA-Z0-9_\&]+[\s]+\$[a-zA-Z0-9]+(\;|([a-zA-Z0-9\s=&]+\;))'
	
	def __init__(self, line):
		self.line = line
	def isMatch(self, pattern):
		pass
	def isAnnotation(self):
		pass
	def isClass(self):
		pass
	def isProperty(self):
		pass
	def isMethod(self):
		pass
	def isTemplateVariable(self):
		pass
	def isModel(self):
		pass