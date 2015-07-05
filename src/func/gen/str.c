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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <func/gen/len.h>

char *string_pointer_char(char *target)
{
	return target;
}

char *string_pointer_constant_char(const char *target)
{
	return (char*) target;
}

//int len_num = length_number_##TYPE(target);
#define NUM_STR(TYPE); \
char* string_number_##TYPE(TYPE target) {\
	char *string = calloc(10, sizeof(char));\
	return string;\
}

NUM_STR(short);
NUM_STR(int);
NUM_STR(long);
NUM_STR(double);
NUM_STR(float);