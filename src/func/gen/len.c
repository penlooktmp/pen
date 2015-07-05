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
#include <limits.h>

// Length of pointer
#define P_LEN(TYPE); \
int lenght_pointer_##TYPE(TYPE *target) {\
	register TYPE*pointer;\
	for (pointer = target; *pointer; ++pointer);\
	return pointer - target;\
}

// Length of constant pointer
#define P_C_LEN(TYPE); \
int lenght_pointer_constant_##TYPE(const TYPE *target_const) {\
	TYPE* target = (TYPE*) target_const;\
	register TYPE*pointer;\
	for (pointer = target; *pointer; ++pointer);\
	return pointer - target;\
}

// Lenght of pointer pointer
#define P_P_LEN(TYPE); \
int lenght_pointer_pointer_##TYPE(TYPE **target) {\
	register TYPE**pointer;\
	for (pointer = target; *pointer; ++pointer);\
	return pointer - target;\
}

// Length of number
#define PO10_LIMIT (INT_MAX/10)
#define NUM_LEN(TYPE); \
int lenght_number_##TYPE(TYPE target) {\
	register short len = 1;\
	register TYPE po10 = 10;\
	if (target < 0) target = -target;\
	while (target >= po10) {\
		len++;\
		if (po10 > PO10_LIMIT) break;\
		po10*=10;\
	}\
	return len;\
}

P_LEN(char);
P_C_LEN(char);
P_P_LEN(char);
NUM_LEN(short);
P_LEN(short);
NUM_LEN(int);
P_LEN(int);
NUM_LEN(long);
P_LEN(long);
NUM_LEN(double);
P_LEN(double);
NUM_LEN(float);
P_LEN(float);