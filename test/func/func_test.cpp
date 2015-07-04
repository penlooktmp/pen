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
#include <func/core.h>

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
	// TODO
	// int number_int = 123456789;
	// int length_number_int = len(number_int);
	// EXPECT_EQ(9, length_number_int);

	// Length of int pointer array
	int int_pointer[] = { 1, 2, 3, 4, 5, '\0' };
	int *int_pointer_pointer = (int*) int_pointer;
	int length_int_pointer_pointer = len(int_pointer_pointer);
	EXPECT_EQ(5, length_int_pointer_pointer);
}