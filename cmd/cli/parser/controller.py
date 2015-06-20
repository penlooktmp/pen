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

# Controller parser

import os
import sys
from pattern import *

class Controller:

	def __init__(self):
		self.annotationStack = []
		self.lineStack = []
		self.currentClass = None
		self.currentMethod = None

		self.stackPublic = []
		self.stackPrivate = []
		self.stackProtected = []
		self.stackNonAccessModifier = []
		self.methodBlockContent = {}

	def setInput(self, targetDir):
		self.Input = targetDir
		return self
	
	def setOutput(self, destDir):
		self.Output = destDir
		return self
	
	def parseFile(self, targetPath):
		# Pattern recognition
		pattern = Pattern()
		pattern.setContext(self)
		# Compile file
		with open(targetPath, "r") as lines :
			for line in lines:
				line = line.strip()
				if len(line) > 0:
					self.line = line
					self.lineStack.append(line)
					if pattern.isComment():
						continue
					if pattern.isHeader():
						self.headerContent += line + "\n"
						print "IGNORE :", line
						continue
					if pattern.isAnnotation():
						# self.headerContent += line + "\n"
						print "ANNOTATION : ", line
						continue
					if pattern.isMethod():
						method_without_am = line
						am = False
						if pattern.isPublic():
							method_without_am = line.split('public')[1]
							self.stackPublic.append(property_without_am)
							am = True
							print "METHOD PUBLIC :", method_without_am
						if pattern.isPrivate():
							method_without_am = line.split('private')[1]
							self.stackPrivate.append(property_without_am)
							am = True
							print "METHOD PRIVATE :", method_without_am
						if pattern.isProtected():
							method_without_am = line.split('protected')[1]
							self.stackProtected.append(method_without_am)
							am = True
							print "METHOD PROTECTED :", method_without_am
						if am is False:
							self.stackNonAccessModifier.append(method_without_am)
						currentMethod = method_without_am
						continue
					if pattern.isProperty():
						am = False
						if pattern.isPublic():
							am = True
							property_without_am = line.split('public')[1]
							self.stackPublic.append(property_without_am)
							print "PROPERTY PUBLIC :", property_without_am
						if pattern.isPrivate():
							am = True
							property_without_am = line.split('private')[1]
							self.stackPrivate.append(property_without_am)
							print "PROPERTY PRIVATE :", property_without_am
						if pattern.isProtected():
							am = True
							property_without_am = line.split('protected')[1]
							self.stackProtected.append(property_without_am)
							print "PROPERTY PROTECTED :", property_without_am
						if am is False:
							self.stackNonAccessModifier.append(property_without_am)
						continue
					if pattern.isTemplateVariable():
						# self.headerContent += line + "\n"
						print "TEMPLATE :", line
						continue
					if pattern.isClass():
						if pattern.isEndWithBracket():
							line2_without_bracket = line.split('{')[0]
							print "CLASS WITHOUT BRACKET :", line2_without_bracket
							self.headerContent += line2_without_bracket + "\n"
						print "CLASS :", line
						continue

	def compileFile(self, filePath):
		fileName = filePath.split(".")[0]
		self.controllerName = fileName.split("/")[-1]
		targetPath = self.Input + "/" + fileName + ".cpp"
		destHeaderPath = self.Output + "/" + fileName + ".h"
		destCppPath = self.Output + "/" + fileName + ".cpp"

		self.headerContent = ''
		self.cppContent = '#include "'+ self.controllerName + '.h"\n'
		self.parseFile(targetPath)

		# Prepare to write
		header = open(destHeaderPath, 'w')
		cpp = open(destCppPath, 'w')

		# Write content to file
		header.write(self.headerContent)
		header.close()
		cpp.write(self.cppContent)
		cpp.close()
		
	def compile(self):
		controllers = os.listdir(self.Input)
		self.compileFile(controllers[0])