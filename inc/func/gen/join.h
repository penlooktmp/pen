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

#ifndef FUNC_GEN_JOIN_H
#define FUNC_GEN_JOIN_H

#define P_JOIN_H(TYPE); \
		char *join_pointer_##TYPE(TYPE *target);
#define P_JOIN_DELIM_H(TYPE); \
		char *join_delim_pointer_##TYPE(TYPE *target, const char *delim);
#define P_P_JOIN_H(TYPE); \
		char *join_pointer_pointer_##TYPE(TYPE **target);
#define P_P_JOIN_DELIM_H(TYPE); \
		char *join_delim_pointer_pointer_##TYPE(TYPE **target, const char *delim);

// join_pointer_char
P_P_JOIN_H(char);
// join_delim_pointer_char
P_P_JOIN_DELIM_H(char);
// join_pointer_short
P_JOIN_H(short);
// join_delim_pointer_short
P_JOIN_DELIM_H(short);
// join_pointer_int
P_JOIN_H(int);
// join_delim_pointer_int
P_JOIN_DELIM_H(int);
// join_pointer_long
P_JOIN_H(long);
// join_delim_pointer_long
P_JOIN_DELIM_H(long);
// join_pointer_double
P_JOIN_H(double);
// join_delim_pointer_double
P_JOIN_DELIM_H(double);
// join_pointer_float
P_JOIN_H(float);
// join_delim_pointer_float
P_JOIN_DELIM_H(float);

#endif
