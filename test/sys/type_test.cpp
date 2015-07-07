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
#include <sys/type/typeof.h>

using namespace std;
using namespace app;

class TypeTest : public Test {};

/*
TEST_F(TypeTest, type_char)
{
	char a_char = 'a';
	string type_char = typeof(a_char);
	EXPECT_EQ("char", type_char);

	char *a_char_pointer = (char*) "Hello world";
	string type_char_pointer = typeof(a_char_pointer);
	EXPECT_EQ("char*", type_char_pointer);

	char *a_char_pointer_pointer_raw[] = { (char*) "abc", (char*) "abd", (char*) "abf" };
	char **a_char_pointer_pointer = (char**) a_char_pointer_pointer_raw;
	string type_char_pointer_pointer = typeof(a_char_pointer_pointer);
	EXPECT_EQ("char**", type_char_pointer_pointer);
}

TEST_F(TypeTest, type_string)
{
	string a_string = "Hello World";
	string type_char = typeof(a_string);
	EXPECT_EQ("string", type_char);

	string a_string_pointer_raw[] = { "abc", "abd", "abf" };
	string *a_string_pointer = (string*) a_string_pointer_raw;
	string type_string_pointer = typeof(a_string_pointer);
	EXPECT_EQ("string*", type_string_pointer);
}

TEST_F(TypeTest, type_int)
{
	int a_int = 2;
	string type_int = typeof(a_int);
	EXPECT_EQ("int", type_int);

	int a_int_pointer_raw[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *a_int_pointer = (int*) a_int_pointer_raw;
	string type_int_pointer = typeof(a_int_pointer);
	EXPECT_EQ("int*", type_int_pointer);
}
*/