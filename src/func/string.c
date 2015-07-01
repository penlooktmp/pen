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

#define MAX_SIZE 1000000

// Lenght of pointer array
int count(char **target)
{
	register int count = 0;
	while (*target++) ++count;
	return count;
}

// Find and replace
char  *replace(const char *target, const char* find, const char* replace_with)
{
	char *result;
	int i, count = 0;
	int newlen = strlen(find);
	int oldlen = strlen(replace_with);

	for (i = 0; target[i] != '\0'; i++)
	{
		if (strstr(&target[i], find) == &target[i]) 
		{
			count++;
			i += oldlen - 1;
		}
	}
	result = (char*) malloc(i + count * (newlen - oldlen));
	if (result == NULL) {
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (*target)
	{
		if (strstr(target, find) == target)
		{
			strcpy(&result[i], replace_with);
			i += newlen;
			target += oldlen;
		} else result[i++] = *target++;
	}
	result[i] = '\0';
	return result;
}

// Split string to one dimession array
char **split(char* target, char* delimiter)
{
	int max = 100;
	char** data = (char**) calloc(max, sizeof(char*));
	
	return data;
}

// Join string with delimiter
char *join(char *target[], char *delimiter)
{
	int num = count(target) - 1;
	int len = 0, wlen = 0;
	char *tmp = calloc(MAX_SIZE, sizeof(char));
	for (int i=0; i<num; i++) {
		// Copy memory segment
		wlen = strlen(target[i]);
		memcpy(tmp + len, target[i], wlen);
		len += wlen;
		// Copy memory segment
		wlen = strlen(delimiter);
		memcpy(tmp + len, delimiter, wlen);
		len += wlen;
	}
	// Copy memory segment
	wlen = strlen(target[num]);
	memcpy(tmp + len, target[num], wlen);
	len += wlen;
	len += 1;
	// Saving memory
	char *result = calloc(len, sizeof(char));
	memcpy(result, tmp, len);
	// Deallocate memory
	free(tmp);
	return result;
}

// Trim all space left and right
char *trim(char *target)
{
	int len, left, right;
	left = 0;
	right = strlen(target) - 1;
	while (target[left] == ' ') left++;
	while (target[right] == ' ') right--;
	len = right - left + 1;
	char *result = calloc(len, sizeof(char));
	memcpy(result, &target[left], len);
	return result;
}
