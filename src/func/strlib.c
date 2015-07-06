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

#define MAX_SIZE 1000000

// Find and replace
char  *str_replace(const char *target, const char* find, const char* replace_with)
{
	char *result;
	register int i, count = 0;
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

// Split string to one dimession array by delimiter
char **str_split(char* target, const char *delim_)
{
	char* delim = (char*) delim_;
	int len_target = strlen(target);
	int len_delim = strlen(delim);
	int len_item = 0;
	char *segment = calloc(len_delim, sizeof(char));
	char **data = malloc(MAX_SIZE * sizeof(char*));
	register int i = 0, count = 0, from = 0, to = -1;
	// Compare delimiter per target segment
	while (i + len_delim < len_target) {
		memcpy(segment, &target[i], len_delim);
		// Found delimiter
		if (strcmp(segment, delim) == 0) {
			// Skip delimiter
			i += len_delim;
			// Not empty element
			if (to - from > 0) {
				len_item = to - from + 1;
				char* item = calloc(len_item, sizeof(char));
				memcpy(item, &target[from], len_item);
				// Append element to result
				data[count++] = item;
				from = i;
				to = i;
			}
		} else to++;
		i++;
	}
	if (len_target - from > 0) {
		len_item = len_target - from + 1;
		char* item = calloc(len_item, sizeof(char));
		memcpy(item, &target[from], len_item);
		// Append element to result
		data[count++] = item;
	}
	data[count] = '\0';
	// Saving memory
	char **result = malloc(count * sizeof(char*));
	for (i=0; i<=count; i++)
		result[i] = data[i];
	// Deallocate memory
	free(segment);
	free(data);
	return result;
}

// Join string with delimiter
char *str_join(char *target[], const char *delim)
{
	int num = lenght_pointer_pointer_char(target) - 1;
	int len = 0, wlen = 0;
	char *tmp = calloc(MAX_SIZE, sizeof(char));
	for (int i=0; i<num; i++) {
		// Copy memory segment
		wlen = strlen(target[i]);
		memcpy(tmp + len, target[i], wlen);
		len += wlen;
		// Copy memory segment
		wlen = strlen(delim);
		memcpy(tmp + len, delim, wlen);
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
char *str_trim(char *target)
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