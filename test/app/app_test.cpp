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

#include <limits.h>
#include <gtest/gtest.h>
#include <http/http.h>
#include <app/app.h>

using namespace app;

class AppTest : public ::testing::Test
{
	protected:
		virtual void SetUp() {}
		virtual void TearDown() {}
};

TEST_F(AppTest, appResponse)
{
    App *app = new App;
    HttpRequest *request = new HttpRequest();
    HttpResponse *response = new HttpResponse();
    Storage *storage = new Storage;
    response->setBody((char*) "<html></html>");
    char hash[] = "2d62bde79116359c6c0fbbbcfcb17076";
    app->setHttpRequest(request)
       ->setHttpResponse(response)
       ->setStorage(storage)
       ->setHash(hash);
    delete app;
}

ControllerList getControllers_App() {
	ControllerList controllers;
	controllers["Home"] = (new Controller)
								->setName("Home")
								->addAction(
									(new Action)
										->setName("App")
										->setHash("c2f2ddf04a74c9720d2152696d539524")
										->addArgument(new ActionArgument("string","password"))
								)
								->addAction(
									(new Action)
										->setName("Index")
										->setHash("71e652f0fc1a125e06983055c6db9801")
								);
	controllers["Index"] = (new Controller)
								->setName("Index")
								->addAction(
									(new Action)
										->setName("Home")
										->setHash("dec2f7bd153e73f8e9691ffe33699ac9")
										->addArgument(new ActionArgument("string","password"))
								)
								->addAction(
									(new Action)
										->setName("About")
										->setHash("fb3526e803db091d112cc67e50dbd675")
								);
	return controllers;
}

TEST_F(AppTest, currentControllerAction)
{
	Storage *storage = new Storage;
	storage->setControllers(getControllers_App());
	App *app = new App;
	app->setStorage(storage)
	   ->setHash("c2f2ddf04a74c9720d2152696d539524");
	EXPECT_EQ(2, app->getControllers().size());
	EXPECT_EQ("c2f2ddf04a74c9720d2152696d539524", app->getHash());
	MappingList mapping = app->getStorage()->getMappingList();
	EXPECT_EQ(4, mapping.size());
	EXPECT_EQ(true, mapping.find("c2f2ddf04a74c9720d2152696d539524") != mapping.end());
	vector<string> com = mapping["c2f2ddf04a74c9720d2152696d539524"];
	EXPECT_EQ(2, com.size());
	EXPECT_EQ("Home", string(com[0]));
	EXPECT_EQ("App", string(com[1]));
	EXPECT_EQ("Home", app->getController()->getName());
	EXPECT_EQ("App", app->getAction()->getName());
	delete app;
}