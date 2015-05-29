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
#include <cli/handler.h>
#include <http/http.h>

using namespace std;
using namespace http;

namespace cli {

	void Handler::create(string name)
	{
		//Creator creator = Creator(name);
	}
	
	// Unit test
	// Benchmark
	void Handler::test(string type)
	{
		cout << "Test pengo application";
	}
	
	// Debug application components
	void Handler::debug(string mode)
	{
		cout << "Debug mode";
	}
	
	// Build application
	void Handler::build(string mode)
	{	
		makeProduction();
	}
	
	// Run application under hot-code reload
	void Handler::run(string mode)
	{	
		HttpRequest _request;
		HttpResponse _response;
		Http proxy(_request, _response);
		proxy.get("/", [](Request* request, Response* response) {
			makeDevelopment();
			response->body << getHttpContent("192.168.250.250:8080");
		});
		proxy.listen(80);
	}
	
	void Handler::help(string doc)
	{
		cout << "Pengo help !";
	}
 
}