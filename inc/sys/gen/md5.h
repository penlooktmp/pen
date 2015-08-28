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

#ifndef SYS_GEN_MD5_H_
#define SYS_GEN_MD5_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <func/crypto/md5.h>
#ifdef __cplusplus
}
#endif

#define P_MD5(TYPE); \
inline char *md5(TYPE* t) {\
	return md5_pointer_##TYPE(t);\
}

#define P_C_MD5(TYPE); \
inline char *md5(const TYPE* t) {\
	return md5_pointer_constant_##TYPE(t);\
}

namespace sys
{
	namespace func
	{
		P_MD5(char);
		P_C_MD5(char);
		
		inline string md5(string target)
		{
			return string(md5_pointer_constant_char(target.c_str()));
		}
	}
}

#endif