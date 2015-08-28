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

// JOIN (Join)
// join(target_array)
// join(target_array, delimiter)
// Use to join item in array with delimiter or not

#ifndef SYS_GEN_JOIN_H_
#define SYS_GEN_JOIN_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <func/gen/join.h>
#ifdef __cplusplus
}
#endif

#define P_JOIN(TYPE);\
inline char *join(TYPE *t)\
{\
	return join_pointer_##TYPE(t);\
}

#define P_JOIN_DELIM(TYPE);\
inline char *join(TYPE *t, const char *delim)\
{\
	return join_delim_pointer_##TYPE(t, delim);\
}

#define P_P_JOIN(TYPE); \
inline char *join(TYPE **t)\
{\
	return join_pointer_pointer_##TYPE(t);\
}

#define P_P_JOIN_DELIM(TYPE); \
inline char *join(TYPE **t, const char *delim)\
{\
	return join_delim_pointer_pointer_##TYPE(t, delim);\
}

namespace sys
{
	namespace func
	{
		P_P_JOIN(char);
		P_P_JOIN_DELIM(char);
		P_JOIN(short);
		P_JOIN_DELIM(short);
		P_JOIN(int);
		P_JOIN_DELIM(int);
		P_JOIN(long);
		P_JOIN_DELIM(long);
		P_JOIN(double);
		P_JOIN_DELIM(double);
		P_JOIN(float);
		P_JOIN_DELIM(float);
	}
}

#endif