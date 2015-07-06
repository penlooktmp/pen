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

#ifndef FUNC_GEN_SEG_H_
#define FUNC_GEN_SEG_H_

#define P_SEG_H(TYPE); \
		extern TYPE *segment_pointer_##TYPE(TYPE *target, int from, int to);
#define P_C_SEG_H(TYPE); \
		extern TYPE *segment_pointer_constant_##TYPE(const TYPE *target, int from, int to);
#define P_P_SEG_H(TYPE); \
		extern TYPE **segment_pointer_pointer_##TYPE(TYPE **target, int from, int to);

// segment_pointer_char
P_SEG_H(char);
// segment_pointer_constant_char
P_C_SEG_H(char);
// segment_pointer_pointer_char
P_P_SEG_H(char);
// segment_pointer_short
P_SEG_H(short);
// segment_pointer_int
P_SEG_H(int);
// segment_pointer_long
P_SEG_H(long);
// segment_pointer_double
P_SEG_H(double);
// segment_pointer_float
P_SEG_H(float);

#endif