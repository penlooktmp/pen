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
#include <func/string.h>

using namespace std;
using namespace app;

class StringTest : public Test {};

TEST_F(StringTest, count)
{
	// Constant string
	char const* data1[] = {
		"abc", "abd", "abf", "xyz", "123", "3456", '\0'
	};
	EXPECT_EQ(6, count((char**) data1));
	
	// Dynamic string
	int NUM = 135;
	char** data2 = (char**) calloc(NUM + 1, sizeof(char*));
	for (int i=0; i<NUM; i++) {
		data2[i] = (char*) "test";
	}
	data2[NUM] = '\0';
	EXPECT_EQ(NUM, count(data2));
}

TEST_F(StringTest, replace)
{
	char name[] = "xyz abc xyz 123 xyz !@# xyz";
	char *result1 = replace(name, "xyz", "456");
	EXPECT_EQ("456 abc 456 123 456 !@# 456", string(result1));
	// WRONG
	//char *result2 = replace(result1, "!", "0123");
	//EXPECT_EQ("abc 456 123 0123@#", string(result2));
}

TEST_F(StringTest, trim)
{
	char name1[] = "     Hello, this is string    ";
	char* result = trim(name1); 
	EXPECT_EQ("Hello, this is string", string(result));

	char name2[] = "     Hello, this is string";
	char* result2 = trim(name2);
	EXPECT_EQ("Hello, this is string", string(result2));

	char name3[] = "Hello, this is string    ";
	char* result3 = trim(name3);
	EXPECT_EQ("Hello, this is string", string(result3));
}

TEST_F(StringTest, join)
{
	char const* data1[] = {
		"abc", "abd", "abf", "xyz", "123", "3456", '\0'
	};
	char* result1 = join((char**) data1, (char*) "-");
	EXPECT_EQ("abc-abd-abf-xyz-123-3456", string(result1));
}