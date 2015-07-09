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

#include <app/test.h>
#include <http/http.h>

using namespace std;
using namespace app;

class HttpTest : public Test {};

void app_handler(App* app)
{
	app->getHttpResponse()->setBody((char*) "<html><body>TEST</body></html>");
}

TEST_F(HttpTest, serveRequest)
{
	Http *http = new Http;
	http->setCommand((char*) "Index Home int a int b")
    	->serveRequest(app_handler);
	HttpResponse *response = http->getResponse();
	EXPECT_EQ("<html><body>TEST</body></html>", string(response->getBody()));
	EXPECT_EQ(30, response->getBodyLength());
	delete http;
}
