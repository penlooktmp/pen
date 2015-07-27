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
#include <sys/type/any.h>

using namespace std;
using namespace app;

class AnyTest : public Test {};

TEST_F(AnyTest, TypeCasting)
{
	any a = "Hello World";
	EXPECT_EQ("Hello World", a.cast<const char*>());
	any b = string("Hello World");
	EXPECT_EQ(string("Hello World"), b.cast<string>());
	any c = 3;
	EXPECT_EQ(3, c.cast<int>());
	any d = true;
	EXPECT_EQ(true, d.cast<bool>());
}
