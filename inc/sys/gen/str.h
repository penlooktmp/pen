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

// STR (String - char pointer )
// str(target)
// Convert char pointer and number to string (char pointer)

#ifndef SYS_GEN_STR_H_
#define SYS_GEN_STR_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <func/gen/str.h>
#ifdef __cplusplus
}
#endif

#define P_STR(TYPE); \
inline char* str(TYPE *t)\
{\
	return string_pointer_##TYPE(t);\
}

#define P_C_STR(TYPE); \
inline char* str(const TYPE *t)\
{\
	return string_pointer_constant_##TYPE(t);\
}

#define NUM_STR(TYPE); \
inline char* str(TYPE t)\
{\
	return string_number_##TYPE(t);\
}

namespace sys
{
	namespace func
	{
		P_STR(char);
		P_C_STR(char);
		NUM_STR(short);
		NUM_STR(int);
		NUM_STR(long);
		NUM_STR(double);
		NUM_STR(float);
		
		inline char *str(string target)
		{
			return (char*) target.c_str();
		}
	}	
}
#endif