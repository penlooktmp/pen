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

TEST_F(FuncTest, sub)
{
	// Length of char pointer
	const char *char_const_pointer = "Hello world";
	char *char_pointer = (char*) char_const_pointer;
	char *seg_char_pointer1 = seg(char_pointer, 6, 10);
	EXPECT_EQ("world", string(seg_char_pointer1));
	
	// Length of char pointer
	char *seg_char_pointer2 = seg("Hello world", 6, 10);
	EXPECT_EQ("world", string(seg_char_pointer2));
}

TEST_F(FuncTest, join)
{
	// Length of char pointer
	char const*char_const_pointer_join[] = {
		"<html>", "<body>", "</body>", "</html>", '\0'
	};
	char *html_join = join((char**) char_const_pointer_join);
	EXPECT_EQ("<html><body></body></html>", string(html_join));
	
	char const*char_const_pointer_join_delim[] = {
		"<html>", "<body>", "</body>", "</html>", '\0'
	};
	char *html_delim = join((char**) char_const_pointer_join_delim, " ");
	EXPECT_EQ("<html> <body> </body> </html>", string(html_delim));
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