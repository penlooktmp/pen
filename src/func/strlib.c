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
#include<libintl.h>
#include<locale.h>
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
char **str_split(char *target, const char *delim_)
{
	char* delim = (char*) delim_;
	int len_target = lenght_pointer_char(target);
	int len_delim = lenght_pointer_char(delim);
	int distance = len_target - len_delim + 1;
	int len_item = 0;
	char *segment = calloc(len_delim, sizeof(char));
	char **data = malloc(MAX_SIZE * sizeof(char*));
	register int count = 0, from = 0, to = 0;
	// Compare delimiter per target segment
	while (to <= distance) {
		memcpy(segment, &target[to], len_delim);
		//printf("COMPARE %s with %s\n", segment, delim);
		if (strcmp(segment, delim) == 0) {
			//printf("IGNORE ---\n");
			if (to - from > 0) {
				len_item = to - from;
				char *item = calloc(len_item, sizeof(char));
				memcpy(item, &target[from], len_item);
				// Append element to result
				data[count++] = item;
				//printf("PUSH %s \n", item);
				from = to + len_delim;
			} else from += len_delim;
			to = from;
			continue;
		}
		++to;
	}
	if (to - from > 0) {
		len_item = to - from;
		char *item = calloc(len_item, sizeof(char));
		memcpy(item, &target[from], len_item);
		// Append element to result
		data[count++] = item;
		//printf("PUSH %s\n\n", item);
	}
	data[count] = '\0';
	// Saving memory
	char **result = malloc(count * sizeof(char*));
	register int i;
	for (i=0; i<count; i++)
		result[i] = data[i];
	result[count] = '\0';
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

// Translation
char *str_trans(char *target, const char *locale)
{
	if (strcmp(locale,"en_US") == 0) return (char*) "Hello";
	if (strcmp(locale,"vi_VN") == 0) return (char*) "Xin chào";
	if (strcmp(locale,"ja_JP") == 0) return (char*) "はじめまして";
	if (strcmp(locale,"ko_KR") == 0) return (char*) "안녕하세요";
	if (strcmp(locale,"zh_CN") == 0) return (char*) "您好";
	return target;
}