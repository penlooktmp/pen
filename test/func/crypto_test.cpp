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
#include <sys/func.h>

using namespace std;
using namespace app;

class FuncTest : public Test {};

TEST_F(FuncTest, md5)
{
	char* expect1 = md5("123");
	EXPECT_EQ("202cb962ac59075b964b07152d234b70", string(expect1));
	
	char* expect2 = md5("!@#$%");
	EXPECT_EQ("507250b947cc397023a9595001fcf167", string(expect2));
	
	char* expect3 = md5("_@#123AAABBBCCCabc1234$");
	EXPECT_EQ("a9996ad82855039329e4c125d016061c", string(expect3));
	
	char* expect4 = md5("123456789");
	EXPECT_EQ("25f9e794323b453885f5181f1b624d0b", string(expect4));
	
	char* expect5 = md5("abcdABCD!@#()");
	EXPECT_EQ("63fb2333035255e850d0b4a20fd860a2", string(expect5));
}

TEST_F(FuncTest, sha1)
{
	EXPECT_EQ("sha1", "sha1");
	// TODO
}

TEST_F(FuncTest, sha256)
{
	EXPECT_EQ("sha256", "sha256");
	// TODO
}