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

# Template parser

import re      # Regular expression
import os      # Operating system
from jinja2 import *

class View:

	PRODUCTION  = 0
	DEVELOPMENT = 1
	
	def __init__ (self):
		self.templateFilePath = ""
		self.templateH = """// AUTO GENERATED
#include <sys/type.h>
#include <sys/func.h>
#include <app/app.h>
namespace app {
namespace Template {
{{ headerContent }}
}\n}"""
		self.templateCPP = """// AUTO GENERATED
#include "view.h"
namespace app {
namespace Template {
void {{ fileName }}(App* app) {
char const *html[] = {
{{ htmlContent }}\'\\0\'
};
app->getHttpResponse()->setBody(join((char**)html, "\\n"));
}\n}\n}"""
		self.templateMain = ""
		self.listFileName = []
		self.listFolderPath = ['../main/', './']

	def setInput(self, inputViewFolder):
		self.Input = inputViewFolder
		return self
	
	def setOutput(self, outputViewFolder):
		self.Output = outputViewFolder
		if not os.path.isdir(self.Output):
			os.makedirs(self.Output)
		return self

	def setMode(self, mode):
		self.mode = mode
		return self

	def renderString(self, template, data):
		content = ''
		start = 0
		end = -1
		for match in re.finditer(r"\{\{[a-zA-Z0-9_\s]+\}\}", template):
			end = match.start()
			if start < end:
				content += template[start:end]
			start = end + 1
			var_block = template[match.start():match.end()]
			var = re.split("\s+", var_block)[1]
			if var in data:
				content += data[var]
			start = match.end()
		content += template[start:]
		content = content.replace('"', '\"')
		return content

	def renderVolt(self, template):
		return template

	def compileTemplate(self, template):
		template = self.renderVolt(template)
		lines = re.split("\n", template)
		if self.mode == self.DEVELOPMENT:
			content = ''
		else:
			content = '"'
		for line in lines:
			line = line.strip()
			line = line.replace('"', '\\"')
			if self.mode == self.DEVELOPMENT:
				content += '"' + line + '",'
			else:
				content += line
		if self.mode == self.PRODUCTION:
			content += '",'
		return content

	def render(self, template, relativePath):
		fileName = relativePath.replace("/", "_").split('.')[0]
		self.listFileName.append(fileName)
		return self.renderString(self.templateCPP, {
			'fileName' : fileName,
			'htmlContent' : self.compileTemplate(template)
		}) + self.templateMain

	def compileFile(self, target, destination):
		destinationAbsolutePath = self.Output + destination
		if not os.path.exists(os.path.dirname(destinationAbsolutePath)):
			os.makedirs(os.path.dirname(destinationAbsolutePath))
		cpp = open(destinationAbsolutePath, 'w')
		html = ''
		with open(target, "r") as lines:
			for line in lines:
				html += line
		cpp.write(self.render(html, destination))
		cpp.close()
		
	def compileHeader(self):
		headerContent = ''
		for fileName in self.listFileName:
			headerContent += 'void ' + fileName + '(App*);\n'
		headerContent = headerContent[:-1]
		viewH = self.renderString(self.templateH, {
			'headerContent' : headerContent,
		})
		for folderPath in self.listFolderPath:
			headerPath = self.Output + folderPath + 'view.h'
			header = open(headerPath, 'w')
			header.write(viewH)
			header.close()

	def scanDirectory(self, root, directory):
		listFiles = os.listdir(root)
		for item in listFiles:
			filePath = root + "/" + item
			if os.path.isfile(filePath):
				item = item.split('.')[0] + ".cpp"
				self.compileFile(filePath, directory + item)
			else:
				directory += item + "/"
				self.listFolderPath.append(directory)
				self.scanDirectory(filePath, directory)
				newDirectory = ""
				arrDirectory = directory.split('/')
				for index in range(0, len(arrDirectory) - 2):
					newDirectory += arrDirectory[index] + "/"
				directory = newDirectory

	def compile(self):
		self.Output += "/"
		self.scanDirectory(self.Input, "")
		self.compileHeader()