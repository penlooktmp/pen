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

// Lenght of pointer array
int len(char* target[])
{
	register int count = 0;
	while (*target++) {++count;}
	return count;
}

// Split string to one dimession array
char** split(char* target, char* delimiter)
{
	int max = 100;
	char** data = (char**) calloc(max, sizeof(char*));
	data[0] = "abc";
	data[1] = "abd";
	data[2] = "abf";
	return data;
}

void echo()
{
	printf("Hello %s", "World");
}
