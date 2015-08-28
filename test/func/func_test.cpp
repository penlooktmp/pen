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
#include <sys/type.h>

using namespace std;
using namespace app;

class FuncTest : public Test {};

TEST_F(FuncTest, len)
{
	// Length of char pointer
	char *char_pointer = (char*) "Hello world";
	int lenght_char_pointer = len(char_pointer);
	EXPECT_EQ(11, lenght_char_pointer);
	
	// Length of char pointer array
	const char *char_pointer_array_raw[] = { "abc", "abd", "abf", "abe", "mnl", '\0' };
	char **char_pointer_pointer = (char**) char_pointer_array_raw;
	int lenght_char_pointer_pointer = len(char_pointer_pointer);
	EXPECT_EQ(5, lenght_char_pointer_pointer);
	
	// Length of number
	int number_int = 123456789;
	int length_number_int = len(number_int);
	EXPECT_EQ(9, length_number_int);

	// Length of int pointer array
	int int_pointer[] = { 1, 2, 3, 4, 5, '\0' };
	int *int_pointer_pointer = (int*) int_pointer;
	int length_int_pointer_pointer = len(int_pointer_pointer);
	EXPECT_EQ(5, length_int_pointer_pointer);
	
	// Length of map
	//map<any, any> map_input;
	//map_input[string("abc")] = string("hello");
	//map_input["abd"] = "hello";
	//map_input["abf"] = "hello";
	//map_input["abe"] = "hello";
	//map_input["abh"] = "hello";
	//int lenght_map = len(map_input);
	//EXPECT_EQ(0, lenght_map);
}

TEST_F(FuncTest, str)
{
	// Char pointer
	char const *sample = "Hello world";
	char *char_pointer0 = str((char*) sample);
	EXPECT_EQ("Hello world", string(char_pointer0));

	// Const char pointer
	char *char_pointer1 = str("Hello world");
	EXPECT_EQ("Hello world", string(char_pointer1));
	
	// Short
	/*char *char_pointer2= str(123);
	EXPECT_EQ("123", string(char_pointer2));

	// Float
	char *char_pointer3 = str(123.0345);
	EXPECT_EQ("123.0345", string(char_pointer3));

	// Long
	char *char_pointer4 = str(123456789012345);
	EXPECT_EQ("123456789012345", string(char_pointer4));
	*/
}

TEST_F(FuncTest, seg)
{
	// Length of char pointer
	const char *char_const_pointer = "Hello world";
	char *char_pointer = (char*) char_const_pointer;
	char *seg_char_pointer1 = seg(char_pointer, 6, 10);
	EXPECT_EQ("world", string(seg_char_pointer1));

	// Length of char pointer
	char *seg_char_pointer2 = seg("Hello world", 6, 10);
	EXPECT_EQ("world", string(seg_char_pointer2));

	// Length of char pointer pointer
	char const* seg_char_const_pointer_pointer[] = { "abc", "abd", "abf", "abh", "xyz", "yuz", "pol", '\0' };
	char const* seg_char_const_pointer_pointer_expect[] = { "abf", "abh", "xyz", "yuz", '\0'};
	char **seg_char_pointer_pointer = (char**) seg_char_const_pointer_pointer;
	char **result_pointer_pointer = seg(seg_char_pointer_pointer, 2, 5);
	EXPECT_EQ(4, len(result_pointer_pointer));
	int len_expect = len((char**) seg_char_const_pointer_pointer_expect);
	EXPECT_EQ(4, len_expect);
	for (int i=0; i<len_expect; i++) {
		EXPECT_EQ(string(seg_char_const_pointer_pointer_expect[i]), string(result_pointer_pointer[i]));
	}

	// Length of char pointer pointer
	char const* seg_char_const_pointer_pointer2[] = { "abc", "abd", "abf", '\0' };
	char **seg_char_pointer_pointer2 = (char**) seg_char_const_pointer_pointer2;
	char **result_pointer_pointer2 = seg(seg_char_pointer_pointer2, 0, 1);
	EXPECT_EQ(2, len(result_pointer_pointer2));
}

TEST_F(FuncTest, join)
{
	// Length of char pointer
	char const*char_const_pointer_join[] = {
		"<html>", "<body>", "</body>", "</html>", '\0'
	};
	char *html_join = join((char**) char_const_pointer_join);
	EXPECT_EQ("<html><body></body></html>", string(html_join));
	EXPECT_EQ(26, len(html_join));

	char const*char_const_pointer_join_delim[] = {
		"<html>", "<body>", "</body>", "</html>", '\0'
	};
	char *html_jon_delim = join((char**) char_const_pointer_join_delim, " ");
	EXPECT_EQ("<html> <body> </body> </html>", string(html_jon_delim));
	EXPECT_EQ(29, len(html_jon_delim));
}

TEST_F(FuncTest, add)
{
	// Length of char pointer
	char const *char_const_pointer_join[] = {
		"<html>", "<body>", "</body>", "abc", '\0'
	};
	char **html_raw = (char**) char_const_pointer_join;
	char **html_list = add(html_raw, " </html>");
	char *html = join(html_list);
	EXPECT_EQ("<html><body></body>abc </html>", string(html));
}

class Sample
{
	
};

TEST_F(FuncTest, freeVector)
{
	vector<Sample*> stack;	
	stack.push_back(new Sample());
	stack.push_back(new Sample());
	stack.push_back(new Sample());
	EXPECT_EQ(3, stack.size());
	free(stack);
	EXPECT_EQ(0, stack.size());
	
	map<string, Sample*> hash;
	hash["a"] = new Sample();
	hash["b"] = new Sample();
	hash["c"] = new Sample();
	EXPECT_EQ(3, hash.size());
	free(hash);
	EXPECT_EQ(0, hash.size());
}

TEST_F(FuncTest, freeMap)
{
	vector<Sample*> stack;
	stack.push_back(new Sample());
	stack.push_back(new Sample());
	stack.push_back(new Sample());
	EXPECT_EQ(3, stack.size());
	free(stack);
	EXPECT_EQ(0, stack.size());
}