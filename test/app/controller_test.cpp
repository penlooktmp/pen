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
#include <app/controller.h>

using namespace std;
using namespace app;

class ControllerTest : public Test {};

TEST_F(ControllerTest, Action)
{
	Action *action = new Action;
	map<const char*, char*> data;
	data["title"] = (char*) "abc";
	action->setName((char*) "Index")
		  ->setData(data);
	EXPECT_EQ("Index", action->getName());
	EXPECT_EQ("abc", action->getData()["title"]);
	delete action;
}

TEST_F(ControllerTest, Controller)
{
	Action *action = new Action;
	map<const char*, char*> data;
	data["title"] = (char*) "abc";
	action->setName((char*) "Home")
		  ->setData(data);

	Controller *controller = new Controller;
	controller->setName((char*) "Index")
			  ->setAction(action);
	EXPECT_EQ("Index", controller->getName());
	EXPECT_EQ("Home", controller->getAction()->getName());
	delete controller;
}