/**
 * Pengo Project
 *
 * Copyright (c) 2015 Penlook Development Team
 *
 * --------------------------------------------------------------------
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * Author:
 *     Loi Nguyen       <loint@penlook.com>
 */

#include <sys/core.h>
#include <http/http.h>
#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <app/toolbar.h>

using namespace http;

void makeDevelopment(string app = "")
{
	executeCommand("sync && echo 3 > /proc/sys/vm/drop_caches");
	executeCommand("pkill pendev");
	executeCommand("service nginx stop");

	string cwd = getCwd();
	if (app.length() > 0) {
		cwd += "/" + app;
	}
	changeDirectory(cwd + "/build/development");
	HttpRequest proxyRequest;
	HttpResponse proxyResponse;
	Http server(proxyRequest, proxyResponse);
	server.get("/", [](Request* _request, Response* _response) {

		FILE *in;
		Debug debug;
		char buf[1024];
		
		if (!(in = popen("./build.sh", "r"))) {
			return;
		}

		while (fgets(buf, sizeof(buf), in) != NULL) {
			string buffer(buf);
			debug.addBuffer(buffer);
			debug.addErrorPattern()
			cout << buffer << "\n";
			if (isMatch(buffer, "[a-zA-Z0-9/.]+:[0-9]+:[0-9]+:.*")) {
				_response->body << buffer;
				pclose(in);
				break;
			}
			
			if (buffer == "Listening on port 8080") {
				_response->body << getHttpContent("http://localhost:8080/");
				pclose(in);
				break;
			}
		}
	});
	server.listen(80);
}

void makeProduction(string app = "")
{
	executeCommand("pkill pendev");

	string cwd = getCwd();
	if (app.length() > 0) {
		cwd += "/" + app;
	}
	changeDirectory(cwd + "/build/production");
	executeCommand("./config.sh");
	int ret = executeCommand("./build.sh");
	cout << ret;
	cout.flush();
}