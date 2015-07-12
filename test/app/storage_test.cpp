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
#include <app/controller.h>
#include <app/storage.h>

using namespace std;
using namespace app;

class StorageTest : public Test {};

ListController getControllers() {
	ListController controllers;
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

TEST_F(StorageTest, buildListMapping)
{
	Storage *storage = new Storage;
	storage->setControllers(getControllers());
	ListMapping mapping = storage->getListMapping();
	EXPECT_EQ(4, mapping.size());
}