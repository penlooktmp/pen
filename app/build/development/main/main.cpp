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

#include <http/http.h>

using namespace http;

// Mockup Nginx server for development mode
int main()
{
	Http *proxy = new Http;
	proxy->get("/", [](Request* proxyRequest, Response* proxyResponse)
	{
		Http *http = new Http;
		http->setCommand((char*) "Index Home int a int b")
			->serveRequest(handler);
		HttpResponse *response = http->getResponse();
		proxyResponse->body << response->getBody();
	});
	proxy->listen(80);
	delete proxy;
	return 0;
}