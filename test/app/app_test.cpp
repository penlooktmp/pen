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
#include <app/app.h>

using namespace app;

class AppTest : public ::testing::Test
{
	protected:
		virtual void SetUp() {}
		virtual void TearDown() {}
};

TEST_F(AppTest, handleCommand)
{
    char command[] = "Index Home int id string password int a bool b string c";
    char **com = str_split(command, " ");
	char  *controllerName = com[0];
	char  *actionName = com[1];
    EXPECT_EQ(12, len(com));
    EXPECT_EQ("Index", string(controllerName));
    EXPECT_EQ("Home", string(actionName));

    char **actionArgs = seg(com, 3, 7);
    EXPECT_EQ(5, len(actionArgs));
}

/*
TEST_F(AppTest, appResponse)
{
    App *app = new App;
    HttpRequest *request = new HttpRequest();
    HttpResponse *response = new HttpResponse();
    Model *model = new Model;

    /*
    response->setBody((char*) "<html></html>");

    char command[] = "Index Home int id string password";
    app->setHttpRequest(request)
       ->setHttpResponse(response)
       ->setModel(model)
       ->handleCommand(command);

    char const *args[] = { "int", "id", "string", "password", '\0' };
    int len_args = len((char**) args);
    EXPECT_EQ("Index", string(app->getController()->getName()));
    EXPECT_EQ("Home", string(app->getController()->getAction()->getName()));

    char **action_args = app->getController()->getAction()->getArgument();    
    EXPECT_EQ(len_args, len(action_args));
    for (int i=0; i<len_args; i++) {
      EXPECT_EQ(string(args[i]), string(action_args[i]));
    }
    EXPECT_EQ("<html></html>", string(app->getHttpResponse()->getBody()));
    delete app;
}*/