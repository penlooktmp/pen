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

import  re

class Template:
	
	def __init__ (self):
		self.templateFilePath = ""
		self.templateCPP = """
// AUTO GENERATED
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
using namespace std;
namespace View {

template <typename T>
string output(T variable) {
	if (typeid(variable).name() == "PKc") {
		return variable;
	} else return "Unknown type";
}

void {{ fileName }}(map<string, string> data) {
{{ htmlContent }}
}}
		"""

	def setTemplate(self, filePath):
		self.templateFilePath = filePath
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
		return content

	def renderVolt(self, template):
		return template
	
	def compileTemplate(self, template):
		template = self.renderVolt(template)
		lines = re.split("\n", template)
		content = 'cout <<'
		for line in lines:
			line = line.strip()
			content += '"' + line + '\\n"\n\r<<'
		content += '"";'
		return content

	def render(self, template):
		return self.renderString(self.templateCPP, {
			'fileName' : 'index_html',
			'htmlContent' : self.compileTemplate(template)
		}) + """\
int main() {
	map<string, string> data;
	View::index_html(data);
	return 0;
}"""

	def compile(self):
		cpp = open(self.templateFilePath + ".cpp", 'w')
		html = ''
		with open(self.templateFilePath + ".html", "r") as lines:
			for line in lines:
				html += line;
		cpp.write(self.render(html))
			
view = Template()
view.setTemplate("template/index")
view.compile();


		