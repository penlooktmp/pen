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

import argparse

from create import *
from build import *
from debug import *
from test import *
from run import *

class Cli:

	def __init__(self):
		self.parser  = argparse.ArgumentParser(
			prog = 'pen',
			description = "Pen-cli for pen project manipulation",
			usage = '%(prog)s [subcommand] [parameter]',
			#help = False
		)

	def setupCommand(self):
		subcommand = self.parser.add_subparsers()

		parser_new = subcommand.add_parser('new', help = 'Create new application or component')
		parser_new.add_argument('name', metavar = "name", help = "application or component name", type = str, action = Create)

		parser_run = subcommand.add_parser('run', help = 'Develop application using hot-code reload')
		parser_run.add_argument('app_directory', default = "", metavar = "app_directory", help = "application directory", type = str, action = Run)

		parser_build = subcommand.add_parser('build', help = 'Build application as Nginx module')
		parser_build.add_argument('app_directory', default = "", metavar = "app_directory", help = "application directory", type = str, action = Build)

		parser_debug = subcommand.add_parser('debug', help = 'Debug application or component structure')
		parser_debug.add_argument('app_component',
			choices = ["router", "controller", "view", "model", "test"], 
			metavar = "app_component", help = "application component", type = str, action = Debug)

		parser_test = subcommand.add_parser('test',  help = 'Run unit - integration test')
		parser_test.add_argument('app_component', choices = ["unit", "benchmark"], nargs = "*", default = "unit", metavar = "app_component", help = "Application component", type = str, action = Test)
		
		self.args = self.parser.parse_args()

	def parse(self):
		self.setupCommand()
