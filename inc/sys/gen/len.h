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

// LEN (Length)
// len(target)
// Use to retrive length of data type

#ifndef SYS_GEN_LEN_H_
#define SYS_GEN_LEN_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <func/gen/len.h>
#ifdef __cplusplus
}
#endif

#define P_LEN(TYPE);\
inline int len(TYPE *t)\
{\
	return lenght_pointer_##TYPE(t);\
}

#define P_C_LEN(TYPE); \
inline int len(const TYPE *t)\
{\
	return lenght_pointer_constant_##TYPE(t);\
}

#define P_P_LEN(TYPE); \
inline int len(TYPE **t)\
{\
	return lenght_pointer_pointer_##TYPE(t);\
}

#define NUM_LEN(TYPE); \
inline int len(TYPE t) \
{\
	return lenght_number_##TYPE(t);\
}

namespace sys
{
	namespace func
	{
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

		// LEN(string)
		inline int len(string target)
		{
			return target.length();
		}
	}
}

#endif