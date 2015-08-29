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
#include <sys/type.h>
#include <app/view.h>

using namespace std;
using namespace app;

class ViewTest : public Test {};

TEST_F(ViewTest, ViewDataClass)
{
	ViewData *data = new ViewData;
	data->set<char*>("test1", (char*) "Hello World");
	EXPECT_EQ("Hello World", string(data->get<char*>("test1")));
	data->set<int>("test2", 3);
	EXPECT_EQ(3, int(data->get<int>("test2")));
	data->set<bool>("test3", true);
	EXPECT_EQ(true, int(data->get<bool>("test3")));
	delete data;
}

TEST_F(ViewTest, ViewViewData)
{
	View *view = new View();
	view->getData()->set<char*>("title", (char*) "Hello");
	EXPECT_EQ("Hello", string(view->getData()->get<char*>("title")));
	delete view;
}

TEST_F(ViewTest, SetGetContent)
{
	EXPECT_EQ("Test", "Test");
}