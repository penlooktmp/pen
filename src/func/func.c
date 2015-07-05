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
#include <func/func.h>

#define P_LEN(TYPE); \
		int len_pointer_##TYPE(TYPE *target) {\
			register TYPE*pointer;\
			for (pointer = target; *pointer; ++pointer);\
			return pointer - target;\
		}

#define P_P_LEN(TYPE); \
		int len_pointer_pointer_##TYPE(TYPE **target) {\
			register TYPE**pointer;\
			for (pointer = target; *pointer; ++pointer);\
			return pointer - target;\
		}

#define P_SUB(TYPE); \
		TYPE *sub_pointer_##TYPE(TYPE *target, int from, int to) {\
			int len = to - from + 1;\
			TYPE *pointer = calloc(len, sizeof(TYPE));\
			memcpy(pointer, &target[from], len);\
			return pointer;\
		}

#define P_P_SUB(TYPE); \
		TYPE **sub_pointer_pointer_##TYPE(TYPE **target, int from, int to) {\
			int len = to - from + 1;\
			TYPE **pointer = calloc(len, sizeof(TYPE*));\
			memcpy(pointer, &target[from], len);\
			return pointer;\
		}

P_LEN(char);
P_P_LEN(char);
P_LEN(int);
P_LEN(long);
P_LEN(double);

P_SUB(char);
P_P_SUB(char);
P_SUB(int);
P_SUB(long);
P_SUB(double);