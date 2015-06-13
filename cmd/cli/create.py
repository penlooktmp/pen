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
import os

#$ pen create app
#$ pen create controller:index
#$ pen create database-entity
#$ pen create view/template
class Create(argparse.Action):

	def createApplication():
		print 'Create pen application'

	def createAction():
		print 'Create pen controller'

	def createEntity():
		print 'Create pen entity'

	def createTemplate():
		print 'Create pen view'

	def __call__(self, parser, args, values, option_string = None):
		print 'Create', values
		#if len(values) == 2 :
			#com = values[1]
			#print "Create new", com
			# TODO
			# Component creation
		#else :
		#	os.system('pen -h')

