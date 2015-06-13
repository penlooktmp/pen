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
from os import *
import SimpleHTTPServer
import SocketServer

#$ pen run
#$ pen run app
class Run(argparse.Action):
	def __call__(self, parser, args, values, option_string = None):
		cwd = getcwd();
		
		if len(values) > 0 :
			cwd += "/" + values
		
		chdir(cwd + '/build/development')
		system("sync && echo 3 > /proc/sys/vm/drop_caches")
		system("pkill pendev")
		system("service nginx stop")
		system("./prepare.sh")

		PORT = 8000
		Handler = SimpleHTTPServer.SimpleHTTPRequestHandler
		httpd = SocketServer.TCPServer(("", PORT), Handler)
		print "serving at port", PORT
		httpd.serve_forever()

		#HttpRequest proxyRequest;
		#HttpResponse proxyResponse;
		#Http server(proxyRequest, proxyResponse);
		
		#server.get("/", [&cwd](Request* _request, Response* _response) {
		#	Debug debug;
		#	debug.setResponse(_response)
		#		 .setViewPath(cwd + "/view")
		#		 .compile();
		#});