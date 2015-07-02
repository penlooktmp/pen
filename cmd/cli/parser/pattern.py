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

	ANNOTATION   		= '\\@[A-Z]{1}[a-zA-Z0-9]+[\\s]+[\\w\\/\\:\"\\s]+'
	CLASS        		= '^class[\s]+[a-zA-Z]+'
	PROPERTY     		= '^[a-z\s]+[a-zA-Z]+(\;|([a-zA-Z0-9\s=&]+\;))'
	METHOD       		= '^[a-z\s]+[a-zA-Z]+\(|([\a-zA-Z0-9\*\&\s,=]+)\)\;'
	TEMPLATE_VAR 		= '[a-zA-Z0-9_\&]+[\s]+\$[a-zA-Z0-9]+(\;|([a-zA-Z0-9\s=&]+\;))'
	COMMENT      		= '^\/\/.+'
	PUBLIC	 	 		= '^public.+'
	PRIVATE		 		= '^private.+'
	PROTECTED			= '^protected.+'
	END_WITH_BRACKET 	= '.+\{'

	def __init__(self):
		self.match = False
		self.context = None

	def setContext(self, context):
		self.context = context

	def isMatch(self, pattern):
		if self.context is None:
			print 'Context can not be none'
			exit()
		self.match = re.match(pattern, self.context.line)
		if self.match is not None:
			return True
		return False

	def isHeader(self):
		if self.context.line.startswith("#include"):
			return True
		if self.context.line.startswith("using"):
			self.context.line += ";"
			return True
		if self.context.line.startswith("template"):
			return True
		return False

	def isComment(self):
		return self.isMatch(self.COMMENT)

	def isAnnotation(self):
		return self.isMatch(self.ANNOTATION)

	def isClass(self):
		return self.isMatch(self.CLASS)

	def isProperty(self):
		return self.isMatch(self.PROPERTY)

	def isMethod(self):
		return self.isMatch(self.METHOD)

	def isTemplateVariable(self):
		return self.isMatch(self.TEMPLATE_VAR)

	def isProtected(self):
		return self.isMatch(self.PROTECTED)

	def isPrivate(self):
		return self.isMatch(self.PRIVATE)

	def isPublic(self):
		return self.isMatch(self.PUBLIC)
	
	def isEndWithBracket(self):
		return self.isMatch(self.END_WITH_BRACKET)