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

#ifndef FUNC_GEN_ADD_H_
#define FUNC_GEN_ADD_H_

/*
#define P_LEN_H(TYPE); \
		TYPE *add_pointer_##TYPE(TYPE *target);
#define P_C_LEN_H(TYPE); \
		TYPE **add_pointer_constant_##TYPE(const TYPE *target);
#define P_P_LEN_H(TYPE); \
		TYPE **add_pointer_pointer_##TYPE(TYPE **target);
#define NUM_ADD_H(TYPE); \
		TYPE _number_##TYPE(TYPE target);
*/

char **add_pointer_pointer_char(char **target, char *append);

// add_pointer_char
// P_ADD_H(char);

/*
// add_pointer_constant_char
P_C_ADD_H(char);
// add_pointer_pointer_char
P_P_ADD_H(char);
// add_number_short
NUM_ADD_H(short);
// add_pointer_short
P_ADD_H(short);
// add_number_int
NUM_ADD_H(int);
// add_pointer_int
P_ADD_H(int);
// add_number_long
NUM_ADD_H(long);
// add_pointer_long
P_ADD_H(long);
// add_number_double
NUM_ADD_H(double);
// add_pointer_double
P_ADD_H(double);
// add_number_float
NUM_ADD_H(float);
// add_pointer_float
P_ADD_H(float);
*/
#endif


