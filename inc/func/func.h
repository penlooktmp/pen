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

#ifndef FUNC_FUNC_H
#define FUNC_FUNC_H

#define P_LEN_H(TYPE); \
		int len_pointer_##TYPE(TYPE*target);
#define P_P_LEN_H(TYPE); \
		int len_pointer_pointer_##TYPE(TYPE**target);
#define P_SUB_H(TYPE); \
		TYPE *sub_pointer_##TYPE(TYPE *target, int from, int to);
#define P_P_SUB_H(TYPE); \
		TYPE **sub_pointer_pointer_##TYPE(TYPE **target, int from, int to);

// len_pointer_char
P_LEN_H(char);
P_P_LEN_H(char);
P_LEN_H(short);
P_LEN_H(int);
P_LEN_H(long);
P_LEN_H(double);

// sub_pointer_char
P_SUB_H(char);
P_P_SUB_H(char);
P_SUB_H(short);
P_SUB_H(int);
P_SUB_H(long);
P_SUB_H(double);

#endif