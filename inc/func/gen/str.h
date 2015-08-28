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

#ifndef FUNC_GEN_STR_H_
#define FUNC_GEN_STR_H_

#include "len.h"

#define P_STR_H(TYPE); \
		char *string_pointer_##TYPE(TYPE *target);
#define P_C_STR_H(TYPE); \
		char *string_pointer_constant_##TYPE(const TYPE *target);
#define NUM_STR_H(TYPE); \
		char *string_number_##TYPE(TYPE target);

// string_pointer_char
P_STR_H(char);
// string_pointer_constant_char
P_C_STR_H(char);
// string_number_short
NUM_STR_H(short);
// string_number_int
NUM_STR_H(int);
// string_number_long
NUM_STR_H(long);
// string_number_double
NUM_STR_H(double);
// string_number_float
NUM_STR_H(float);

#endif