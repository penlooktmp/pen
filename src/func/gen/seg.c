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

#define P_SEG(TYPE); \
TYPE *segment_pointer_##TYPE(TYPE *target, int from, int to) {\
	int len = to - from + 1;\
	TYPE *pointer = calloc(len, sizeof(TYPE));\
	memcpy(pointer, &target[from], len);\
	return pointer;\
}

#define P_C_SEG(TYPE); \
TYPE *segment_pointer_constant_##TYPE(const TYPE *target, int from, int to) {\
	int len = to - from + 1;\
	TYPE *pointer = calloc(len, sizeof(TYPE));\
	memcpy(pointer, &target[from], len);\
	return pointer;\
}

#define P_P_SEG(TYPE); \
TYPE **segment_pointer_pointer_##TYPE(TYPE **target, int from, int to) {\
	int len = to - from + 1;\
	TYPE **pointer = calloc(len, sizeof(TYPE*));\
	memcpy(pointer, &target[from], len);\
	return pointer;\
}

P_SEG(char);
P_C_SEG(char);
P_P_SEG(char);
P_SEG(int);
P_SEG(long);
P_SEG(double);
