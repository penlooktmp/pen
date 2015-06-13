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

#include <iostream>
#include <app/app.h>

using namespace std;
using namespace http;

// Mockup Nginx server
int main()
{
	HttpRequest proxyRequest;
	HttpResponse proxyResponse;
	Http server(proxyRequest, proxyResponse);
	server.get("/", [](Request* _request, Response* _response) {
		cout << "New request";
		cout.flush();
		HttpRequest request;
		HttpResponse response;
		Http http(request, response);
		http.process();
		cout << http.getResponse().getBody();
		cout.flush();
		_response->body << http.getResponse().getBody();
	});
	server.listen(8080);
	return 0;
}