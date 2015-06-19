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

class Controller:

	def __init__(self):
		pass

	def setInput(self, targetDir):
		self.Input = targetDir
		return self
	
	def setOutput(self, destDir):
		self.Output = destDir
		return self
	
	def compileLine(self):
		self.headerContent += self.line + "\n"

	def compileFile(self, filePath):
		fileName = filePath.split(".")[0]
		self.controllerName = fileName.split("/")[-1]
		targetPath = self.Input + "/" + fileName + ".cpp"
		destHeaderPath = self.Output + "/" + fileName + ".h"
		destCppPath = self.Output + "/" + fileName + ".cpp"
		
		self.headerContent = ''
		self.cppContent = '#include "'+ self.controllerName + '.h"\n'

		# Compile file
		with open(targetPath, "r") as lines:
			for line in lines:
				line = line.strip()
				if len(line) > 0 :
					self.line = line
					self.compileLine()

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